/*
    Copyright (C) 2015 Panagiotis Roubatsis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "FMODMusic.h"
#include <climits>

FMODMusic::FMODMusic(std::string fileName)
{
	_succesfulInitialization = true;
	_isPlaying = false;

	if(checkError(FMOD::System_Create(&_system))) return;
	if(checkError(_system->init(1, FMOD_INIT_NORMAL, 0))) return;
	if(checkError(_system->createStream(fileName.c_str(), FMOD_LOOP_NORMAL, 0, &_sound))) return;
}

FMODMusic::~FMODMusic()
{
	_sound->release();
	_system->close();
	_system->release();
}

bool FMODMusic::checkError(FMOD_RESULT result)
{
	bool error = result != FMOD_OK;
	if(error) _succesfulInitialization = false;
	return error;
}

void FMODMusic::play()
{
	if(!_succesfulInitialization) return;
	if(checkError(_system->playSound(FMOD_CHANNEL_FREE, _sound, false, &_channel))) return;
	
	_isPlaying = true;
}

void FMODMusic::update()
{
	if(!_isPlaying) return;
	_system->update();
}

std::vector<float> FMODMusic::getSpectrum()
{
	const int SIZE = 1024;
	std::vector<float> left(SIZE), right(SIZE), spectrum;

	_channel->getSpectrum(&left[0], SIZE, 0, FMOD_DSP_FFT_WINDOW_BLACKMANHARRIS);
	_channel->getSpectrum(&right[0], SIZE, 1, FMOD_DSP_FFT_WINDOW_BLACKMANHARRIS);

	//Average of the left and right channels
	for(int i = 0; i < SIZE; i++)
	{
		spectrum.push_back((left[i] + right[i]) / 2.0f);
	}

	return spectrum;
}

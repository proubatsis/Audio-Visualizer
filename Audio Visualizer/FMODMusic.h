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

/*
	Created by Panagiotis Roubatsis

	Description: An implementation of the Music abstract class.
	FMODMusic plays music and analyzes it using the FMOD library (http://www.fmod.org/).
*/

#ifndef FMOD_MUSIC_H
#define FMOD_MUSIC_H

#include "Music.h"
#include <string>
#include <fmod.hpp>

class FMODMusic : public Music
{
public:
	FMODMusic(std::string fileName);
	~FMODMusic();

	void play();
	void update();

	std::vector<float> getSpectrum();

private:
	FMOD::System* _system;
	FMOD::Sound* _sound;
	FMOD::Channel* _channel;

	bool _succesfulInitialization, _isPlaying;

	//Disables the class' functionality if
	//an error occurs during initialization.
	bool checkError(FMOD_RESULT result);
};

#endif
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

std::vector<float> FMODMusic::getRawSpectrum()
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

std::vector<float> FMODMusic::getSpectrum()
{
	std::vector<float> spectrum = getRawSpectrum();

	float maxFreq = INT_MIN;	//Used to normalize the spectrum
	//Average of the left and right channels
	for(int i = 0; i < spectrum.size(); i++)
		if(spectrum[i] > maxFreq) maxFreq = spectrum[i];

	//Normalize the spectrum
	for(int i = 0; i < spectrum.size(); i++) spectrum[i] /= maxFreq;
	return spectrum;
}
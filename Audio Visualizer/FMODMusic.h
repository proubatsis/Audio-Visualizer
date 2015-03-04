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

	std::vector<float> getRawSpectrum();
	std::vector<float> getSpectrum();

private:
	FMOD::System* _system;
	FMOD::Sound* _sound;
	FMOD::Channel* _channel;

	bool _succesfulInitialization, _isPlaying;

	bool checkError(FMOD_RESULT result);
};

#endif
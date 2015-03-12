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
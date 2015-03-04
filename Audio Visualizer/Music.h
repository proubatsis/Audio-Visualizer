#ifndef MUSIC_H
#define MUSIC_H

#include <vector>

class Music
{
public:
	virtual void play() = 0;
	virtual void update() = 0;

	virtual std::vector<float> getRawSpectrum() = 0;
	virtual std::vector<float> getSpectrum() = 0;
};

#endif
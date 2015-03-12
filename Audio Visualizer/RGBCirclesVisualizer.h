/*
	Created by Panagiotis Roubatsis

	Description: Three overlapping circle (Coloured red, green and blue). Each circle
	reacts based upon a certain set of frequencies.
*/

#ifndef RGB_CIRCLES_VISUALIZER
#define RGB_CIRCLES_VISUALIZER

#include "Visualizer.h"

class RGBCirclesVisualizer : public Visualizer
{
public:
	RGBCirclesVisualizer(sf::RenderWindow* window, Music* music);
	void render();

private:
	sf::CircleShape _circles[3];
	const float RADIUS;
	float _aHist, _bHist, _cHist;					//Used for time smoothing

	void adjustCircles(float a, float b, float c);	//Adjust the radius for each circle

	float sum(float* vals, int size);
	float smooth(float n, float& hist);
};

#endif
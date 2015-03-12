/*
	Created by Panagiotis Roubatsis

	Description: Based off of the CircleBarVisualizer. Instead of the bars
	extending outwards they are pointing inwards towards the center of the circle.
	They also have colour assigned to them, the colour transitions around the circle
	based on the elapsed time and how loud the music is at a given moment.
*/

#ifndef INVERTED_CIRCLE_BAR_VISUALIZER
#define INVERTED_CIRCLE_BAR_VISUALIZER

#include "CircleBarVisualizer.h"

class InvertedCircleBarVisualizer : public CircleBarVisualizer
{
public:
	InvertedCircleBarVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:
	float _volume;
	float _colorAngleOffset;	//The offset angle to adjust the position of the colours on the wheel
	sf::Clock _clock;

	virtual void setBar(int i, std::vector<float>& spectrum);
	virtual sf::Color getColor(float angle);

	float interpolate(float a, float b, float t);
};

#endif
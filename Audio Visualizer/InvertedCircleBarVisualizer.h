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
	float _colorAngleOffset;
	sf::Clock _clock;

	virtual void setBar(int i, std::vector<float>& spectrum);
	virtual sf::Color getColor(float angle);

	float interpolate(float a, float b, float t);
};

#endif
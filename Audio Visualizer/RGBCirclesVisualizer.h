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

	void adjustCircles(float a, float b, float c);	//The radius for each circle
};

#endif
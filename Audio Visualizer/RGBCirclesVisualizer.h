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
	float _aHist, _bHist, _cHist;

	void adjustCircles(float a, float b, float c);	//The radius for each circle
	float sum(float* vals, int size);
	float smooth(float n, float& hist);
};

#endif
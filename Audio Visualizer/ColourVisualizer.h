#ifndef COLOUR_VISUALIZER
#define COLOUR_VISAULIZER

#include "Visualizer.h"

class ColourVisualizer : public Visualizer
{
public:
	ColourVisualizer(sf::RenderWindow* window, Music* music);
	void render();

private:
	sf::RectangleShape _rect;
};

#endif
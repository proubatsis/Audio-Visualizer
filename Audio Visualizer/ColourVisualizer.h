/*
	Created by Panagiotis Roubatsis

	Description: Horrible visualizer that will be removed later.
*/

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
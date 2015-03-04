#ifndef BAR_VISUALIZER_H
#define BAR_VISUALIZER_H

#include <vector>
#include "Visualizer.h"

class BarVisualizer : public Visualizer
{
public:
	BarVisualizer(sf::RenderWindow* window, Music* music);
	void render();

private:
	std::vector<sf::RectangleShape> _bars;
	int _barWidth;
};

#endif
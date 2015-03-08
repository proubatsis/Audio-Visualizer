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
	std::vector<float> _previousSpectrum;

	void smooth(std::vector<float>& spectrum);

	int _barWidth;
};

#endif
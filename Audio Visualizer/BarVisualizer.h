#ifndef BAR_VISUALIZER_H
#define BAR_VISUALIZER_H

#include <vector>
#include "Visualizer.h"

class BarVisualizer : public Visualizer
{
public:
	BarVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

private:
	std::vector<float> _previousSpectrum;

protected:
	int _barWidth;
	std::vector<sf::RectangleShape> _bars;
	void smooth(std::vector<float>& spectrum);
};

#endif
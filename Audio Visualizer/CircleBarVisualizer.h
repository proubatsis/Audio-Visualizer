#ifndef CIRCLE_BAR_VISUALIZER_H
#define CIRCLE_BAR_VISUALIZER_H

#include "BarVisualizer.h"

class CircleBarVisualizer : public BarVisualizer
{
public:
	CircleBarVisualizer(sf::RenderWindow* window, Music* music);
	
private:
	float _innerRadius, _theta, _thetaR;

protected:
	void initializeBars();
	void setBar(int i, std::vector<float>& spectrum);
};

#endif
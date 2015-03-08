#ifndef CIRCLE_DOT_VISUALIZER
#define CIRCLE_DOT_VISUALIZER

#include "CircleBarVisualizer.h"

class CircleDotVisualizer : public CircleBarVisualizer
{
public:
	CircleDotVisualizer(sf::RenderWindow* window, Music* music);

protected:
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
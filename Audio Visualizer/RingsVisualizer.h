#ifndef RINGS_VISUALIZER_H
#define RINGS_VISUALIZER_H

#include "Visualizer.h"

class RingsVisualizer : public Visualizer
{
public:
	RingsVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:
	const sf::Vector2f CENTER;
	const int INNER_SAMPLES, OUTER_SAMPLES, INNER_SLICE_SIZE, OUTER_SLICE_SIZE;

	float _innerRadius, _outerRadius, _innerAmplitude, _outerAmplitude;
	std::vector<sf::Vertex> _innerLines, _outerLines;

	virtual void setInner(int i, std::vector<float>& spectrum);
	virtual void setOuter(int i, std::vector<float>& spectrum);
};

#endif
#ifndef PIE_VISUALIZER_H
#define PIE_VISUALIZER_H

#include "Visualizer.h"

class PieVisualizer : public Visualizer
{
public:
	PieVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:
	struct Segment
	{
		sf::ConvexShape triangle;
		sf::Vector2f moveDirection;
	};

	const int SEGMENTS;
	const float BASE_RADIUS;

	sf::CircleShape _beatCircle, _beatCircle2;
	std::vector<Segment> _segments;
	std::vector<float> _previousSums;

	float sum(float* values, int size);
	void smooth(std::vector<float>& sums);

	float interpolate(float a, float b, float t);
	sf::Color getColor(int i, float sum);
};

#endif
/*
	Created by Panagiotis Roubatsis

	Description: An effect where there is a colourful circle that
	is cut into "pie" slices. The slices move away from the center depending
	on the amplitude of certain frequencies. The colours get more intense as
	the amplitude increases. There are two circles on either side of the "pie".
	These are used to show the low frequencies, usually beats.
*/

#ifndef PIE_VISUALIZER_H
#define PIE_VISUALIZER_H

#include "Visualizer.h"

class PieVisualizer : public Visualizer
{
public:
	PieVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:

	//A slice of "pie"
	struct Segment
	{
		sf::ConvexShape triangle;
		sf::Vector2f moveDirection;
	};

	const int SEGMENTS;
	const float BASE_RADIUS;

	sf::CircleShape _beatCircle, _beatCircle2;
	std::vector<Segment> _segments;

	std::vector<float> _previousSums;	//Used for time smoothing

	float sum(float* values, int size);
	void smooth(std::vector<float>& sums);

	float interpolate(float a, float b, float t);
	sf::Color getColor(int i, float sum);
};

#endif
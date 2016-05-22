/*
    Copyright (C) 2015 Panagiotis Roubatsis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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

///
/// \brief A visualizer made up of several "pie" slices.
/// An effect where there is a colourful circle that is cut into "pie" slices. The slices move away from the center depending
/// on the amplitude of certain frequencies. The colours get more intense as
/// the amplitude increases. There are two circles on either side of the "pie".
/// These are used to show the low frequencies, usually beats.
///
class PieVisualizer : public Visualizer
{
public:
	PieVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:

	///
	/// \brief A "slice" of the pie.
	///
	struct Segment
	{
		sf::ConvexShape triangle;
		sf::Vector2f moveDirection;
	};

	const int SEGMENTS;			///< The amount of slices
	const float BASE_RADIUS;	///< The radius of the pie assuming no music

	sf::CircleShape _beatCircle, _beatCircle2;
	std::vector<Segment> _segments;

	std::vector<float> _previousSums;	///< Used for time smoothing

	float sum(float* values, int size);
	void smooth(std::vector<float>& sums);

	float interpolate(float a, float b, float t);
	sf::Color getColor(int i, float sum);
};

#endif
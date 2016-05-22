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

	Description: Based off of the CircleBarVisualizer. Instead of the bars
	extending outwards they are pointing inwards towards the center of the circle.
	They also have colour assigned to them, the colour transitions around the circle
	based on the elapsed time and how loud the music is at a given moment.
*/

#ifndef INVERTED_CIRCLE_BAR_VISUALIZER
#define INVERTED_CIRCLE_BAR_VISUALIZER

#include "CircleBarVisualizer.h"

///
/// \brief Similar to CircleBarVisualizer except that the bars extend inwards.
/// Instead of the bars extending outwards they are pointing inwards towards the center of the circle.
///	They also have colour assigned to them, the colour transitions around the circle
/// based on the elapsed time and how loud the music is at a given moment.
///
class InvertedCircleBarVisualizer : public CircleBarVisualizer
{
public:
	InvertedCircleBarVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

protected:
	float _volume;
	float _colorAngleOffset;	///< The offset angle to adjust the position of the colours on the wheel
	sf::Clock _clock;

	virtual void setBar(int i, std::vector<float>& spectrum);
	virtual sf::Color getColor(float angle);

	float interpolate(float a, float b, float t);
};

#endif
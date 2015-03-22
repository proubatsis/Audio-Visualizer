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

	Description: A visualizer that uses an inner ring to show
	the higher frequencies and the outer ring to show the lower frequencies.
*/

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
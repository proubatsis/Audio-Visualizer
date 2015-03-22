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

	Description: Based off of the CircleBarVisualizer. Instead of
	bars it uses small dots.
*/

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
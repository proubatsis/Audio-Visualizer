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

	Description: A variant of the BarVisualizer where the bars are
	arranged in a circle and the bars extend outwards from the circle.
*/

#ifndef CIRCLE_BAR_VISUALIZER_H
#define CIRCLE_BAR_VISUALIZER_H

#include "BarVisualizer.h"

class CircleBarVisualizer : public BarVisualizer
{
public:
	CircleBarVisualizer(sf::RenderWindow* window, Music* music);

protected:
	float _innerRadius;			//The blank radius inside the circle
	float _theta;				//Angle for each rotation in degrees
	float _thetaR;				//_theta in radians
	float _barNormalAngle;		//The angle rotated for the bar to be a normal to the circle
	float _barCountMultiplier;	//How many more bars do we want then the minimum?

	virtual void initializeBars();
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
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

#include "CircleDotVisualizer.h"

CircleDotVisualizer::CircleDotVisualizer(sf::RenderWindow* window, Music* music)
	: CircleBarVisualizer(window, music)
{
	_barWidth = 3;
}

void CircleDotVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	int h = (int)((spectrum[i] / 0.125f) * vWindow->getSize().y * 0.5f);

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, _barWidth));
	_bars[i].rotate(angle);
	_bars[i].setPosition((_innerRadius+h) * cos(angleR) + vWindow->getSize().x / 2, (_innerRadius+h) * sin(angleR) + vWindow->getSize().y / 2);
}
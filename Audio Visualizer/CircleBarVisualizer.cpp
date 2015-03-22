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

#include "CircleBarVisualizer.h"
#include <cmath>

#define TO_DEG (180 / 3.14159265359f)

CircleBarVisualizer::CircleBarVisualizer(sf::RenderWindow* window, Music* music)
	: BarVisualizer(window, music)
{
	_barWidth = 3;
	_innerRadius = 50;

	_barCountMultiplier = 2;
	_barNormalAngle = -90;
}

void CircleBarVisualizer::initializeBars()
{
	//Formula derived using the cosine law
	//                     +
	//                 *   |
	//         r    *      |
	//           *         |
	//        *            |
	//     *               |
	//  *     theta        | b
	//     *               |
	//        *            |
	//           *         |
	//        r     *      |
	//                 *   |
	//                     +
	
	// cos(theta) = (1 - b ^ 2) / (2 * r ^ 2)
	_thetaR = acosf(1-((_barWidth * _barWidth) / (2 * _innerRadius * _innerRadius)));
	_theta = _thetaR * TO_DEG;
	
	int barCount = (int)(360 / _theta);

	for(int i = 0; i < barCount * _barCountMultiplier; i++)
		_bars.push_back(sf::RectangleShape(sf::Vector2f(0, 0)));
}

void CircleBarVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	float h = (spectrum[i] / 0.125f) * vWindow->getSize().y * 0.5f + 1;

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, h));
	_bars[i].rotate(angle + _barNormalAngle);
	_bars[i].setPosition(_innerRadius * cos(angleR) + vWindow->getSize().x / 2, _innerRadius * sin(angleR) + vWindow->getSize().y / 2);
}

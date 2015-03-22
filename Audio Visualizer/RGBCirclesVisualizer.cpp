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

#include "RGBCirclesVisualizer.h"
#include <cmath>
#define SIN_COS_45 0.70710678118f

RGBCirclesVisualizer::RGBCirclesVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music), RADIUS(128.0f)
{
	//Configure circles
	adjustCircles(RADIUS, RADIUS, RADIUS);

	_circles[0].setFillColor(sf::Color(255, 0, 0, 128));
	_circles[1].setFillColor(sf::Color(0, 0, 255, 128));
	_circles[2].setFillColor(sf::Color(0, 255, 0, 128));

	_aHist = _bHist = _cHist = 0;
}

float RGBCirclesVisualizer::sum(float* vals,  int size)
{
	float total = 0;
	for(int i = 0; i < size; i++) total += vals[i];
	return total;
}

float RGBCirclesVisualizer::smooth(float n, float& hist)
{
	float a = hist;
	hist = n;
	return 0.5f * (n - a) + a;
}

void RGBCirclesVisualizer::render()
{
	std::vector<float> spectrum = vMusic->getSpectrum();

	float a = sum(&spectrum[0], 16);
	float b = sum(&spectrum[17], 32);
	float c = sum(&spectrum[49], 32);

	a = smooth(a, _aHist);
	b = smooth(b, _bHist);
	c = smooth(c, _cHist);

	adjustCircles(RADIUS * (a + 0.25f), RADIUS * (b + 0.25f), RADIUS * (c + 0.25f));

	for(int i = 0; i < 3; i++) vWindow->draw(_circles[i]);
}

void RGBCirclesVisualizer::adjustCircles(float a, float b, float c)
{
	sf::Vector2f midScreen = (sf::Vector2f)vWindow->getSize();
	midScreen.x /= 2;
	midScreen.y /= 2;

	_circles[0].setPosition(midScreen + sf::Vector2f(-a * SIN_COS_45, -a * SIN_COS_45) + sf::Vector2f(-a / 2, -a / 2));
	_circles[1].setPosition(midScreen + sf::Vector2f(b * SIN_COS_45, -b * SIN_COS_45) + sf::Vector2f(-b / 2, -b / 2));
	_circles[2].setPosition(midScreen + sf::Vector2f(0, c) + sf::Vector2f(-c / 2, -c / 2));

	_circles[0].setRadius(a);
	_circles[1].setRadius(b);
	_circles[2].setRadius(c);
}
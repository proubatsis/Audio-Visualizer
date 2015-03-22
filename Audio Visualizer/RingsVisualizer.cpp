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

#include "RingsVisualizer.h"
#include <cmath>
#include <numeric>
#include <iostream>

#define PI 3.14159265359f

RingsVisualizer::RingsVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music), CENTER(window->getSize().x / 2.0f, window->getSize().y / 2.0f),
	INNER_SAMPLES(32), OUTER_SAMPLES(16), INNER_SLICE_SIZE(4), OUTER_SLICE_SIZE(8)
{
	//Radius of the inner and outer rings
	_innerRadius	= 75;
	_outerRadius	= 200;

	//Amplitude of the ring's vibration
	_innerAmplitude	= 1000;
	_outerAmplitude	= 250;

	//The +1 is to close the ring
	_innerLines.resize(INNER_SAMPLES + 1);
	_outerLines.resize(OUTER_SAMPLES + 1);
}

void RingsVisualizer::setInner(int i, std::vector<float>& spectrum)
{
	const float ANGLE = (float)((2 * PI) / INNER_SAMPLES) * i;

	std::vector<float>::iterator begin = spectrum.begin() + i * INNER_SLICE_SIZE + OUTER_SAMPLES * OUTER_SLICE_SIZE;
	float d = std::accumulate(begin, begin + INNER_SLICE_SIZE, 0.0f) * _innerAmplitude;
	d -= d / 2;

	//Rotates the up vector based on the given angle. Derived from [0, -1] * RotationMatrix. (Taken From: PieVisualizer.cpp)
	sf::Vector2f direction(sinf(ANGLE), -cosf(ANGLE));
	direction.x *= _innerRadius + d;
	direction.y *= _innerRadius + d;

	sf::Vector2f position = CENTER + direction;
	_innerLines[i] = sf::Vertex(position);

	//Close the ring
	if(i == 0) _innerLines[_innerLines.size() - 1] = _innerLines[i];
}

void RingsVisualizer::setOuter(int i, std::vector<float>& spectrum)
{
	const float ANGLE = (float)((2 * PI) / OUTER_SAMPLES) * i;

	std::vector<float>::iterator begin = spectrum.begin() + i * OUTER_SLICE_SIZE;
	float d = std::accumulate(begin, begin + OUTER_SLICE_SIZE, 0.0f) * _outerAmplitude;
	d -= d / 2;

	//Rotates the up vector based on the given angle. Derived from [0, -1] * RotationMatrix. (Taken From: PieVisualizer.cpp)
	sf::Vector2f direction(sinf(ANGLE), -cosf(ANGLE));
	direction.x *= _outerRadius + d;
	direction.y *= _outerRadius + d;

	sf::Vector2f position = CENTER + direction;
	_outerLines[i] = sf::Vertex(position);

	//Close the ring
	if(i == 0) _outerLines[_outerLines.size() - 1] = _outerLines[i];
}

void RingsVisualizer::render()
{
	std::vector<float> spectrum = vMusic->getSpectrum();

	//Adjust each ring
	for(size_t i = 0; i < _innerLines.size() - 1; i++)
		setInner((int)i, spectrum);

	for(size_t i = 0; i < _outerLines.size() - 1; i++)
		setOuter((int)i, spectrum);
	
	//Draw the rings
	vWindow->draw(&_innerLines[0], _innerLines.size(), sf::LinesStrip);
	vWindow->draw(&_outerLines[0], _outerLines.size(), sf::LinesStrip);
}

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

	Description: A standard bar graph visualization of Amplitude vs Frequency.
*/

#ifndef BAR_VISUALIZER_H
#define BAR_VISUALIZER_H

#include <vector>
#include "Visualizer.h"

class BarVisualizer : public Visualizer
{
public:
	BarVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

private:
	std::vector<float> _previousSpectrum;	//Used for time smoothing.
	bool _areBarsInitialized;				//Has initializeBars() been called yet?

protected:
	float _barWidth;
	std::vector<sf::RectangleShape> _bars;	//The bars that will be rendered to the screen

	//Smooth the current spectrum based on the previous one using interpolation.
	void smooth(std::vector<float>& spectrum);

	virtual void initializeBars();

	//Sets the bar of given index 'i' to have specific properties
	//such as position, size and rotation based on the spectrum values.
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
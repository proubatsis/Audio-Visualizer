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

///
/// \brief A standard bar graph visualization of Amplitude vs Frequency.
///
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
	std::vector<sf::RectangleShape> _bars;	///< The bars that will be rendered to the screen

	///
	/// \brief Smooth the current spectrum based on the previous one using interpolation.
	/// \param spectrum Current spectrum.
	///
	void smooth(std::vector<float>& spectrum);

	///
	/// \brief Initialize _bars with inital values.
	///
	virtual void initializeBars();

	///
	/// \brief Set the bar at the given index to have specific properties.
	/// Set the bar at index i to take on certain properties such as position, size,
	/// and rotation based on the spectrum values.
	///
	/// \param i Index of the bar to adjust
	/// \param spectrum The current spectrum.
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
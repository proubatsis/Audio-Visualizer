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

	Description: Three overlapping circle (Coloured red, green and blue). Each circle
	reacts based upon a certain set of frequencies.
*/

#ifndef RGB_CIRCLES_VISUALIZER
#define RGB_CIRCLES_VISUALIZER

#include "Visualizer.h"

///
/// \brief Three circles (One red, one green, one blue) growing or shrinking based on the music.
///
class RGBCirclesVisualizer : public Visualizer
{
public:
	RGBCirclesVisualizer(sf::RenderWindow* window, Music* music);
	void render();

private:
	sf::CircleShape _circles[3];
	const float RADIUS;
	float _aHist, _bHist, _cHist;					//Used for time smoothing

	///
	/// \brief Adjust the radius for each circle
	/// \param a Radius of red circle
	/// \param b Radius of blue circle
	/// \param c Radius of green circle
	///
	void adjustCircles(float a, float b, float c);

	float sum(float* vals, int size);
	float smooth(float n, float& hist);
};

#endif
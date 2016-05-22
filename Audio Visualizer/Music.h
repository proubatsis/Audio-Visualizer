/*
    Copyright (C) 2016 Panagiotis Roubatsis

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

	Description: An abstract class that defines the required
	functionality of the music playing/analyzing abilities
	for the visualizations.
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <vector>

///
/// \brief Plays music and provides the spectrum data to analyze it.
///
class Music
{
public:
	virtual ~Music() {}

	///
	/// \brief Play the music
	///
	virtual void play() = 0;

	///
	/// \brief Update spectrum data.
	///
	virtual void update() = 0;

	///
	/// \brief Return the spectrum data
	/// \return Spectrum data
	///
	virtual std::vector<float> getSpectrum() = 0;
};

#endif
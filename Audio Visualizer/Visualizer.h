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

	Description: An abstract class that defines the basic
	functionality of a visualizer.
*/

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>
#include "Music.h"

///
/// \brief A music visualizer that plays and renders a music visualization.
///
class Visualizer
{
public:
	///
	/// \brief Create a Visualizer
	/// \param window The window to render the visualizer on.
	/// \param music The music to play and analyze for the visualization.
	///
	Visualizer(sf::RenderWindow* window, Music* music) { vWindow = window; vMusic = music; }

	virtual ~Visualizer() { delete vMusic; }

	///
	/// \brief Render the visualization.
	///
	virtual void render() = 0;

	///
	/// \brief Play the music.
	///
	virtual void playMusic() { vMusic->play(); }

protected:
	sf::RenderWindow* vWindow;
	Music* vMusic;
};

#endif
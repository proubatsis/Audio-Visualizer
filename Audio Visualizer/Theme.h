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

	Description: Contains information that is used
	to theme a form and its gui elements.
*/

#ifndef THEME_H
#define THEME_H

#include <SFML/Graphics.hpp>

namespace gui
{
	///
	/// \brief A theme for use with a Form.
	///
	struct Theme
	{
		int formWidth;	///< Width of the form

		sf::Font font;	///< Font to use for rendering text

		sf::Color background;		///< Main background
		sf::Color formBackground;	///< Background of the form
		sf::Color border;			///< Form element outlines
		sf::Color text;				///< Text color of form elements
		sf::Color accent;			///< Used for color change on hover events
	};
};

#endif
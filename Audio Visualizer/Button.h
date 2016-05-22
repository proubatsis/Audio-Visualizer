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

	Description: A button GUI element that can be added to a form.
	A callback can be set for a button click event.
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Theme.h"

namespace gui
{
	///
	/// \brief A button that can be placed on a form and clicked.
	/// A button that when clicked calls a given callback function.
	///
	class Button
	{
	public:
		///
		/// \brief Create a Button.
		/// \param text The text that should be displayed on the button.
		/// \param x The x coordinate relative to the window.
		/// \param y The y coordinate relative to the window.
		/// \param clickCallback The function that should be called when the button is clicked.
		/// \param theme The form's theme.
		/// \param window The window to render the button on.
		///
		Button(std::string text, int x, int y, std::function<void ()> clickCallback, Theme& theme, sf::RenderWindow* window);

		//Calls the callback function if the given mouse co-ordinates are
		//within the bounds of the button.

		///
		/// \brief Calls the callback function if the coordinates are within the Button's bounds.
		///
		virtual void click(int x, int y);

		///
		/// \brief Adjust the Button's style if the coordinates are within the Button's bounds.
		///
		virtual void hover(int x, int y);

		///
		/// \brief Render the button.
		///
		virtual void render();

	protected:
		Theme& _theme;
		std::function<void ()> _callback;	///< This will be called if the button is clicked
		sf::RenderWindow* vWindow;

		sf::Rect<int> _bounds;				///< The bounds of the button, used for hover and click calculations
		sf::RectangleShape _shape;			///< The rectangle shape to be rendered as the body of the button
		sf::Text _text;						///< The text to be rendered as part of the button
	};
};

#endif
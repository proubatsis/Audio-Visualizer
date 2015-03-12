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
	class Button
	{
	public:
		Button(std::string text, int x, int y, std::function<void ()> clickCallback, Theme& theme, sf::RenderWindow* window);

		//Calls the callback function if the given mouse co-ordinates are
		//within the bounds of the button.
		virtual void click(int x, int y);

		//The button adjusts its style if the given mouse co-ordiantes
		//are within the bounds of the button.
		virtual void hover(int x, int y);

		virtual void render();

	protected:
		Theme& _theme;
		std::function<void ()> _callback;	//This will be called if the button is clicked
		sf::RenderWindow* vWindow;

		sf::Rect<int> _bounds;				//The bounds of the button, used for hover and click calculations
		sf::RectangleShape _shape;			//The rectangle shape to be rendered as the body of the button
		sf::Text _text;						//The text to be rendered as part of the button
	};
};

#endif
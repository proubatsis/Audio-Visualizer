/*
	Created by Panagiotis Roubatsis

	Description: A form where gui elements can be added.
	It should typically be used as a template to build
	a form with additional functionality.
*/

#ifndef FORM_H
#define FORM_H

#include <string>
#include <functional>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Theme.h"

#include "Button.h"
#include "RadioButton.h"

namespace gui
{
	class Form
	{
	public:
		Form(sf::RenderWindow* window, Theme& theme);

		//Add a button to the form. The x and y co-ordinates are relative to the form, not the window.
		void addButton(std::string text, int x, int y, std::function<void ()> clickCallback);

		//Add a radio button to the form. The x and y co-ordinates are relative to the form, not the window.
		void addRadioButton(std::string text, int x, int y, RadioGroup& group);

		//Add text to the form. The x and y co-ordinates are relative to the form, not the window.
		void addText(std::string text, int x, int y);

		void render();

	protected:
		sf::RenderWindow* vWindow;
		sf::RectangleShape _backgroundRectangle, _formRectangle;

		int _xOffset;	//Used to offset elements as they are added to the form.
		Theme& _theme;

		//GUI elements
		std::vector<Button> _buttons;
		std::vector<RadioButton> _radioButtons;
		std::vector<sf::Text> _textItems;

	private:
		bool _isMouseDownOnLastFrame;	//Used to determine whether the user has clicked or not
	};
};

#endif
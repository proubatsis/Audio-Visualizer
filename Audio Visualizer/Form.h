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

		void addButton(std::string text, int x, int y, std::function<void ()> clickCallback);
		void addRadioButton(std::string text, int x, int y, RadioGroup& group);
		void addText(std::string text, int x, int y);

		void render();

	protected:
		sf::RenderWindow* vWindow;
		sf::RectangleShape _backgroundRectangle, _formRectangle;

		float _xOffset;
		Theme& _theme;

		std::vector<Button> _buttons;
		std::vector<RadioButton> _radioButtons;
		std::vector<sf::Text> _textItems;
	};
};

#endif
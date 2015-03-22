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

#include "Form.h"

gui::Form::Form(sf::RenderWindow* window, Theme& theme)
	: _theme(theme), _isMouseDownOnLastFrame(false)
{
	vWindow = window;

	_backgroundRectangle.setFillColor(theme.background);
	_formRectangle.setFillColor(theme.formBackground);

	_backgroundRectangle.setPosition(0, 0);
	_backgroundRectangle.setSize((sf::Vector2f)window->getSize());

	_xOffset = (int)(0.5f * (window->getSize().x - theme.formWidth));
	_formRectangle.setPosition((float)_xOffset, 0);
	_formRectangle.setSize(sf::Vector2f((float)theme.formWidth, (float)window->getSize().y));
}

void gui::Form::addButton(std::string text, int x, int y, std::function<void ()> clickCallback)
{
	x += _xOffset;
	
	Button btn(text, x, y, clickCallback, _theme, vWindow);
	_buttons.push_back(btn);
}

void gui::Form::addRadioButton(std::string text, int x, int y, RadioGroup& group)
{
	x += _xOffset;

	RadioButton rBtn(text, x, y, group, _theme, vWindow);
	_radioButtons.push_back(rBtn);
}

void gui::Form::addText(std::string text, int x, int y)
{
	sf::Text sfText;

	sfText.setFont(_theme.font);
	sfText.setString(text);
	sfText.setPosition((float)x + _xOffset, (float)y);

	_textItems.push_back(sfText);
}

void gui::Form::render()
{
	//Render the background and the form background
	vWindow->draw(_backgroundRectangle);
	vWindow->draw(_formRectangle);

	//Render all the text
	for(size_t i = 0; i < _textItems.size(); i++) vWindow->draw(_textItems[i]);
	
	//Handle buttons hover and click events, then render them.
	for(size_t i = 0; i < _buttons.size(); i++)
	{
		sf::Vector2i point = sf::Mouse::getPosition(*vWindow);

		_buttons[i].hover(point.x, point.y);
		if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && _isMouseDownOnLastFrame) _buttons[i].click(point.x, point.y);
		
		_buttons[i].render();
	}
	
	//Handle radio buttons hover and click events, then render them.
	for(size_t i = 0; i < _radioButtons.size(); i++)
	{
		sf::Vector2i point = sf::Mouse::getPosition(*vWindow);

		_radioButtons[i].hover(point.x, point.y);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) _radioButtons[i].click(point.x, point.y);
		
		_radioButtons[i].render();
	}

	_isMouseDownOnLastFrame = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

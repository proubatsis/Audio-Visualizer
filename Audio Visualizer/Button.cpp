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

#include "Button.h"

gui::Button::Button(std::string text, int x, int y, std::function<void ()> clickCallback, Theme& theme, sf::RenderWindow* window)
	: _theme(theme)
{
	vWindow = window;
	_theme = theme;
	_callback = clickCallback;

	_text.setFont(_theme.font);
	_text.setString(text);
	_text.setPosition(x + 1.0f, y + 1.0f);
	_text.setColor(theme.text);
	
	_bounds.left = x;
	_bounds.top = y;
	_bounds.width = (_text.getCharacterSize() / 2) * text.length() + 16;
	_bounds.height = (int)(_text.getCharacterSize() * 1.2f + 4);

	_shape.setPosition((float)x, (float)y);
	_shape.setSize(sf::Vector2f((float)_bounds.width, (float)_bounds.height));
	_shape.setFillColor(theme.background);
	_shape.setOutlineColor(theme.border);
	_shape.setOutlineThickness(1);
}

void gui::Button::hover(int x, int y)
{
	if(_bounds.contains(x, y))
		_text.setColor(_theme.accent);
	else
		_text.setColor(_theme.text);
}

void gui::Button::click(int x, int y)
{
	if(_bounds.contains(x, y))
		_callback();
}

void gui::Button::render()
{
	vWindow->draw(_shape);
	vWindow->draw(_text);
}

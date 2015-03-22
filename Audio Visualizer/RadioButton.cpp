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

#include "RadioButton.h"

gui::RadioButton::RadioButton(std::string text, int x, int y, RadioGroup& group, Theme& theme, sf::RenderWindow* window)
	: Button(text, x, y, /*Empty lambda function (No callback is necessary)*/ [](){}, theme, window), _group(group)
{
	_groupID =_group.add();

	_shape.setFillColor(theme.formBackground);
	_shape.setOutlineColor(theme.formBackground);

	_text.setPosition(_text.getPosition().x + _text.getCharacterSize() + 2, _text.getPosition().y);

	_selectionCircle.setRadius((float)_text.getCharacterSize() / 2);
	_selectionCircle.setOutlineColor(theme.border);
	_selectionCircle.setOutlineThickness(2);
	_selectionCircle.setFillColor(theme.text);
	_selectionCircle.setPosition((float)x, y + 1.0f);
}

void gui::RadioButton::click(int x, int y)
{
	if(_bounds.contains(x, y))
		_group.check(_groupID);
}

void gui::RadioButton::render()
{
	Button::render();

	//If the button is checked fill the circle with a distinct colour, otherwise
	//make it the same as the form's colour to indicate that is is not checked.
	if(_group.getCheckedId() == _groupID) _selectionCircle.setFillColor(_theme.accent);
	else _selectionCircle.setFillColor(_theme.formBackground);

	vWindow->draw(_selectionCircle);
}
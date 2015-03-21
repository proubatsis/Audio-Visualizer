#include "Button.h"

gui::Button::Button(std::string text, int x, int y, std::function<void ()> clickCallback, Theme& theme, sf::RenderWindow* window)
	: _theme(theme)
{
	vWindow = window;
	_theme = theme;
	_callback = clickCallback;

	_text.setFont(_theme.font);
	_text.setString(text);
	_text.setPosition(x + 1, y + 1);
	_text.setColor(theme.text);
	
	_bounds.left = x;
	_bounds.top = y;
	_bounds.width = (_text.getCharacterSize() / 2) * text.length() + 16;
	_bounds.height = _text.getCharacterSize() * 1.2f + 4;

	_shape.setPosition(x, y);
	_shape.setSize(sf::Vector2f(_bounds.width, _bounds.height));
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

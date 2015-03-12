#include "Form.h"

gui::Form::Form(sf::RenderWindow* window, Theme& theme)
	: _theme(theme), _isMouseDownOnLastFrame(false)
{
	vWindow = window;

	_backgroundRectangle.setFillColor(theme.background);
	_formRectangle.setFillColor(theme.formBackground);

	_backgroundRectangle.setPosition(0, 0);
	_backgroundRectangle.setSize((sf::Vector2f)window->getSize());

	_xOffset = 0.5f * (window->getSize().x - theme.formWidth);
	_formRectangle.setPosition(_xOffset, 0);
	_formRectangle.setSize(sf::Vector2f(theme.formWidth, window->getSize().y));
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
	sfText.setPosition(x + _xOffset, y);

	_textItems.push_back(sfText);
}

void gui::Form::render()
{
	vWindow->draw(_backgroundRectangle);
	vWindow->draw(_formRectangle);

	for(int i = 0; i < _textItems.size(); i++) vWindow->draw(_textItems[i]);
	
	for(int i = 0; i < _buttons.size(); i++)
	{
		sf::Vector2i point = sf::Mouse::getPosition(*vWindow);

		_buttons[i].hover(point.x, point.y);
		if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && _isMouseDownOnLastFrame) _buttons[i].click(point.x, point.y);
		
		_buttons[i].render();
	}
	
	for(int i = 0; i < _radioButtons.size(); i++)
	{
		sf::Vector2i point = sf::Mouse::getPosition(*vWindow);

		_radioButtons[i].hover(point.x, point.y);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) _radioButtons[i].click(point.x, point.y);
		
		_radioButtons[i].render();
	}

	_isMouseDownOnLastFrame = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

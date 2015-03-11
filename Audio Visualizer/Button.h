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

		virtual void click(int x, int y);
		virtual void hover(int x, int y);

		virtual void render();

	protected:
		Theme& _theme;
		std::function<void ()> _callback;
		sf::RenderWindow* vWindow;

		sf::Rect<int> _bounds;
		sf::RectangleShape _shape;
		sf::Text _text;
	};
};

#endif
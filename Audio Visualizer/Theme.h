#ifndef THEME_H
#define THEME_H

#include <SFML/Graphics.hpp>

namespace gui
{
	struct Theme
	{
		int formWidth;

		sf::Font font;
		sf::Color background, formBackground, border, text, accent;
	};
};

#endif
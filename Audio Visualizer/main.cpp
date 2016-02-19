/*
    Copyright (C) 2016 Panagiotis Roubatsis

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

/*
	Created by Panagiotis Roubatsis

	Description: Software that plays and visualizes music.
*/

#ifdef _DEBUG
#include <vld.h>
#endif

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ChooseMenuForm.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Audio Visualizer - By: Panagiotis Roubatsis");
	window.setVerticalSyncEnabled(true);

	//Set up the theme for the GUI
	gui::Theme theme;
	theme.background = sf::Color(2, 81, 103);		//#025167
	theme.formBackground = sf::Color(0, 143, 182);	//#008FB6
	theme.border = sf::Color(0, 179, 228);			//#00B3E4
	theme.text = sf::Color(255, 255, 255);			//#FFFFFF
	theme.accent = sf::Color(255, 140, 0);			//#FF8C00
	theme.formWidth = (int)(window.getSize().x * 0.95f);
	theme.font.loadFromFile("font.ttf");

	ChooseMenuForm form(&window, theme);

	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed) window.close();
		}

		window.clear();
		form.render();
		window.display();
	}

	return 0;
}

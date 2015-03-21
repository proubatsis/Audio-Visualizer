/*
	Created by Panagiotis Roubatsis

	Description: Software that plays and visualizes music.
*/

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

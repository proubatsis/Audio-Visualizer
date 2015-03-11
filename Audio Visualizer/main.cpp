#include <iostream>
#include <SFML/Graphics.hpp>
#include "ChooseMenuForm.h"

using namespace std;

int main()
{
	//FMODMusic music("ee.mp3");

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello, World!");
	window.setVerticalSyncEnabled(true);

	//PieVisualizer visualizer(&window, &music);
	//music.play();

	//Set up the theme for the GUI
	gui::Theme theme;
	theme.background = sf::Color(2, 81, 103);		//#025167
	theme.formBackground = sf::Color(0, 143, 182);	//#008FB6
	theme.border = sf::Color(0, 179, 228);			//#00B3E4
	theme.text = sf::Color(255, 255, 255);			//#FFFFFF
	theme.accent = sf::Color(255, 140, 0);			//#FF8C00
	theme.formWidth = window.getSize().x * 0.75f;
	theme.font.loadFromFile("arial.ttf");

	ChooseMenuForm form(&window, theme);

	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed) window.close();
		}

		//music.update();

		window.clear();
		//visualizer.render();
		form.render();
		window.display();
	}

	return 0;
}

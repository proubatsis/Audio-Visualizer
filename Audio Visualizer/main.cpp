#include <iostream>
#include <SFML/Graphics.hpp>
#include "FMODMusic.h"
#include "BarVisualizer.h"
#include "RGBCirclesVisualizer.h"
#include "ColourVisualizer.h"

using namespace std;

int main()
{
	FMODMusic music("ee.mp3");

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello, World!");
	window.setVerticalSyncEnabled(true);

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(100, 25));
	shape.setPosition(100, 200);

	BarVisualizer visualizer(&window, &music);
	music.play();

	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed) window.close();
		}

		music.update();

		window.clear();
		visualizer.render();
		window.display();
	}

	return 0;
}
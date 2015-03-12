/*
	Created by Panagiotis Roubatsis

	Description: An abstract class that defines the basic
	functionality of a visualizer.
*/

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>
#include "Music.h"

class Visualizer
{
public:
	Visualizer(sf::RenderWindow* window, Music* music) { vWindow = window; vMusic = music; }
	virtual void render() = 0;

protected:
	sf::RenderWindow* vWindow;
	Music* vMusic;
};

#endif
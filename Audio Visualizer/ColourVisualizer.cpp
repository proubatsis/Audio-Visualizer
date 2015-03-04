#include "ColourVisualizer.h"

ColourVisualizer::ColourVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music)
{
	_rect.setPosition(0, 0);
	_rect.setSize(sf::Vector2f(window->getSize()));
}

void ColourVisualizer::render()
{
	std::vector<float> spectrum = vMusic->getSpectrum();

	float r, g, b;
	r = spectrum[0];
	g = spectrum[5];
	b = spectrum[10];

	sf::Color color(r * 255, g * 255, b * 255);
	_rect.setFillColor(color);

	vWindow->draw(_rect);
}
#include "BarVisualizer.h"

BarVisualizer::BarVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music)
{
	_barWidth = 10;

	for(int i = 0; i < window->getSize().x / _barWidth; i++)
		_bars.push_back(sf::RectangleShape(sf::Vector2f(i * _barWidth, 0)));
}

void BarVisualizer::render()
{
	std::vector<float> spectrum = vMusic->getSpectrum();
	int iter = _bars.size() < spectrum.size() ? _bars.size() : spectrum.size();

	for(int i = 0; i < iter; i++)
	{
		int h = spectrum[i] * vWindow->getSize().y * 0.5f;
		_bars[i].setPosition(i * _barWidth, vWindow->getSize().y - h);
		_bars[i].setSize(sf::Vector2f(_barWidth, h));

		vWindow->draw(_bars[i]);
	}
}
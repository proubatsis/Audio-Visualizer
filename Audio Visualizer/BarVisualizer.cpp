#include "BarVisualizer.h"

BarVisualizer::BarVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music)
{
	_barWidth = 5;
	_areBarsInitialized = false;
}

void BarVisualizer::initializeBars()
{
	for(size_t i = 0; i < vWindow->getSize().x / _barWidth; i++)
		_bars.push_back(sf::RectangleShape(sf::Vector2f(i * _barWidth, 0)));
}

void BarVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float h = (spectrum[i] / 0.05f) * vWindow->getSize().y * 0.5f;
	_bars[i].setPosition(i * _barWidth, vWindow->getSize().y - h);
	_bars[i].setSize(sf::Vector2f(_barWidth, h));
}

void BarVisualizer::smooth(std::vector<float>& spectrum)
{
	std::vector<float> a = _previousSpectrum;
	_previousSpectrum = spectrum;

	if(a.size() == 0) return;

	for(size_t i = 0; i < a.size(); i++)
		spectrum[i] = 0.5f * (spectrum[i] - a[i]) + a[i];
}

void BarVisualizer::render()
{
	if(!_areBarsInitialized)
	{
		initializeBars();
		_areBarsInitialized = true;
	}

	std::vector<float> spectrum = vMusic->getSpectrum();
	smooth(spectrum);

	int iter = _bars.size() < spectrum.size() ? _bars.size() : spectrum.size();

	for(int i = 0; i < iter; i++)
	{
		setBar(i, spectrum);
		vWindow->draw(_bars[i]);
	}
}
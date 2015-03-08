#include "CircleBarVisualizer.h"
#include <cmath>

#define TO_DEG (180 / 3.14159265359)

CircleBarVisualizer::CircleBarVisualizer(sf::RenderWindow* window, Music* music)
	: BarVisualizer(window, music)
{
	_barWidth = 10;
	_innerRadius = 25;
}

void CircleBarVisualizer::initializeBars()
{
	_thetaR = acosf(1-((_barWidth * _barWidth) / (2 * _innerRadius * _innerRadius)));
	_theta = _thetaR * TO_DEG;
	
	int barCount = 360 / _theta;

	for(int i = 0; i < barCount * 2; i++)
		_bars.push_back(sf::RectangleShape(sf::Vector2f(0, 0)));
}

void CircleBarVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	int h = (spectrum[i] / 0.125f) * vWindow->getSize().y * 0.5f + 1;

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, h));
	_bars[i].rotate(angle);
	_bars[i].setPosition(_innerRadius * cos(angleR) + vWindow->getSize().x / 2, _innerRadius * sin(angleR) + vWindow->getSize().y / 2);
}

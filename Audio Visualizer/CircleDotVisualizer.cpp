#include "CircleDotVisualizer.h"

CircleDotVisualizer::CircleDotVisualizer(sf::RenderWindow* window, Music* music)
	: CircleBarVisualizer(window, music)
{
	_barWidth = 3;
}

void CircleDotVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	int h = (spectrum[i] / 0.125f) * vWindow->getSize().y * 0.5f;

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, _barWidth));
	_bars[i].rotate(angle);
	_bars[i].setPosition((_innerRadius+h) * cos(angleR) + vWindow->getSize().x / 2, (_innerRadius+h) * sin(angleR) + vWindow->getSize().y / 2);
}
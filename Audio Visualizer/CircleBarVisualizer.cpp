#include "CircleBarVisualizer.h"
#include <cmath>

#define TO_DEG (180 / 3.14159265359)

CircleBarVisualizer::CircleBarVisualizer(sf::RenderWindow* window, Music* music)
	: BarVisualizer(window, music)
{
	_barWidth = 3;
	_innerRadius = 50;

	_barCountMultiplier = 2;
	_barNormalAngle = -90;
}

void CircleBarVisualizer::initializeBars()
{
	//Formula derived using the cosine law
	//                     +
	//                 *   |
	//         r    *      |
	//           *         |
	//        *            |
	//     *               |
	//  *     theta        | b
	//     *               |
	//        *            |
	//           *         |
	//        r     *      |
	//                 *   |
	//                     +
	
	// cos(theta) = (1 - b ^ 2) / (2 * r ^ 2)
	_thetaR = acosf(1-((_barWidth * _barWidth) / (2 * _innerRadius * _innerRadius)));
	_theta = _thetaR * TO_DEG;
	
	int barCount = 360 / _theta;

	for(int i = 0; i < barCount * _barCountMultiplier; i++)
		_bars.push_back(sf::RectangleShape(sf::Vector2f(0, 0)));
}

void CircleBarVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	int h = (spectrum[i] / 0.125f) * vWindow->getSize().y * 0.5f + 1;

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, h));
	_bars[i].rotate(angle + _barNormalAngle);
	_bars[i].setPosition(_innerRadius * cos(angleR) + vWindow->getSize().x / 2, _innerRadius * sin(angleR) + vWindow->getSize().y / 2);
}

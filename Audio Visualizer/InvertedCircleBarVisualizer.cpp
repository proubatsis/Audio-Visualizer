#include "InvertedCircleBarVisualizer.h"
#include <cmath>

InvertedCircleBarVisualizer::InvertedCircleBarVisualizer(sf::RenderWindow* window, Music* music)
	: CircleBarVisualizer(window, music)
{
	_barWidth = 16;
	_innerRadius = 256;

	_barNormalAngle = 90;
	_barCountMultiplier = 1;

	_colorAngleOffset = 0;
}

float InvertedCircleBarVisualizer::interpolate(float a, float b, float t)
{
	t = t * t * (3 - 2 * t);
	return t * (b - a) + a;
}

sf::Color InvertedCircleBarVisualizer::getColor(float angle)
{
	angle = fmodf(angle + _colorAngleOffset, 360);

	const float ONE_THIRD_ROT = 360 / 3;
	float t = (fmodf(angle, ONE_THIRD_ROT)) / ONE_THIRD_ROT;
	int r = 0, g = 0, b = 0;

	if(angle < ONE_THIRD_ROT)
	{
		r = (int)interpolate(255, 0, t);
		g = (int)interpolate(0, 255, t);
	}else if(angle >= ONE_THIRD_ROT && angle < 2 * ONE_THIRD_ROT)
	{
		g = (int)interpolate(255, 0, t);
		b = (int)interpolate(0, 255, t);
	}else
	{
		b = (int)interpolate(255, 0, t);
		r = (int)interpolate(0, 255, t);
	}

	return sf::Color(r, g, b, 128);
}

void InvertedCircleBarVisualizer::setBar(int i, std::vector<float>& spectrum)
{
	float angle = _theta * i;
	float angleR = _thetaR * i;
	
	_volume += spectrum[i];
	int h = (spectrum[i] / 0.125f) * _innerRadius * 3;

	//Damp the lower frequencies
	float t = (float)i / (_bars.size() - 1);
	t = t * t * (3 - 2 * t);
	h *= (t * 0.7f + 0.3f);
	h += 1;

	_bars[i] = sf::RectangleShape(sf::Vector2f(_barWidth, h));
	_bars[i].rotate(angle + _barNormalAngle);
	_bars[i].setPosition(_innerRadius * cos(angleR) + vWindow->getSize().x / 2, _innerRadius * sin(angleR) + vWindow->getSize().y / 2);
	_bars[i].setFillColor(getColor(angle));
}

void InvertedCircleBarVisualizer::render()
{
	_volume = 0;
	CircleBarVisualizer::render();
	_colorAngleOffset += _clock.restart().asSeconds() + _volume;
}
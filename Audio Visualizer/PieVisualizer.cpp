#include "PieVisualizer.h"
#define PI 3.14159265359

PieVisualizer::PieVisualizer(sf::RenderWindow* window, Music* music)
	: Visualizer(window, music), SEGMENTS(32), BASE_RADIUS(64)
{
	const float ANGLE = 360 / SEGMENTS;
	const float ANGLERADS = (2 * PI) / SEGMENTS;
	const float TRIG_ANGLE = (PI - ANGLERADS) / 2;

	const float HORIZ = cosf(TRIG_ANGLE), VERT = sinf(TRIG_ANGLE);

	for(int i = 0; i < SEGMENTS; i++)
	{
		Segment segment;

		sf::ConvexShape shape;
		shape.setPointCount(3);

		shape.setPoint(0, sf::Vector2f(0, 0));
		shape.setPoint(1, sf::Vector2f(BASE_RADIUS * HORIZ, -BASE_RADIUS * VERT));
		shape.setPoint(2, sf::Vector2f(-BASE_RADIUS * HORIZ, -BASE_RADIUS * VERT));

		shape.setPosition(vWindow->getSize().x / 2, vWindow->getSize().y / 2);
		shape.rotate(i * ANGLE);

		segment.triangle = shape;
		segment.moveDirection = sf::Vector2f(sinf(i * ANGLERADS), -cosf(i * ANGLERADS));

		_segments.push_back(segment);
	}

	_beatCircle.setFillColor(sf::Color(128, 128, 128));
	_beatCircle2.setFillColor(sf::Color(128, 128, 128));
}

float PieVisualizer::sum(float* nums, int size)
{
	float s = 0;
	for(int i = 0; i < size; i++) s += nums[i];
	return s;
}

void PieVisualizer::smooth(std::vector<float>& sums)
{
	if(_previousSums.size() == 0)
	{
		_previousSums = sums;
		return;
	}

	for(int i = 0; i < sums.size(); i++)
	{
		float a = _previousSums[i];
		float b = sums[i];

		sums[i] = 0.5f * (b - a) + a;
	}

}

float PieVisualizer::interpolate(float a, float b, float t)
{
	t = t * t * (3 - 2 * t);
	return t * (b - a) + a;
}

sf::Color PieVisualizer::getColor(int i, float sum)
{
	const int ONE_THIRD_SEGS = SEGMENTS / 3 + 1;
	float t = (i % ONE_THIRD_SEGS) / (float)ONE_THIRD_SEGS;
	int r = 0, g = 0, b = 0;

	if(i < ONE_THIRD_SEGS)
	{
		r = (int)interpolate(255, 0, t);
		g = (int)interpolate(0, 255, t);
	}else if(i >= ONE_THIRD_SEGS && i < 2 * ONE_THIRD_SEGS)
	{
		g = (int)interpolate(255, 0, t);
		b = (int)interpolate(0, 255, t);
	}else
	{
		b = (int)interpolate(255, 0, t);
		r = (int)interpolate(0, 255, t);
	}

	float scale = sum * 100 + 0.1f;
	return sf::Color(r * scale, g * scale, b * scale);
}

void PieVisualizer::render()
{
	std::vector<float> spectrum = vMusic->getSpectrum();

	std::vector<float> sums;

	const int SUM_SLICE = 8;
	const int BASE_INDEX = 16;

	sums.push_back(sum(&spectrum[0], 8));
	sums.push_back(sum(&spectrum[8], 8));

	for(int i = 0; i < _segments.size(); i++)
		sums.push_back(sum(&spectrum[BASE_INDEX + SUM_SLICE * i], SUM_SLICE));

	smooth(sums);

	//Draw the two beat circles
	_beatCircle.setRadius(BASE_RADIUS + sums[0] * 32);
	_beatCircle2.setRadius(BASE_RADIUS + sums[1] * 32);
	_beatCircle.setPosition(vWindow->getSize().x / 4 - _beatCircle.getRadius(), vWindow->getSize().y / 2 - _beatCircle.getRadius());
	_beatCircle2.setPosition(3 * vWindow->getSize().x / 4 - _beatCircle2.getRadius(), vWindow->getSize().y / 2 - _beatCircle2.getRadius());
	vWindow->draw(_beatCircle);
	vWindow->draw(_beatCircle2);

	//Draw the main frequency circle
	for(int i = 0; i < _segments.size(); i++)
	{
		float d = sums[i + 2] * 1024;

		//Damp the lower frequencies
		float t = i / 31.0f;
		t = t * t * (3 - 2 * t);
		d *= (t * 0.5f + 0.5f);

		_segments[i].triangle.setPosition(
			vWindow->getSize().x / 2 + _segments[i].moveDirection.x * d,
			vWindow->getSize().y / 2 + _segments[i].moveDirection.y * d);

		_segments[i].triangle.setFillColor(getColor(i, sums[i + 2]));

		vWindow->draw(_segments[i].triangle);
	}
}
/*
	Created by Panagiotis Roubatsis

	Description: A variant of the BarVisualizer where the bars are
	arranged in a circle and the bars extend outwards from the circle.
*/

#ifndef CIRCLE_BAR_VISUALIZER_H
#define CIRCLE_BAR_VISUALIZER_H

#include "BarVisualizer.h"

class CircleBarVisualizer : public BarVisualizer
{
public:
	CircleBarVisualizer(sf::RenderWindow* window, Music* music);

protected:
	float _innerRadius;			//The blank radius inside the circle
	float _theta;				//Angle for each rotation in degrees
	float _thetaR;				//_theta in radians
	float _barNormalAngle;		//The angle rotated for the bar to be a normal to the circle
	float _barCountMultiplier;	//How many more bars do we want then the minimum?

	virtual void initializeBars();
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
/*
	Created by Panagiotis Roubatsis

	Description: A standard bar graph visualization of Amplitude vs Frequency.
*/

#ifndef BAR_VISUALIZER_H
#define BAR_VISUALIZER_H

#include <vector>
#include "Visualizer.h"

class BarVisualizer : public Visualizer
{
public:
	BarVisualizer(sf::RenderWindow* window, Music* music);
	virtual void render();

private:
	std::vector<float> _previousSpectrum;	//Used for time smoothing.
	bool _areBarsInitialized;				//Has initializeBars() been called yet?

protected:
	float _barWidth;
	std::vector<sf::RectangleShape> _bars;	//The bars that will be rendered to the screen

	//Smooth the current spectrum based on the previous one using interpolation.
	void smooth(std::vector<float>& spectrum);

	virtual void initializeBars();

	//Sets the bar of given index 'i' to have specific properties
	//such as position, size and rotation based on the spectrum values.
	virtual void setBar(int i, std::vector<float>& spectrum);
};

#endif
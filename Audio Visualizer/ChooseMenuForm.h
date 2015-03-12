/*
	Created by Panagiotis Roubatsis

	Description: A child of the Form class. It provides
	a menu for the user to choose their desired visualization
	and song.
*/

#ifndef CHOOSE_MENU_FORM
#define CHOOSE_MENU_FORM

#include <SFML/Graphics.hpp>
#include "Form.h"

#include "FMODMusic.h"
#include "Visualizers.h"

class ChooseMenuForm : public gui::Form
{
public:
	ChooseMenuForm(sf::RenderWindow* window, gui::Theme& theme);
	~ChooseMenuForm();

	void render();

private:
	bool _isFormActive;					//Should the form or the visualizer be rendered?

	Music* _music;
	Visualizer* _visualizer;

	gui::RadioGroup _visualizerGroup;
	std::string _filePath;

	void playMusic();
	void openFile();
};

#endif
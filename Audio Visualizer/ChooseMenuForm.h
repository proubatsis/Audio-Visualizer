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
	bool _isFormActive;

	Music* _music;
	Visualizer* _visualizer;

	gui::RadioGroup _visualizerGroup;

	void playMusic();
	void openFile();
};

#endif
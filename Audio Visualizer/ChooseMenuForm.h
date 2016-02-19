/*
    Copyright (C) 2016 Panagiotis Roubatsis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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

	//Return the visualizer that was chosen in the menu
	Visualizer* getVisualizer();

private:
	gui::RadioGroup _visualizerGroup;
	std::string _filePath;

	void openFile();
};

#endif
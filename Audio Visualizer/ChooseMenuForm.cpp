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

#include "ChooseMenuForm.h"
#include "WindowsFileDialog.h"
#include <iostream>
#include <ShObjIdl.h>

ChooseMenuForm::ChooseMenuForm(sf::RenderWindow* window, gui::Theme& theme)
	: Form(window, theme), _filePath("")
{
	//Configure the form with its elements
	const int BASE_X = 75;
	const int BASE_Y = 25;

	addText("Audio Visualizer - By: Panagiotis Roubatsis", BASE_X, BASE_Y);
	addText("Choose an effect:", BASE_X, BASE_Y + 60);

	addButton("Play Song!", BASE_X, BASE_Y + 410,
		[=]()
	{
		this->openFile();
		if(_filePath.length() > 0) vWindow->close();
	});

	addRadioButton("Bar Graph", BASE_X + 25, BASE_Y + 100, _visualizerGroup);
	addRadioButton("Circle Bar Graph", BASE_X + 25, BASE_Y + 140, _visualizerGroup);
	addRadioButton("Red, Green & Blue Circles", BASE_X + 25, BASE_Y + 180, _visualizerGroup);
	addRadioButton("Dots", BASE_X + 25, BASE_Y + 220, _visualizerGroup);
	addRadioButton("Colourful Pie", BASE_X + 25, BASE_Y + 260, _visualizerGroup);
	addRadioButton("Rainbow Disc", BASE_X + 25, BASE_Y + 300, _visualizerGroup);
	addRadioButton("Rings", BASE_X + 25, BASE_Y + 340, _visualizerGroup);

	//Check the bar graph radio button by default
	_visualizerGroup.check(0);
}

ChooseMenuForm::~ChooseMenuForm()
{

}

void ChooseMenuForm::render()
{
	Form::render();
}

void ChooseMenuForm::openFile()
{
	//Create appropriate filters for the file open dialog
	COMDLG_FILTERSPEC filters[] =
	{
		{L"Music", L"*.mp3;*.ogg;*.wav;*.wma"}
	};

	//Show the dialog to the user
	WindowsFileDialog dialog(std::vector<COMDLG_FILTERSPEC>(filters, filters + 1));
	dialog.openDialog();

	//Retrieve the file's path assuming that one has been chosen.
	if(dialog.isFileChosen())
	{
		_filePath = dialog.getFilePath();
	}
	else
	{
		_filePath = "";
	}
}

Visualizer* ChooseMenuForm::getVisualizer()
{
	Music* music;

	if(_filePath.length() > 0) music = new FMODMusic(_filePath);
	else return 0;

	switch(_visualizerGroup.getCheckedId())
	{
	case 0:
		return new BarVisualizer(vWindow, music);
	case 1:
		return new CircleBarVisualizer(vWindow, music);
	case 2:
		return new RGBCirclesVisualizer(vWindow, music);
	case 3:
		return new CircleDotVisualizer(vWindow, music);
	case 4:
		return new PieVisualizer(vWindow, music);
	case 5:
		return new InvertedCircleBarVisualizer(vWindow, music);
	case 6:
		return new RingsVisualizer(vWindow, music);
	default:
		return new BarVisualizer(vWindow, music);
	}
}
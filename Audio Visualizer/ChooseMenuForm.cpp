#include "ChooseMenuForm.h"
#include "WindowsFileDialog.h"
#include <iostream>

ChooseMenuForm::ChooseMenuForm(sf::RenderWindow* window, gui::Theme& theme)
	: Form(window, theme)
{
	//Null the pointers until we want to start playing music
	_music = 0;
	_visualizer = 0;

	//The form should be displayed first
	_isFormActive = true;

	//Configure the form with its elements
	const int BASE_X = 75;
	const int BASE_Y = 25;

	addText("Audio Visualizer - By: Panagiotis Roubatsis", BASE_X, BASE_Y);
	addText("Choose a song:", BASE_X, BASE_Y + 45);
	addText("Choose an effect:", BASE_X, BASE_Y + 130);
	addText("", BASE_X + 230, BASE_Y + 80);

	addButton("Open Music File", BASE_X + 25, BASE_Y + 80, [=](){this->openFile();});
	addButton("Play Song!", BASE_X, BASE_Y + 370, [=](){this->playMusic();});

	addRadioButton("Bar Graph", BASE_X + 25, BASE_Y + 160, _visualizerGroup);
	addRadioButton("Circle Bar Graph", BASE_X + 25, BASE_Y + 200, _visualizerGroup);
	addRadioButton("Red, Green & Blue Circles", BASE_X + 25, BASE_Y + 240, _visualizerGroup);
	addRadioButton("Dots", BASE_X + 25, BASE_Y + 280, _visualizerGroup);
	addRadioButton("Colourful Pie", BASE_X + 25, BASE_Y + 320, _visualizerGroup);
}

ChooseMenuForm::~ChooseMenuForm()
{
	if(_music != 0) delete _music;
	if(_visualizer != 0) delete _visualizer;
}

void ChooseMenuForm::render()
{
	if(_isFormActive)
		Form::render();
	else
	{
		_music->update();
		_visualizer->render();
	}
}

void ChooseMenuForm::openFile()
{
	WindowsFileDialog dialog;
	dialog.openDialog();

	if(dialog.isFileChosen()) _filePath = dialog.getFilePath();
	else _filePath = "";

	_textItems[_textItems.size() - 1].setString(_filePath);
}

void ChooseMenuForm::playMusic()
{
	_music = new FMODMusic(_filePath);
	_visualizer = new BarVisualizer(vWindow, _music);

	switch(_visualizerGroup.getCheckedId())
	{
	case 0:
		_visualizer = new BarVisualizer(vWindow, _music);
		break;
	case 1:
		_visualizer = new CircleBarVisualizer(vWindow, _music);
		break;
	case 2:
		_visualizer = new RGBCirclesVisualizer(vWindow, _music);
		break;
	case 3:
		_visualizer = new CircleDotVisualizer(vWindow, _music);
		break;
	case 4:
		_visualizer = new PieVisualizer(vWindow, _music);
		break;
	default:
		_visualizer = new BarVisualizer(vWindow, _music);
		break;
	}

	_music->play();

	_isFormActive = false;
}
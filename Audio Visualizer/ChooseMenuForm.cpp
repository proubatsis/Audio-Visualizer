#include "ChooseMenuForm.h"
#include "WindowsFileDialog.h"
#include <iostream>
#include <ShObjIdl.h>

ChooseMenuForm::ChooseMenuForm(sf::RenderWindow* window, gui::Theme& theme)
	: Form(window, theme)
{
	//Make the pointers null until we want to start playing music
	_music = 0;
	_visualizer = 0;

	//The form should be displayed first
	_isFormActive = true;

	//Configure the form with its elements
	const int BASE_X = 75;
	const int BASE_Y = 25;

	addText("Audio Visualizer - By: Panagiotis Roubatsis", BASE_X, BASE_Y);
	addText("Choose an effect:", BASE_X, BASE_Y + 60);

	addButton("Play Song!", BASE_X, BASE_Y + 410,
		[=]()
	{
		this->openFile();
		if(_filePath.length() > 0) this->playMusic();
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
	//Create appropriate filters for the file open dialog
	COMDLG_FILTERSPEC filters[] =
	{
		{L"Music", L"*.mp3;*.ogg;*.wav;*.wma"}
	};

	//Show the dialog to the user
	WindowsFileDialog dialog(std::vector<COMDLG_FILTERSPEC>(filters, filters + 1));
	dialog.openDialog();

	//Retrieve the file's path assuming that one has been chosen.
	if(dialog.isFileChosen()) _filePath = dialog.getFilePath();
	else _filePath = "";
}

void ChooseMenuForm::playMusic()
{
	//Use the FMod library for music playback
	//and analysis.
	_music = new FMODMusic(_filePath);

	//Determine which visualization to use
	//based on which radio button is checked.
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
	case 5:
		_visualizer = new InvertedCircleBarVisualizer(vWindow, _music);
		break;
	case 6:
		_visualizer = new RingsVisualizer(vWindow, _music);
		break;
	default:
		_visualizer = new BarVisualizer(vWindow, _music);
		break;
	}

	_music->play();

	//Display the visualizer instead of the form.
	_isFormActive = false;
}
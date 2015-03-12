/*
	Created by Panagiotis Roubatsis
	Description: An abstract class to represent an open file dialog.
*/

#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <string>

class FileDialog
{
public:

	//Opens and displays the dialog to the user
	virtual void openDialog() = 0;

	virtual std::string getFilePath() = 0;
	
	//Did the user click ok or cancel?
	virtual bool isFileChosen() = 0;
};

#endif
#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <string>

class FileDialog
{
public:
	virtual void openDialog() = 0;
	virtual std::string getFilePath() = 0;
	virtual bool isFileChosen() = 0;
};

#endif
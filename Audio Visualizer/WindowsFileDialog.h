#ifndef WINDOWS_FILE_DIALOG
#define WINDOWS_FILE_DIALOG

#include "FileDialog.h"

class WindowsFileDialog : public FileDialog
{
public:
	WindowsFileDialog();

	void openDialog();
	std::string getFilePath();
	bool isFileChosen();

private:
	std::string _filePath;
	bool _success;
};

#endif
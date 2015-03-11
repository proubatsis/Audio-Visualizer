#ifndef WINDOWS_FILE_DIALOG
#define WINDOWS_FILE_DIALOG

#include <Windows.h>
#include <ShObjIdl.h>
#include <vector>
#include "FileDialog.h"

class WindowsFileDialog : public FileDialog
{
public:
	WindowsFileDialog();
	WindowsFileDialog(std::vector<COMDLG_FILTERSPEC> filterSpecifications);

	void openDialog();
	std::string getFilePath();
	bool isFileChosen();

private:
	std::vector<COMDLG_FILTERSPEC> _filterSpecifications;

	std::string _filePath;
	bool _success;
};

#endif
/*
	Created by Panagiotis Roubatsis

	Description: An implementation of the FileDialog abstract class.
	It uses the Windows API to create and show the dialog.
*/

#ifndef WINDOWS_FILE_DIALOG
#define WINDOWS_FILE_DIALOG

#include <Windows.h>
#include <ShObjIdl.h>
#include <vector>
#include "FileDialog.h"

class WindowsFileDialog : public FileDialog
{
public:
	
	//Standard open file dialog with no filters
	WindowsFileDialog();

	//Assign filters so only specific file types are displayed in the dialog
	WindowsFileDialog(std::vector<COMDLG_FILTERSPEC> filterSpecifications);

	void openDialog();
	std::string getFilePath();
	bool isFileChosen();

private:
	std::vector<COMDLG_FILTERSPEC> _filterSpecifications;

	std::string _filePath;

	//Did the user click ok?
	bool _success;
};

#endif
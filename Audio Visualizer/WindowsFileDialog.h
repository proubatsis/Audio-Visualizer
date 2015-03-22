/*
    Copyright (C) 2015 Panagiotis Roubatsis

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
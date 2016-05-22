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
	Description: An abstract class to represent an open file dialog.
*/

#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <string>

///
/// \brief File dialog for choosing a file.
/// Abstract class representing a file dialog.
/// There are different implementations depending on the OS.
///
class FileDialog
{
public:

	///
	/// \brief Open the dialog and display it.
	///
	virtual void openDialog() = 0;

	///
	/// \brief Return the path to the chosen file.
	/// \return Path to the chosen file
	///
	virtual std::string getFilePath() = 0;
	
	///
	/// \brief Return true if "Ok" was clicked, return false if "Cancel" was clicked.
	/// \return true if "Ok" was clicked, false if "Cancel" was clicked
	///
	virtual bool isFileChosen() = 0;
};

#endif
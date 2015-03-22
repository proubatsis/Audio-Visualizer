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
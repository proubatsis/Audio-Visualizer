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

	Description: This header contains two classes: RadioGroup and RadioButton.
	The RadioGroup is used to manage radio buttons, all instances of the RadioButton class
	must be assigned to an instance of the RadioGroup class. The RadioButton is a GUI element
	used to select items in a list, it is a child of the ButtonClass, no callbacks are needed.
*/

#ifndef RADIO_BUTTON
#define RADIO_BUTTON

#include "Button.h"
#include <vector>

namespace gui
{
	///
	/// \brief A group of radio buttons
	///
	class RadioGroup
	{
	public:
		///
		/// \brief Create a RadioGroup
		///
		RadioGroup() {}

		///
		/// \brief Create and add a RadioButton to the group
		/// \return id of the RadioButton
		///
		int add()
		{
			int id = _checkedStatus.size();
			_checkedStatus.push_back(false);
			return id;
		}

		///
		/// \brief Check the button with the given id
		///
		void check(int id)
		{
			for(size_t i = 0; i < _checkedStatus.size(); i++)
				_checkedStatus[i] = false;
			
			if(id >= 0 && id < (int)_checkedStatus.size()) _checkedStatus[id] = true;
		}

		//Returns the id that is checked, -1 if none are.

		///
		/// \brief Return the id of the radio button that is currently checked.
		/// \return id of the radio button that is currently checked
		int getCheckedId()
		{
			int id = -1;
			for(size_t i = 0; i < _checkedStatus.size(); i++)
				if(_checkedStatus[i]) id = i;
			return id;
		}


	private:
		std::vector<bool> _checkedStatus;
	};

	///
	/// \brief A radio button that can be placed on a form and chosen.
	/// A button that when clicked chooses a different item.
	///
	class RadioButton : public Button
	{
	public:
		///
		/// \brief Add a radio button to the form.
		/// \param text The text that should be displayed beside the radio button.
		/// \param x The x coordinate relative to the window.
		/// \param y The y coordinate relative to the window.
		/// \param group The RadioGroup that this radio button belongs to.
		/// \param theme The form's theme.
		/// \param window The window to render the radio button on.
		///
		RadioButton(std::string text, int x, int y, RadioGroup& group, Theme& theme, sf::RenderWindow* window);

		///
		/// \brief Check this radio button if the coordinates are within its bounds.
		///
		void click(int x, int y);

		void render();

	protected:
		int _groupID;			///< The RadioButton's id within its group
		RadioGroup& _group;		///< The RadioGroup that this belongs to
		sf::CircleShape _selectionCircle;	///< Used to render the radio button
	};

};

#endif
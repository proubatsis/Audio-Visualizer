#ifndef RADIO_BUTTON
#define RADIO_BUTTON

#include "Button.h"
#include <vector>

namespace gui
{

	class RadioGroup
	{
	public:
		RadioGroup() {}

		//Adds a radio button and returns it's id
		int add()
		{
			int id = _checkedStatus.size();
			_checkedStatus.push_back(false);
			return id;
		}

		//Unchecks all IDs and checks the identified one
		void check(int id)
		{
			for(int i = 0; i < _checkedStatus.size(); i++)
				_checkedStatus[i] = false;
			
			if(id >= 0 && id < _checkedStatus.size()) _checkedStatus[id] = true;
		}

		//Returns the id that is checked, -1 if none are.
		int getCheckedId()
		{
			int id = -1;
			for(int i = 0; i < _checkedStatus.size(); i++)
				if(_checkedStatus[i]) id = i;
			return id;
		}


	private:
		std::vector<bool> _checkedStatus;
	};

	class RadioButton : public Button
	{
	public:
		RadioButton(std::string text, int x, int y, RadioGroup& group, Theme& theme, sf::RenderWindow* window);

		void click(int x, int y);
		void render();

	protected:
		int _groupID;
		RadioGroup& _group;
		sf::CircleShape _selectionCircle;
	};

};

#endif
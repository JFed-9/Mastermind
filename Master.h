#include "stdafx.h"
#include <iostream>
	class consolewindow
	{
	public:
		//Set Color
		int getColor();
		void setColor();
		void setColor(std::string color);
		void setColor(std::string colorb, std::string colorf);
		void setColor(int reference);
		void safeInput (int &x);
		void safeInput (double &x);
		void safeInput (char &x);
		std::string commas(double num);
		std::string commas(int num);
		void toClipboard(std::string copy);
		consolewindow();
		int random(int begin, int end);
	protected:
		int reference;
	};

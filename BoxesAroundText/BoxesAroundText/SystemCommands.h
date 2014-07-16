#include <iostream>
#include "windows.h"

using namespace std;
class SystemCommands
{
private:
public:
	SystemCommands(){}

	void SetColor(int Color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
	}

	void SetLoc(short Col, short Row)
	{
		COORD Loc = { Col, Row };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Loc);
	}

	void AddLines(int NumOfLines)
	{
		int k;

		for (k = 0; k < NumOfLines; k++)
		{
			cout << "\n";
		}
	}

	void CenteredText(int Color, int Row, char *Text)
	{
		int LengthOfString;

		LengthOfString = strlen(Text);
		LengthOfString = (80 - LengthOfString) / 2;

		SetColor(Color);
		SetLoc(LengthOfString, Row);

		cout << Text;
	}
};
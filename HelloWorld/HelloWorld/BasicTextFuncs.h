#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BasicTextFuncs
{
	

private:

public:
	BasicTextFuncs(){}

	void ClearScreen()
	{
		system("cls");
	}

	void PauseScreen()
	{
		system("pause");
	}

	void AddSpaces(int Spaces)
	{
		int k;

		for (k = 0; k < Spaces; k++)
		{
			cout << " ";
		}
	}

	void AddLines(int Lines)
	{
		int k;

		for (k = 0; k < Lines; k++)
		{
			cout << "\n";
		}
	}

	void Center(char *Text)
	{
		int HorSpace;

		HorSpace = (80 - strlen(Text))/2;

		AddSpaces(HorSpace);
		cout << Text;
		AddLines(1);
	}

};
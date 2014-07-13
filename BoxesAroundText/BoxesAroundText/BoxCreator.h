#include "SystemCommands.h"

class BoxCreator
{
private:
	char TopLeft[2];
	char TopRight[2];
	char BotLeft[2];
	char BotRight[2];
	char Horiz[2];
	char Vert[2];
	SystemCommands Control;


public:
	BoxCreator(){}

	void SetPos(short Col, short Row)
	{
		COORD Loc = { Col, Row };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Loc);
	}

	void SetColor(int Color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
	}

	void CreateBox(int Color, int Row, int Col, char *Text)
	{
		int k;
		int VertSpace;
		int HorizSpace;
		int Width;
		int Length;

		VertSpace = 2;
		HorizSpace = 5;
		Width = 2 * HorizSpace + strlen(Text);
		Length = 2 * VertSpace + 1;

		TopLeft[0] = 218;
		TopRight[0] = 191;
		BotLeft[0] = 192;
		BotRight[0] = 217;
		Horiz[0] = 196;
		Vert[0] = 179;

		TopLeft[1] = '\0';
		TopRight[1] = '\0';
		BotLeft[1] = '\0';
		BotRight[1] = '\0';
		Horiz[1] = '\0';
		Vert[1] = '\0';

		if (Row < 9)
		{
			Control.CenteredText(1, 9, "Increase the row by at least: ");
			cout << 9 - Row;
		}

		if (Row > 8 && Row + Length + 1 < 45)
		{
			SetColor(Color);
			SetPos(Col, Row);
			cout << TopLeft;

			SetPos(Col + Width + 1, Row);
			cout << TopRight;
			SetPos(Col, Row + Length + 1);
			cout << BotLeft;
			SetPos(Col + Width + 1, Row + Length + 1);
			cout << BotRight;
			SetPos(Col + HorizSpace + 1, Row + VertSpace + 1);
			cout << Text;

			for (k = 0; k < Length; k++)
			{
				SetPos(Col, Row + k + 1);
				cout << Vert;

				SetPos(Col + Width + 1, Row + k + 1);
				cout << Vert;
			}

			for (k = 0; k < Width; k++)
			{
				SetPos(Col + k + 1, Row);
				cout << Horiz;

				SetPos(Col + k + 1, Row + Length + 1);
				cout << Horiz;
			}

			if (Row + Length + 1 > 44)
			{
				Control.CenteredText(1, 9, "Decrease your row by at least: ");
				cout << Row + Length + 1 - 44;

			}
		}	
	}
};
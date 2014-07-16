#include "BoxCreator.h"

int main()
{
	BoxCreator Boxes;

	int k;
	int color;
	color = 0;

	for (k = 0; k < 50; k++)
	{
		Boxes.CreateBox(color, k+9, k, "");
		color++;
		if (color > 10)
		{
			color = 0;
		}
	}
	cout << "\n";
	return 0;
};
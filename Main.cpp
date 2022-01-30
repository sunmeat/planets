#include "CircleInRectangle.h"
#include "FilledRectangle.h"
#include <iostream>
using namespace std;

void animation();

int main()
{
	system("title Solar System");

	Circle a;
	a.Draw();

	MyRectangle b;
	b.Draw();

	CircleInMyRectangle c(150, 150, 50, RGB(0, 0, 255));
	c.Draw();
	c.MoveTo(250, 50);
	c.Draw();

	animation();
}

void animation()
{
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(h, &cci);
	MoveWindow(GetConsoleWindow(), 0, 0, 1000, 1000, true);

	FilledRect global(0, 0, 900, 900);
	global.SetColor(Figure::BLACK);

	Circle sun(300, 300, 100);
	sun.SetShapeColor(Figure::YELLOW);

	Circle earth(0, 0, 25);
	earth.SetShapeColor(Figure::BLUE);

	double radius_e = 150, radius_m = 250, X = 300, Y = 300;
	int grad_e = 0, grad_m = 180;

	Circle mars(0, 0, 15);

	while (true)
	{
		global.Draw();
		sun.Draw();
		double rad = grad_e * 3.14 / 180;
		earth.MoveTo(radius_e * cos(rad) + X - earth.GetHeight() / 2,
			radius_e * sin(rad) + Y - earth.GetHeight() / 2);
		earth.Draw();
		rad = grad_m * 3.14 / 180;
		mars.MoveTo(radius_m * cos(rad) + X - mars.GetHeight() / 2,
			radius_m * sin(rad) + Y - mars.GetHeight() / 2);
		mars.Draw();
		grad_e += 10, grad_m -= 5;
		if (grad_e == 360)
			grad_e = 0;
		if (grad_m == 0)
			grad_m = 360;
		Sleep(40);
	}
}
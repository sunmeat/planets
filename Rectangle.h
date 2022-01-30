#pragma once
#include "Figure.h"

class MyRectangle : public virtual Figure
{
public:
	MyRectangle(int X, int Y, int width, int height, COLORREF c = RGB(255, 0, 0))
		: Figure(X, Y, width, height, c) {}

	MyRectangle() : Figure(50, 50, 50, 50, RGB(255, 0, 0)) {}

	void Draw()
	{
		SetPen(color);
		MoveToEx(hdc, tl.GetX(), tl.GetY(), NULL);
		LineTo(hdc, tl.GetX() + width, tl.GetY());
		LineTo(hdc, tl.GetX() + width, tl.GetY() + height);
		LineTo(hdc, tl.GetX(), tl.GetY() + height);
		LineTo(hdc, tl.GetX(), tl.GetY());
	}
};
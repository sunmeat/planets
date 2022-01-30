
#include "Rectangle.h"

class FilledRect :public MyRectangle
{
public:
	FilledRect(int X, int Y, int width, int height, COLORREF c = RGB(255, 0, 0)) :Figure(X, Y, width, height, c) {}

	void Draw()
	{
		SetBrush(color);
		SetPen(color, 1);
		Rectangle(hdc, tl.GetX(), tl.GetY(), tl.GetX() + width, tl.GetY() + height);
	}
};
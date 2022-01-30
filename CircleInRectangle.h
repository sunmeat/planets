#include "Circle.h"
#include "Rectangle.h"

class CircleInMyRectangle : public MyRectangle, public Circle
{
public:
	CircleInMyRectangle(int center_X, int center_Y, int radius, COLORREF c = RGB(255, 0, 0)) :
		Figure(center_X - radius, center_Y - radius, radius * 2, radius * 2, c)
	{
		SetShapeColor(c);
	}

	void Draw()
	{
		Circle::Draw();
		MyRectangle::Draw();
	}
};
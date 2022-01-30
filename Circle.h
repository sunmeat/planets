#include "Figure.h"

class Circle : public virtual Figure
{
protected:
	COLORREF color;

public:
	Circle(int center_X, int center_Y, int radius, COLORREF color = RGB(255, 0, 0))
		: Figure(center_X - radius, center_Y - radius, radius * 2, radius * 2)
	{
		this->color = color;
	}

	Circle() : Figure(200, 200, 50, 50)
	{
		color = RGB(255, 0, 0);
	}

	COLORREF GetShapeColor() const
	{
		return color;
	}

	void SetShapeColor(COLORREF color)
	{
		this->color = color;
	}

	void SetShapeColor(unsigned char red, unsigned char green, unsigned char blue)
	{
		color = RGB(red, green, blue);
	}

	void SetShapeColor(SHAPE_COLOR c)
	{
		color = SHAPECOLOR_to_COLORREF(c);
	}

	void Draw()
	{
		SetPen(0, 0);
		SetBrush(color);
		Ellipse(hdc, tl.GetX(), tl.GetY(), tl.GetX() + width, tl.GetY() + height);
	}
};
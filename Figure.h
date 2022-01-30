#pragma once
#include "Point.h"
#include <Windows.h>

class Figure
{
protected:
	static HDC hdc;

	void SetPen(COLORREF c, int width = 3)
	{
		SelectObject(hdc, CreatePen(PS_SOLID, width, c));
	}

	void SetBrush(COLORREF c)
	{
		SelectObject(hdc, CreateSolidBrush(c));
	}

public:
	enum SHAPE_COLOR { BLACK, RED, GREEN, BLUE, WHITE, YELLOW, NONE };

protected:
	Point tl;
	unsigned short width;
	unsigned short height;
	COLORREF color;

	COLORREF SHAPECOLOR_to_COLORREF(SHAPE_COLOR c)
	{
		switch (c)
		{
		case BLACK:
			return RGB(0, 0, 0);
		case RED:
			return RGB(255, 0, 0);
		case GREEN:
			return RGB(0, 255, 0);
		case BLUE:
			return RGB(0, 0, 255);
		case WHITE:
			return RGB(255, 255, 255);
		case YELLOW:
			return RGB(255, 255, 0);
		case NONE:
			return 0;
		}
	}

public:
	Figure()
	{
		color = RGB(255, 255, 255);
	}

	Figure(int X, int Y, unsigned short _width, unsigned short _height, COLORREF c = RGB(255, 0, 0)) :tl(X, Y)
	{
		width = _width;
		height = _height;
		color = c;
	}

	const Point& GetPointTopleft() const
	{
		return tl;
	}

	unsigned short GetWidth() const
	{
		return width;
	}

	unsigned short GetHeight() const
	{
		return height;
	}

	COLORREF GetColor() const
	{
		return color;
	}

	void SetPointTopLeft(const Point& p)
	{
		tl = p;
	}

	void SetWidth(unsigned short value)
	{
		width = value;
	}

	void SetHeight(unsigned short value)
	{
		height = value;
	}

	void SetColor(COLORREF color)
	{
		this->color = color;
	}

	void SetColor(unsigned char red, unsigned char green, unsigned char blue)
	{
		color = RGB(red, green, blue);
	}

	void SetColor(SHAPE_COLOR c)
	{
		color = SHAPECOLOR_to_COLORREF(c);
	}

	void MoveTo(int X, int Y)
	{
		tl = { X, Y };
	}
};

HDC Figure::hdc = GetDC(GetConsoleWindow());

class Point
{
	int X;
	int Y;

public:
	Point()
	{
		X = Y = 0;
	}

	Point(int x, int y)
	{
		X = x;
		Y = y;
	}

	Point(const Point& other)
	{
		X = other.X;
		Y = other.Y;
	}

	int GetX() const
	{
		return X;
	}

	int GetY() const
	{
		return Y;
	}

	void SetX(unsigned int value)
	{
		X = value;
	}

	void SetY(unsigned int value)
	{
		Y = value;
	}
};

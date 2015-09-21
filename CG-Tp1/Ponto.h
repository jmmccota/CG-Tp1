#pragma once
class Ponto
{
protected:
	friend std::ostream& operator<<(std::ostream&, const Ponto&);
	float x, y;
public:

	Ponto()
	{
	}

	Ponto(float _x, float _y) {
		x = _x;
		y = _y;
	}

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	float setX(float _x) {
		x = _x;
	}

	float setY(float _y) {
		y = _y;
	}
	~Ponto()
	{
		/*delete &x;
		delete &y;*/
	}

};
std::ostream& operator<<(std::ostream &strm, const Ponto &a) {
	return strm << "Ponto(" << a.x << ", " << a.y << ")";
}

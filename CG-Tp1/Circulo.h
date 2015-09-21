#pragma once
#include "Ponto.h"
class Circulo :
	public Ponto
{
private:
	friend std::ostream& operator<<(std::ostream&, const Circulo&);
	float raio;
public:

	Circulo()
	{
	}

	Circulo(float _x, float _y, float _r) :Ponto(_x, _y)
	{
		raio = _r;
	}
	float getRaio() {
		return raio;
	}
	void setRaio(float _r) {
		raio = _r;
	}
	~Circulo()
	{
	}
};

std::ostream& operator<<(std::ostream &strm, const Circulo &a) {
	return strm << "Circulo(" << a.x << ", " << a.y << ", " << a.raio << ")";
}

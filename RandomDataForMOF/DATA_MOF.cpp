#include "DATA_MOF.h"
void DATA_FOR_MOF::startRand(int N, double x0, double y0, double r) {
	P.setN(N);
	P.setRandomPoints(x0, y0, r);
	double sqr = P.square(); // площадь
	do {
		vcon1 = (double)(rand()) / RAND_MAX * (sqr); // рандомная объемная доля 1-го вещества [0.1;sqr]
		vcon2 = sqr - vcon1; // оставшийся объем занимает второе вещество
	} while ((sqr - vcon1) <= 0 || (vcon1) < 1e-2 || (vcon2) < 1e-2);
	c1 = P.getRandomCentroid();
	c2 = P.getRandomCentroid();
}
ostream& operator << (ostream& os, const DATA_FOR_MOF& M) {
	os << M.P; //<< endl;
	os << M.c1 << " " << M.c2;// << endl;
	os << M.vcon1 << " " << M.vcon2;// << endl;
	return os;
}
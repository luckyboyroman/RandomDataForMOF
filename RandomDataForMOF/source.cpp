#include "Polygon.h"
#include "DATA_MOF.h"
#include <fstream>
double random(double min, double max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}
int main()
{
	//srand(time(NULL));

	const int examples = 1000;
	cout << examples << endl;
	//Polygon P;
	//P.setN(4);
	//Point p0(4, 2);
	//vector <Point> v1(4);
	//v1[0].set(0, 0);
	//v1[1].set(8, 0);
	//v1[2].set(6, 4);
	//v1[3].set(2, 4);
	//P.setPoints(p0, v1);
	//cout << P.square() << endl;

	ofstream fout("input_RandomDataMoF.txt");
	fout << examples << endl;
	DATA_FOR_MOF* data = new DATA_FOR_MOF[examples];
	for (int i = 0; i < examples; i++) {
		// генерируем данные
		data[i].startRand(4, random(0, 10), random(2, 10), random(0.3, 0.6));
		fout << data[i] << endl;
	}
	fout.close();
}

#include "newtonMethod.h";

void main() 
{

	int n;
	cout << "Number of equations: ";
	cin >> n;

	double x0 = 1, y0 = 0;
	cout << setw(15) << "Iteration" << setw(15) << "Delta 1" << setw(15) << "Delta 2\n";
	newtonMethod(x0, y0, n);
	
}
﻿#include "newtonMethod.h"
#include "Gauss.h"

void main() 
{

	int n=2;
	double x0 = 1, y0 = 0;
	cout << setw(15) << "Iteration" << setw(15) << "Delta 1" << setw(15) << "Delta 2\n";
	newtonMethod(x0, y0, n, Jac(x0,y0,n));
	vector<double> M{0.01, 0.05, 0.1};
	for (int i = 0; i < M.size(); i++)
	{
		cout << endl;
			cout << "\nM[" << i + 1 << "] = " << M[i];
		if (x0 == 0 || y0 == 0)
			cout << "\nJac cannot be counted";
		else
		{
			
			cout << endl << setw(15) << "Iteration" << setw(15) << "Delta 1" << setw(15) << "Delta 2\n";
			newtonMethod(x0, y0, n, Jac(x0, y0, n, M[i]));
		}
	}


	
}
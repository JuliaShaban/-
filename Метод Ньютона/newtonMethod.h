#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void newtonMethod(double x1, double x2, int n, bool b, double M);
vector<vector<double>> Jac2(double x1, double x2, int n, double M);
vector<vector<double>> Jac1(double x1, double x2, int n);


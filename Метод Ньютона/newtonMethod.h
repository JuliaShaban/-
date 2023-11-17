#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void newtonMethod(double x1, double x2, int n, vector<vector<double>> Jac);
vector<vector<double>> Jac(double x1, double x2, int n, double M);
vector<vector<double>> Jac(double x1, double x2, int n);


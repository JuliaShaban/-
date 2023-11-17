#pragma once
#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix);
void gaussMetod(vector<vector<double>>& matrix);
void vectorNev(const vector<vector<double>>& A, vector<double>& B, const vector<vector<double>>& matrix);

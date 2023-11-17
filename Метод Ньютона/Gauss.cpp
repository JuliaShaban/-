#include"Gauss.h"


void printMatrix(const vector<vector<double>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void gaussMetod(vector<vector<double>>& matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        int elem = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(matrix[j][i]) > abs(matrix[elem][i]))
            {
                elem = j;
            }
        }

        if (elem != i)
        {
            swap(matrix[i], matrix[elem]);
        }

        double KoffDel = matrix[i][i];

        for (int j = i; j < n + 1; j++)
        {
            matrix[i][j] /= KoffDel;
        }


        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                double Koffmult = matrix[j][i];
                for (int k = i; k < n + 1; k++)
                {
                    matrix[j][k] -= Koffmult * matrix[i][k];
                }
            }
        }
    }
}
void vectorNev(const vector<vector<double>>& A, vector<double>& B, const vector<vector<double>>& matrix)
{
    int n = matrix.size();
    vector<double> residualVector(n, 0);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            B[i] += A[i][j] * matrix[j][n];
        }
        residualVector[i] -= B[i];
    }
    cout << "Vec nev:" << endl;
    double vecNev = 0.0;

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i + 1 << "] = " << B[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        vecNev = max(vecNev, abs(B[i]));
    }
    cout << "Norm =" << vecNev << endl;
}

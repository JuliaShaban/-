#include "newtonMethod.h";
#include "Gauss.h"

double f1(double x1, double x2)
{
    return sin(x1) - x2 - 1.32;
}

double f2(double x1, double x2)
{
    return cos(x2) - x1 + 0.85;
}

double diffF1x1(double x1, double x2 )
{
    return cos(x1);
}

double diffF1x2(double x1, double x2)
{
    return -1;
}

double diffF2x1(double x1, double x2)
{
    return -1;
}

double diffF2x2(double x1, double x2)
{
    return -sin(x2);
}

double maximum(double x1, double x2)
{
    return abs((x1 > x2) ? x1 : x2);
}
vector<vector<double>> Jac1(double x1, double x2, int n)
{
    vector<double> x(n);
    x[0] = x1;
    x[1] = x2;
    vector<vector<double>> jac(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == 0) jac[i][j] = (j == 0) ? diffF1x1(x[0], x[1]) : diffF1x2(x[0],x[1]);
            else jac[i][j] = (j == 0) ? diffF2x1(x[0], x[1]) : diffF2x2(x[0], x[1]);
    return jac;
}
vector<vector<double>> Jac2(double x1, double x2, int n, double M)
{
    vector<double> x(n);
    x[0] = x1;
    x[1] = x2;
    vector<vector<double>> jac(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == 0) jac[i][j] = (j == 0) ? (f1(x[0] + M * x[0], x[1]) - f1(x[0], x[1])) / M * x[0] : (f1(x[0], x[1] + M * x[1]) - f1(x[0], x[1])) / M * x[1];
            else jac[i][j] = (j == 0) ? (f2(x[0] + M * x[0], x[1]) - f2(x[0], x[1])) / M * x[0] : (f2(x[0], x[1] + M * x[1]) - f2(x[0], x[1])) / M * x[1];

    return jac;
}

double maximum(vector<double>& x,vector<vector<double>>& matrix)
{
    int n = matrix.size();
    double max = 0;
    for (int i = 0; i < n; i++)
        if (abs(x[i] + matrix[i][n]) < 1)
        {
            if (max < abs(matrix[i][n]))
                max = abs(matrix[i][n]);
        }
        else if (max < abs(matrix[i][n] / (x[i] + matrix[i][n])))
            max = abs(matrix[i][n] / (x[i] + matrix[i][n]));
    return max;
}
void newtonMethod(double x1, double x2, int n, bool b, double M)
{
    const int nit = 100;
    const double e1 = 1e-9, e2 = e1;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    vector<vector<double>> jac(n, vector<double>(n));
    vector<double> F(n);
    vector<double> x(n);


    double d1 = 1, d2 = 1;
    x[0] = x1;
    x[1] = x2;
    int k = 1;
    
    while (d1 > e1 || d2 > e2)
    {
        if (k > nit)
        {
            cout << "\nIER = 2";
            break;
        }
        F[0] = -f1(x[0], x[1]);
        F[1] = -f2(x[0], x[1]);
        
        if (b)
        jac = Jac1(x[0],x[1],n);
        else
            jac = Jac2(x[0], x[1], n, M);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j]=jac[i][j];
            }
            matrix[i][n] = F[i];
        }
        gaussMetod(matrix);
        d1 = maximum(f1(x[0], x[1]), f2(x[0], x[1]));
        d2 = maximum(x, matrix);
        for (int i = 0; i < n; i++)
            x[i] += matrix[i][n];
        cout << setw(15) << k << setw(15) << d1 << setw(15) << d2 << endl;
        k++;
    }
    cout << "\nAnswer: (" << x[0] << "; " << x[1] << ")";
}

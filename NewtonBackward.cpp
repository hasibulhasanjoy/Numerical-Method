#include <bits/stdc++.h>
using namespace std;
double u_cal(double u, int n)
{
    double temp = u;
    for (int i = 1; i < n; i++)
    {
        temp *= (u + i);
    }
    return temp;
}
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n = 5;
    float x[] = {1891, 1901, 1911, 1921, 1931};
    float y[n][n];
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Displaying the backward difference table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
    double value = 1925;
    double sum = y[n - 1][0];
    double u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum += (u_cal(u, i) * y[n - i][i]) / fact(i);
    }
    cout << sum << endl;
    return 0;
}
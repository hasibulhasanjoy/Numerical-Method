#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define f(x) 2 * x *x + x *x - 1
#define g(x) 1 / sqrt(1 + x)
#define iteration 1e5
#define tolerance 0.00001
const int lb = -1000;
const int ub = 1000;

class FixedPointIteration
{
public:
    void solve()
    {
        double a, b;
        double x = 0, x1;
        // cout << x << endl;
        for (int i = 0; i < 10; i++)
        {
            // cout << x << " ";
            x1 = g(x);
            if (abs(x - x1) < tolerance)
            {
                break;
            }
            x = x1;
        }
        cout << "root of the equation is : " << x << endl;
    }
};

int main()
{
    FixedPointIteration it;
    it.solve();
    return 0;
}
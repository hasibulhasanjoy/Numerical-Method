#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define f(x) x *x *x + x - 1
#define tolerance 0.0001
const int ub = 1000;
const int lb = -1000;

class Secant
{
public:
    void solve()
    {
        double x1, x2, root;
        x1 = 12;
        x2 = -12;
        while (abs(x1 - x2) > tolerance)
        {
            root = ((x1 * f(x2) - x2 * f(x1))) / (f(x2) - f(x1));
            if (f(root) == 0)
            {
                break;
            }
            x1 = x2;
            x2 = root;
        }
        cout << "Root of the equation is : " << root << endl;
    }
};

int main()
{
    cout << fixed << setprecision(4);
    Secant s;
    s.solve();
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;
#define f(x) x *x *x - 2 * x - 5
#define epsilon 0.001
const int ub = 1000;
const int lb = -1000;

class Bisection
{
public:
    void solve()
    {
        double a, b;
        do
        {
            a = (rand() % (ub - lb + 1)) + lb;
        } while (f(a) > 0);
        do
        {
            b = (rand() % (ub - lb + 1)) + lb;
        } while (f(b) < 0);
        double root;
        while ((b - a) >= epsilon)
        {
            root = (a + b) / 2;
            if (f(root) == 0)
            {
                break;
            }
            else if (f(root) > 0)
            {
                b = root;
            }
            else
            {
                a = root;
            }
        }
        cout << "Root of the equation is : " << root << endl;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    cout << fixed << setprecision(4);
    Bisection b;
    b.solve();
    return 0;
}
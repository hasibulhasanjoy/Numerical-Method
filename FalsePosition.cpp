#include <iostream>
#include <iomanip>
using namespace std;
#define f(x) x *x *x - 2 * x + 7
#define iteration 1e5
const int lb = -1000;
const int ub = 1000;

class FalsePosition
{
private:
    double calculateC(double a, double b)
    {
        return (a * f(b) - b * f(a)) / (f(b) - f(a));
    }

public:
    double a, b;
    void solve()
    {
        do
        {
            a = (rand() % (ub - lb + 1)) + lb;
        } while (f(a) > 0);
        do
        {
            b = (rand() % (ub - lb + 1)) + lb;
        } while (f(b) < 0);
        double c;
        for (int i = 0; i < iteration; i++)
        {
            c = calculateC(a, b);
            if (f(c) == 0)
            {
                break;
            }
            else if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        cout << "Root of the equation is : " << c << endl;
    }
};

int main()
{
    cout << fixed << setprecision(4);
    FalsePosition f;
    f.solve();
    return 0;
}
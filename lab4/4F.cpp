#include <iostream>
#include <iomanip>

using namespace std;

int length = 0;
int n;
double A;
double last;

double garlandcheck(double a2) {
    double prev = A;
    double cur = a2;
    double min = a2;
    for (int i = 2; i < n; i++) {
        double t = 2 * cur - prev + 2;
        prev = cur;
        cur = t;
        if (cur < min)
            min = cur;
    }
    last = cur;
    return min;
}

double binSearch() {
    double x = A/2;
    double step = A/2;
    while (step>0.00000000000001) {
        step /= 2;
        double check = garlandcheck(x);
        if (check < 0)
            x += step;
        else if (check > 0)
            x -= step;
        else
            break;
    }
    return x;
}


int main()
{
    //freopen("garland.in", "r", stdin);
    //freopen("garland.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> A;
    binSearch();
    cout << fixed;
    cout << setprecision(2);
    cout << last;
    return 0;
}
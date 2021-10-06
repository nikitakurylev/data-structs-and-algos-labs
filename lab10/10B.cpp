#include <iostream>
#include <iomanip>
#include <cmath>
#pragma warning(disable : 4996)

using namespace std;

double posx[5000];
double posy[5000];
double priorities[5000];
int connection[5000]{ -1 };
bool connected[5000];

int main()
{
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> posx[i] >> posy[i];
        priorities[i] = 1000000000000000;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    priorities[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int min = -1;
        for (int j = 0; j < n; j++)
            if (!connected[j] && (min == -1 || priorities[j] < priorities[min]))
                min = j;
        connected[min] = true;
        for (int j = 0; j < n; j++)
            if (j != min && !connected[j])
            {
                double dist = sqrt(pow(posx[min] - posx[j], 2) + pow(posy[min] - posy[j], 2));
                if (dist < priorities[j]) {
                    priorities[j] = dist;
                    connection[j] = min;
                }
            }
    }

    double weight = 0;
    for (int i = 0; i < n; i++)
        weight += priorities[i];
    cout << fixed << setprecision(20) << weight;
    return 0;
}
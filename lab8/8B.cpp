#include <iostream>
#pragma warning(disable : 4996)

using namespace std;
int graph[100][100];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
        cin >> graph[i / n][i % n];
    for (int i = 0; i < n * n; i++)
        if ((graph[i / n][i % n] == 0 && graph[i % n][i / n] == 1) || (i % n == i / n && graph[i / n][i % n] == 1)) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
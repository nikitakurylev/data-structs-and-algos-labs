#include <iostream>
#pragma warning(disable : 4996)

using namespace std;
int graph[100][100];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] += 1;
    }
    for (int i = 0; i < n * n; i++) 
        if ((graph[i / n][i % n] == 1 && graph[i % n][i / n] == 1 || graph[i % n][i / n] > 1) && i / n != i % n) {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}
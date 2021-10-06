#include <iostream>
#include <vector>
#include <list>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[100000];

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
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++)
        cout << graph[i].size() << " ";
    return 0;
}
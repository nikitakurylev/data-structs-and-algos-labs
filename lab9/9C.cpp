#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[100000];
int color[100000];

int main()
{
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    queue<int> bfsQueue;
    for (int i = 0; i < n; i++) 
        if (color[i] == 0) {
            bfsQueue.push(i);
            color[i] = 1;
            while (!bfsQueue.empty()) {
                for (int j = 0; j < graph[bfsQueue.front()].size(); j++) {
                    int child = graph[bfsQueue.front()][j];
                    if (color[child] == 0) {
                        bfsQueue.push(child);
                        color[child] = 1 + (color[bfsQueue.front()]) % 2;
                    }
                    else if (color[child] == color[bfsQueue.front()]) {
                        cout << "NO";
                        return 0;
                    }
                }
                bfsQueue.pop();
            }
        }
    cout << "YES";
    return 0;
}
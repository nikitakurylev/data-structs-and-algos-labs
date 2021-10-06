#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[100000];
int graphClass[100000];

int main()
{
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
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
    int currentClass = 0;
    for (int i = 0; i < n; i++) {
        if (graphClass[i] == 0) {
            bfsQueue.push(i);
            currentClass++;
        }
        while (!bfsQueue.empty()) {
            if (graphClass[bfsQueue.front()]==0) {
                int tempClass = currentClass;
                for (int j = 0; j < graph[bfsQueue.front()].size(); j++)
                    bfsQueue.push(graph[bfsQueue.front()][j]);
                graphClass[bfsQueue.front()] = tempClass;
            }
            bfsQueue.pop();
        }
    }
    cout << currentClass << "\n";
    for (int i = 0; i < n; i++)
        cout << graphClass[i] << " ";
    return 0;
}
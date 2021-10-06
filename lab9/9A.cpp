#include <iostream>
#include <vector>
#include <list>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[100000];
bool visited[100000];
int color[100000];
vector<int> sortedNodes;

bool checkCycle(int currentNode) {
    if (color[currentNode] == 0) {
        color[currentNode] = 1;
        for (int i = 0; i < graph[currentNode].size(); i++)
            if (checkCycle(graph[currentNode][i]))
                return true;
        color[currentNode] = 2;
        return false;
    }
    else if (color[currentNode] == 1)
        return true;
    else
        return false;
}

void dfs(int currentNode) {
    if (!visited[currentNode]) {
        visited[currentNode] = true;
        for (int i = 0; i < graph[currentNode].size(); i++)
            dfs(graph[currentNode][i]);
        sortedNodes.push_back(currentNode + 1);
    }
}

int main()
{
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0) {
            if (checkCycle(i)) {
                cout << "-1";
                return 0;
            }
        }

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);
    for (int i = sortedNodes.size()-1; i >=0; i--)
        cout << sortedNodes[i] << " ";
    return 0;
}
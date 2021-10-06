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

int checkCycle(int currentNode) {
    if (color[currentNode] == 0) {
        color[currentNode] = 1;
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int result = checkCycle(graph[currentNode][i]);
            if (result == -2)
                return -2;
            else if (result != -1) {
                sortedNodes.push_back(currentNode);
                if (currentNode == result)
                    return -2;
                else
                    return result;
            }
        }
        color[currentNode] = 2;
        return -1;
    }
    else if (color[currentNode] == 1) {
        return currentNode;
    }
    else
        return -1;
}

int main()
{
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
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
            if (checkCycle(i) != -1){
                cout << "YES\n";
                for (int i = sortedNodes.size() - 1; i >= 0; i--)
                    cout << (sortedNodes[i] + 1) << " ";
                return 0;
            }
        }

    cout << "NO";
    return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable : 4996)

#define edge pair<int, pair<int, int>>

using namespace std;



vector<edge> edges;
vector<int> weights[1000];

int dfs(int currentNode, const vector<edge> &edges, vector<bool> &visited) {
    int result = 1;
    visited[currentNode] = true;
    for (const edge &e : edges)
        if (e.second.first == currentNode && !visited[e.second.second])
            result += dfs(e.second.second, edges, visited);
    return result;
}

int findMST(int n, int root) {
    int result = 0;
    vector<int> minEdge(n);
    for (const edge &e : edges)
        minEdge[e.second.second] = min(e.first, minEdge[e.second.second]);
    for (int i = 0; i < n; i++)
        if (i != root)
            result += minEdge[i];
    vector<edge> zeroEdges;
    for (edge& e : edges) {
        if (e.first == minEdge[e.second.second])
            zeroEdges.push_back(make_pair(0, e.second));
    }
    vector<bool> visited(n);
    if (dfs(root, zeroEdges, visited) == n)
        return result;
    return result;
    vector<int> newComponents(n);

}

int main()
{
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        edges.push_back(make_pair(w, make_pair(a - 1, b - 1)));
    }
    vector<bool> visited(n);
    if (n != dfs(0, edges, visited)) {
        cout << "NO";
        return 0;
    }
    cout << "YES";


    return 0;
}
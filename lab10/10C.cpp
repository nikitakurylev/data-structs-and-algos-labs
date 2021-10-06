#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

bool comp(pair<int, pair<int, int>> i, pair<int, pair<int, int>> j) { return (i.first < j.first); }

vector<int> tree;
vector<int> treecount;

void union_set(int a, int b) {
    if (treecount[b] > treecount[a]) {
        tree[a] = tree[b];
        treecount[b] += treecount[a];
        treecount[a] = 0;
    }
    else {
        tree[b] = tree[a];
        treecount[a] += treecount[b];
        treecount[b] = 0;
    }
}
int union_get(int a) {
    if (a == tree[a])
        return a;
    else
        return union_get(tree[a]);
}

vector<pair<int, pair<int, int>>> edges;
int main()
{
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        edges.push_back(make_pair(w, make_pair(a - 1, b - 1)));
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        tree.push_back(i);
        treecount.push_back(1);
    }

    sort(edges.begin(), edges.end());
    long long weight = 0;
    for (int i = 0; i < m; i++)
    {
        int a = union_get(edges[i].second.first), b = union_get(edges[i].second.second), w = edges[i].first;
        if (tree[a] != tree[b])
        {
            weight += w;
            union_set(a, b);
        }
    }


    cout << weight;
    return 0;
}
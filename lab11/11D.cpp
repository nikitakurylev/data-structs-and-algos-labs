#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)
#define INF 2000000000000000000

struct edge {
    long long a, b;
    long long w;
};

using namespace std;
vector<edge> graph;
vector<long long> dist;
vector<long long> parent;
int x;
void Relax(edge e) {
    if (dist[e.b] > dist[e.a] + e.w) {
        dist[e.b] = max(-INF, dist[e.a] + e.w);
        parent[e.b] = e.a;
        x = e.b;
    }
}

int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, s, m;
    cin >> n >> m >> s;
    s--;
    dist = vector<long long>(n, INF);
    parent = vector<long long>(n, -1);
    graph = vector<edge>(m);
    for (long long i = 0; i < m; i++) {
        cin >> graph[i].a >> graph[i].b >> graph[i].w;
        graph[i].a--;
        graph[i].b--;
    }
    dist[s] = 0;
    vector<int> needcorrect;
    for (long long i = 0; i < n; i++) {
        x = -1;
        for (long long j = 0; j < m; j++) {
            int tmp = x;
            if (dist[graph[j].a] < INF)
                Relax(graph[j]);
            if (i == n - 1 && tmp != x)
                needcorrect.push_back(x);
        }
    }

    while (!needcorrect.empty())
    {
        int y = needcorrect.back();
        needcorrect.pop_back();
        for (int i = 0; i < n; i++) {
            dist[y] = -INF;
            y = parent[y];
        }
    }

    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < m; j++)
            if (dist[graph[j].a] == -INF)
                dist[graph[j].b] = -INF;
    for (long long i = 0; i < n; i++) {
        if (dist[i] == -INF)
            cout << "-" << "\n";
        else if (dist[i] < INF)
            cout << dist[i] << "\n";
        else
            cout << "*" << "\n";
    }
    return 0;
}
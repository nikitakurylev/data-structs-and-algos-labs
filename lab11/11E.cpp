#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)
#define INF 9000000000000000000

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
	freopen("negcycle.in", "r", stdin);
	freopen("negcycle.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, s = 0, m = 0;
	cin >> n;
	dist = vector<long long>(n, 0);
	parent = vector<long long>(n, -1);
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < n; j++) {
			edge e;
			cin >> e.w;
			if (abs(e.w) <= 10000) {
				e.a = i;
				e.b = j;
				graph.push_back(e);
				m++;
			}
		}
	dist[s] = 0;
	for (long long i = 0; i < n; i++) {
		x = -1;
		for (long long j = 0; j < m; j++)
			if (dist[graph[j].a] < INF)
				Relax(graph[j]);
	}

	if (x != -1) {
		int y = x;
		for (int i = 0; i < n; i++) {
			y = parent[y];
		}
		vector<int> path;
		for (int cur = y; ; cur = parent[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1)  
				break;
		}

		cout << "YES\n" << path.size() << "\n";
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] + 1 << ' ';
		return 0;
	}
	cout << "NO";
	return 0;
}
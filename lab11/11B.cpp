#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
int graph[2000][2000];
long long dist[2000];
long long parent[2000];

void Relax(int i, int j) {
	if (dist[j] > dist[i] + graph[i][j] && dist[i] < INT64_MAX) {
		dist[j] = dist[i] + graph[i][j];
		parent[j] = i;
	}
}

int main()
{
	freopen("pathsg.in", "r", stdin);
	freopen("pathsg.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> dist(n, vector<long long>(n, INT64_MAX));

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u-1][v-1] = w;
	}

	for (int i = 0; i < n; i++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				if (dist[u][i] + dist[i][v] < dist[u][v] && dist[u][i] != INT64_MAX && dist[i][v] != INT64_MAX)
					dist[u][v] = dist[u][i] + dist[i][v];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == j)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
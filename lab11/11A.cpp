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
	freopen("pathmgep.in", "r", stdin);
	freopen("pathmgep.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	vector<int> notready;
	vector<int> ready;

	for (int i = 0; i < n; i++) {
		dist[i] = INT64_MAX;
		parent[i] = -1;
		notready.push_back(i);
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}
	dist[s] = 0;
	while (!notready.empty()) {
		int minv = 0;
		for (int i = 1; i < notready.size(); i++)
			if (dist[notready[minv]] > dist[notready[i]])
				minv = i;
		int u = notready[minv];
		notready.erase(notready.begin() + minv);
		ready.push_back(u);
		for (int v = 0; v < n; v++)
			if(graph[u][v] != -1)
				Relax(u, v);
	}
	if (dist[f] < INT64_MAX)
		cout << dist[f];
	else
		cout << -1;
	return 0;
}
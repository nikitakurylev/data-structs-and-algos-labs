#include <iostream>
#include <vector>
#include <set>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("pathbgep.in", "r", stdin);
	freopen("pathbgep.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> notready;
	vector<int> ready;

	int n, m, s = 0;
	cin >> n >> m;
	vector < vector < pair<int, int> > > graph(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a-1].push_back(make_pair(b-1, w));
		graph[b-1].push_back(make_pair(a-1, w));
	}

	vector<long long> dist(n, INT64_MAX);
	dist[s] = 0;
	set < pair<int, int> > q;
	q.insert(make_pair(dist[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (size_t j = 0; j < graph[v].size(); ++j) {
			int to = graph[v][j].first;
			int	len = graph[v][j].second;
			if (dist[v] + len < dist[to]) {
				q.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + len;
				q.insert(make_pair(dist[to], to));
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	return 0;
}
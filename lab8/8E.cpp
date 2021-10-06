#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[30000];
int graphDepth[30000];

int main()
{
	freopen("pathbge1.in", "r", stdin);
	freopen("pathbge1.out", "w", stdout);
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
	bfsQueue.push(0);
	while (!bfsQueue.empty()) {
		for (int j = 0; j < graph[bfsQueue.front()].size(); j++) {
			int child = graph[bfsQueue.front()][j];
			if ((graphDepth[child] == 0 || graphDepth[child] > graphDepth[bfsQueue.front()] + 1) && child!=0) {
				bfsQueue.push(child);
				graphDepth[child] = graphDepth[bfsQueue.front()] + 1;
			}
		}
		bfsQueue.pop();
	}
	for (int i = 0; i < n; i++)
		cout << graphDepth[i] << " ";
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
vector<int> graph[10000];
vector<char> direction[10000];
int graphDepth[10000];
bool map[100][100];
string graphPath[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, startx, starty, endx, endy;
	cin >> n >> m;
	for (int i = 0; i < m * n; i++) {
		char tile;
		cin >> tile;
		map[i % m][i / m] = tile == '#';
		if (tile == 'S') {
			startx = i % m;
			starty = i / m;
		}
		else if (tile == 'T') {
			endx = i % m;
			endy = i / m;
		}

	}
	for (int i = 0; i < m * n; i++) {
		int x = i % m, y = i / m;
		if (!map[x][y]) {
			if (y > 0 && !map[x][y - 1]) {
				graph[i].push_back(i - m);
				direction[i].push_back('U');
			}
			if (y < n - 1 && !map[x][y + 1]) {
				graph[i].push_back(i + m);
				direction[i].push_back('D');
			}
			if (x > 0 && !map[x - 1][y]) {
				graph[i].push_back(i - 1);
				direction[i].push_back('L');
			}
			if (x < m - 1 && !map[x + 1][y]) {
				direction[i].push_back('R');
				graph[i].push_back(i + 1);
			}
		}
	}

	queue<int> bfsQueue;
	bfsQueue.push(startx + starty * m);
	while (!bfsQueue.empty()) {
		for (int j = 0; j < graph[bfsQueue.front()].size(); j++) {
			int child = graph[bfsQueue.front()][j];
			if ((graphDepth[child] == 0 || graphDepth[child] > graphDepth[bfsQueue.front()] + 1) && child != startx + starty * m) {
				bfsQueue.push(child);
				graphDepth[child] = graphDepth[bfsQueue.front()] + 1;
				graphPath[child] = graphPath[bfsQueue.front()] + direction[bfsQueue.front()][j];
			}
		}
		bfsQueue.pop();
	}
	if (graphDepth[endx + endy * m] == 0)
		cout << "-1";
	else
		cout << graphDepth[endx + endy * m] << "\n" << graphPath[endx + endy * m];
	return 0;
}
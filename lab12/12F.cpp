#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int d[100][2];
int w[100];
vector<int> c[100];

int step(int v, int color) {
	if (d[v][color] != 0)
		return d[v][color];
	if (color == 1) {
		int result = w[v];
		for (int i = 0; i < c[v].size(); i++)
			result += step(c[v][i], 0);
		d[v][1] = result;
		return result;
	}
	int result = 0;
	for (int i = 0; i < c[v].size(); i++)
		result += max(step(c[v][i], 0), step(c[v][i], 1));
	d[v][0] = result;
	return result;
}

int main()
{
	freopen("selectw.in", "r", stdin);
	freopen("selectw.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, root = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v >> w[i];
		if (v == 0)
			root = i;
		else
			c[v - 1].push_back(i);
	}
	cout << max(step(root, 0), step(root, 1));
}

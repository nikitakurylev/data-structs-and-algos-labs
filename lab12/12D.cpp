#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

int moves[][2] = {
{-1, 2}, { 2, -1}, { 1, 2}, { 2, 1} };
int d[15][15];
int n, m;

int step(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	if (x == n - 1 && y == m - 1) 
		return 1; 
	if (d[x][y] != 0)
		return d[x][y];
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];
		result += step(nx, ny);
	}
	d[x][y] = result;
	return result;
}

int main()
{
	freopen("knight2.in", "r", stdin);
	freopen("knight2.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << step(0, 0);
	return 0;
}
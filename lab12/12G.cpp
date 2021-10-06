#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

int d[301][10001];

int main()
{
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int s, n;
	int a[300];

	cin >> s >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= s; j++)
			if (j - a[i] >= 0)
 				d[i][j] = max(d[i - 1][j], d[i - 1][j - a[i]] + a[i]);
			else
				d[i][j] = d[i - 1][j];
	cout << d[n][s];
	return 0;
}
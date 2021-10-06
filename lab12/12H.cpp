#include <iostream>
#include <vector>
#pragma warning(disable : 4996)
#define MOD 1000000000

using namespace std;

int a[2000];
int d[2000][2000];

int step(int i, int j) {
	if(i == j)
		return 1;
	if (i > j)
		return 0;
	if (d[i][j] != 0)
		return d[i][j];
	if (a[i] != a[j])
		d[i][j] = (MOD + (step(i,j - 1) + step(i + 1, j)) % MOD - step(i + 1, j - 1)) % MOD;
	else
		d[i][j] = (step(i, j - 1) + step(i + 1, j) + 1) % MOD;
	return d[i][j];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << step(0,n-1);
	return 0;
}

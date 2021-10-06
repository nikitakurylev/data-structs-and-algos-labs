#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning(disable : 4996)


using namespace std;

int a[1000000];
vector<int> d;
int p[1000001];
int pa[1000000];

int main()
{
	int n;
	cin >> n;
	d = vector<int>(n+1);
	for (int i = 0; i < n; i++) {
		d[i + 1] = INT32_MAX;
		pa[i] = -1;
		cin >> a[i];
	}
	d[0] = -INT32_MIN;
	
	for (int i = 0; i < n; i++) {
		int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
		if (d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
			p[j] = i;
			pa[i] = p[j - 1];
		}
	}
	int k, l = -1;
	for (int i = 0; i <= n; i++)
		if (d[i] != INT32_MAX) {
			k = i;
			l++;
		}
	cout << k << "\n";
	int j = p[l];
	string buf = "";
	for (int i = 0; i < l; i++) {
		buf = to_string(a[j]) + " " + buf;
		j = pa[j];
	}
	cout << buf;
	return 0;
}
#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	vector<int> prefix(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = prefix[i - 1];
		while (j > 0 && s[i] != s[j])
			j = prefix[j - 1];
		if (s[i] == s[j])
			j++;
		prefix[i] = j;
	}
	for (int i = 0; i < prefix.size(); i++)
		cout << prefix[i] << ' ';
}
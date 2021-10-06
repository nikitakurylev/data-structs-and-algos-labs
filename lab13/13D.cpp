#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	s += '!';

	vector<int> prefix(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = prefix[i - 1];
		while (j > 0 && s[i] != s[j])
			j = prefix[j - 1];
		if (s[i] == s[j])
			j++;
		prefix[i] = j;
	}


	vector<vector<int>> result(s.length(), vector<int>(n));
	for (int i = 0; i < s.length(); i++) {
		for (char c = 0; c < n; c++) {
			if (i > 0 && c + 'a' != s[i])
				result[i][c] = result[prefix[i - 1]][c];
			else
				result[i][c] = i + (c + 'a' == s[i]);
			cout << result[i][c] << ' ';
		}
		cout << '\n';
	}
 }
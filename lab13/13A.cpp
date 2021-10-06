#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("search1.in", "r", stdin);
	freopen("search1.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string p, t;
	cin >> p >> t;
	vector<int> answer;
	for (int i = 0; i < t.length(); i++) {
		int j;
		for (j = 0; j < p.length(); j++)
			if (t[i + j] != p[j])
				break;
		if (j == p.length())
			answer.push_back(i + 1);
	}
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}

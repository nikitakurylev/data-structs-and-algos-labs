#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("search2.in", "r", stdin);
	freopen("search2.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string p, t;
	cin >> p >> t;

	const int maxpower = 57;
	vector<long long> powers(max(p.length(), t.length()));
	powers[0] = 1;
	for (int i = 1; i < powers.size(); i++)
		powers[i] = powers[i - 1] * maxpower;

	vector<long long> thash(t.length());
	for (int i = 0; i < t.length(); i++)
	{
		thash[i] = (t[i] - 'A' + 1) * powers[i];
		if (i)  
			thash[i] += thash[i - 1];
	}

	long long phash = 0;
	for (int i = 0; i < p.length(); i++)
		phash += (p[i] - 'A' + 1) * powers[i];

	vector<int> result;
	for (int i = 0; i + p.length() - 1 < t.length(); i++)
	{
		long long cur = thash[i + p.length() - 1];
		if(i)  
			cur -= thash[i - 1];
		if (cur == phash * powers[i])
			result.push_back(i + 1);
	}
	
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
}
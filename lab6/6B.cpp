#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)
#define SIZE 100003
#define SIZE1 50
#define A 0.987654
#define STEP 100
#define POW 31

using namespace std;

struct item {
	bool exists = false;
	string key;
	string value;
};

item hashset[SIZE][SIZE1];
int powers[20];
long unsigned key(string x) {
	long unsigned result = 0;
	int length = x.length();
	for (int i = 0; i < length; i++)
		result = (result + (x[i]-'a') * powers[i]) % SIZE;
	return result;
}

void put(string x, string y) {
	long unsigned k = key(x);
	int i = 0;
	bool found = false;
	for (i = 0; i < SIZE1; i++)
		if (hashset[k][i].key == x || !hashset[k][i].exists) {
			found = true;
			break;
		}
	if(!found)
		for (i = 0; i < SIZE1; i++)
			if (hashset[k][i].key == "")
				break;
	hashset[k][i].exists = true;
	hashset[k][i].key = x;
	hashset[k][i].value = y;
}

string get(string x) {
	long unsigned k = key(x);
	int i = 0;
	bool found = false;
	for (i = 0; i < SIZE1; i++)
		if (hashset[k][i].key == x) {
			found = true;
			break;
		}
		else if (!hashset[k][i].exists)
			break;
	if (!found)
		return "none";
	else
		return hashset[k][i].value;
}

void remove(string x) {
	long unsigned k = key(x);
	int i = 0;
	bool found = false;
	for (i = 0; i < SIZE1; i++)
		if (hashset[k][i].key == x) {
			found = true;
			break;
		}
		else if (!hashset[k][i].exists)
			break;
	if (found)
		hashset[k][i].key = "";
	

}

int main()
{
	int powx = 1;
	for (int i = 0; i < 20; i++) {
		powers[i] = powx;
		powx = (powx * POW) % SIZE;
	}

	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	while (cin >> s) {
		string x, y;
		if (s == "put") {
			cin >> x >> y;
			put(x, y);
		}
		else if (s == "get") {
			cin >> x;
			cout << get(x) << "\n";
		}
		else if (s == "delete") {
			cin >> x;
			remove(x);
		}
	}
	return 0;
}
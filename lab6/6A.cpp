#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)
#define SIZE 10000000
#define A 0.987654
#define STEP 100

using namespace std;

struct item {
	bool exists;
	bool defined;
	int value;
};

item hashset[SIZE];

long unsigned key(int x) {
	double intpart;
	return floor(SIZE*(modf(abs(x)*A,&intpart)));
}

bool exists(int x) {
	long unsigned k = key(x);
	long unsigned i = 0;
	while (hashset[(k + i * STEP) % SIZE].exists) {
		if (hashset[(k + i * STEP) % SIZE].defined && hashset[k + i * STEP].value == x)
			return true;
		i++;
	}
	return false;
}

void insert(int x) {
	long unsigned k = key(x);
	long unsigned i = 0;
	if (!exists(x)) {
		while (hashset[(k + i * STEP) % SIZE].defined) i++;
		i = (k + i * STEP) % SIZE;
		hashset[i].value = x;
		hashset[i].exists = true;
		hashset[i].defined = true;
	}
}

void remove(int x) {
	long unsigned k = key(x);
	long unsigned i = 0;
	if (exists(x))
		while (hashset[(k + i * STEP) % SIZE].exists) {
			long unsigned key = (k + i * STEP) % SIZE;
			if(hashset[key].defined && hashset[key].value == x) {
				hashset[key].defined = false;
				break;
			}
			i++;
		}
}

int main()
{
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	while (cin >> s) {
		int x;
		if (s == "insert") {
			cin >> x;
			insert(x);
		}
		else if (s == "exists") {
			cin >> x;
			cout << (exists(x) ? "true" : "false") << "\n";
		}
		else if (s == "delete") {
			cin >> x;
			remove(x);
		}
	}
	return 0;
}
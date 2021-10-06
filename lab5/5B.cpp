#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Node {
    int key;
    int left;
    int right;
    int parent;
};

Node tree[200000];

bool check(int index, int min, int max) {
    if (index == 0)
        return true;
    if (tree[index].key <= min || tree[index].key >= max)
        return false;
    return check(tree[index].left, min, tree[index].key) && check(tree[index].right, tree[index].key, max);
}

int main()
{
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            cin >> tree[i].key >> tree[i].left >> tree[i].right;
        }
        if (check(1,-1000000001, 1000000001))
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "YES";
    return 0;
}
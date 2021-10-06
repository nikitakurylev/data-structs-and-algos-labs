#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Node {
    int left;
    int height = 0;
    bool exists = false;
    int right;
};

Node tree[200000];

int height(int index) {
    if (tree[index].exists)
        return tree[index].height;
    int depthleft = 1, depthright = 1;
    if (tree[index].left)
        depthleft = height(tree[index].left);
    if (tree[index].right)
        depthright = height(tree[index].right);
    int depth = (depthleft > depthright ? depthleft : depthright);
    tree[index].height = depth;
    tree[index].exists = true;
    return depth+1;
}

int main()
{
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, i, dummy;
    cin >> n;
    if (n > 0) {
        for (i = 1; i <= n; i++) 
            cin >> dummy >> tree[i].left >> tree[i].right;
        for (i = 1; i <= n; i++)
            tree[i].height = height(i);
        for (i = 1; i <= n; i++) 
            cout << tree[tree[i].right].height - tree[tree[i].left].height << "\n";
    }
    else
        cout << "0";
    return 0;
}
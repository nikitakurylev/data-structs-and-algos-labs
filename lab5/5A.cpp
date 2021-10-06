#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Node {
    //bool empty;
    int key;
    int left;
    int right;
    int parent;
};

Node tree[200000];

int walk(int index, int depth) {
    int depthleft = depth, depthright = depth;
    if(tree[index].left != 0)
        depthleft = walk(tree[index].left, depth + 1);
    if (tree[index].right != 0)
        depthright = walk(tree[index].right, depth + 1);
    depth = depthleft > depthright ? depthleft : depthright;
    return depth;
}

int main()
{
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            cin >> tree[i].key >> tree[i].left >> tree[i].right;
        }
        cout << walk(1, 1);
    }
    else
        cout << "0";
    return 0;
}
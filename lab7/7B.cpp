#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

int height(Node* node) {
    return node ? node->height : 0;
}

int balance(Node* node) {
    return height(node->right) - height(node->left);
}

void fixheight(Node* node) {
    int left = height(node->left);
    int right = height(node->right);
    node->height = (left > right ? left : right) + 1;
}

Node* rotateleft(Node* a)
{
    Node* b = a->right;
    a->right = b->left;
    b->left = a;
    fixheight(a);
    fixheight(b);
    return b;
}
Node* rotateright(Node* a)
{
    Node* b = a->left;
    a->left = b->right;
    b->right = a;
    fixheight(a);
    fixheight(b);
    return b;
}


void printNode(Node* node) {
    Node* output[200000];
    output[1] = node;
    int start = 1, end = 2;
    while (start < end) {
        int right = 0, left = 0;
        if (output[start]->left->height != 0) {
            left = end;
            output[end] = output[start]->left;
            end++;
        }
        if (output[start]->right->height != 0) {
            right = end;
            output[end] = output[start]->right;
            end++;
        }
        cout << output[start]->key << " " << left << " " << right << "\n";
        start++;
    }
}

Node tree[200000];

int main()
{
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, i;
    cin >> n;
    if (n > 0) {
        for (i = 1; i <= n; i++) {
            int l, r;
            cin >> tree[i].key >> l >> r;
            tree[i].left = &tree[l];
            tree[i].right = &tree[r];
        }
        for (i = n; i >= 1; i--)
            fixheight(&tree[i]);
        Node* root = &tree[1];
        if (balance(root->right) == -1)
            root->right = rotateright(root->right);
        root = rotateleft(root);
        cout << n << "\n";
        printNode(root);
    }
    else
        cout << "0";
    return 0;
}
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int value) {
        key = value;
        height = 1;
        left = 0;
        right = 0;
    }
    Node() {
        key = 0;
        height = 0;
        left = 0;
        right = 0;
    }
};

int height(Node* node) {
    return node ? node->height : 0;
}

int getbalance(Node* node) {
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

Node* balancetree(Node* node) {
    fixheight(node);
    int balance = getbalance(node);
    if (balance == 2) {
        if (getbalance(node->right) < 0)
            node->right = rotateright(node->right);
        node = rotateleft(node);
    }
    else if(balance == -2) {
        if (getbalance(node->left) > 0)
            node->left = rotateleft(node->left);
        node = rotateright(node);
    }
    return node;
}
int n;

Node* insert(Node* node, int value) {
    if (!node) {
        n++;
        return new Node(value);
    }
    if (value < node->key)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return balancetree(node);
}

Node* output[300000];
void printNode(Node* node) {
    output[1] = node;
    int start = 1, end = 2;
    while (start < end) {
        int right = 0, left = 0;
        if (output[start]->left) {
            left = end;
            output[end] = output[start]->left;
            end++;
        }
        if (output[start]->right) {
            right = end;
            output[end] = output[start]->right;
            end++;
        }
        cout << output[start]->key << " " << left << " " << right << "\n";
        start++;
    }
}

Node tree[300000];
int main()
{
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, value;
    cin >> n;
    if (n > 0) {
        for (i = 1; i <= n; i++) {
            int l, r;
            cin >> tree[i].key >> l >> r;
            //tree[i].left = 0;
            //tree[i].right = 0;
            if (l != 0)
                tree[i].left = &tree[l];
            if (r != 0)
                tree[i].right = &tree[r];
        }
        
        for (i = n; i >= 1; i--)
            fixheight(&tree[i]);
        Node* root = &tree[1];
        cin >> value;
        root = insert(root, value);
        cout << n << "\n";
        printNode(root);
    }
    else {
        cin >> value;
        cout << "1\n" << value <<" 0 0";
    }
    return 0;
}
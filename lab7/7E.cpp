#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

int n = 0;

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
    if (n == 0)
        return 0;
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
    else if (balance == -2) {
        if (getbalance(node->left) > 0)
            node->left = rotateleft(node->left);
        node = rotateright(node);
    }
    return node;
}

Node* insert(Node* node, int value) {
    if (!node || n == 0) {
        n++;
        return new Node(value);
    }
    if (value < node->key)
        node->left = insert(node->left, value);
    else if (value > node->key)
        node->right = insert(node->right, value);
    return balancetree(node);
}

Node* removerightest(Node* root, Node* node) {
    if (node->right)
        node->right = removerightest(root, node->right);
    else {
        root->key = node->key;
        if (node->left)
            return balancetree(node->left);
        else
            return 0;
    }
    return balancetree(node);
}

Node* remove(Node* node, int value)
{
    if (!node || n == 0) return 0;
    if (value < node->key)
        node->left = remove(node->left, value);
    else if (value > node->key)
        node->right = remove(node->right, value);
    else {
        n--;
        if (!node->left && !node->right)
            return 0;
        else if (!node->left)
            node = node->right;
        else
            node->left = removerightest(node, node->left);
    }
    return balancetree(node);
}

bool check(Node* node, int value) {
    if (!node || n == 0)
        return false;
    else if (node->key > value)
        check(node->left, value);
    else if (node->key < value)
        check(node->right, value);
    else
        return true;
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

int main()
{
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, value, num;
    char task;
    Node* root = new Node();
    cin >> num;
    for (i = 0; i < num; i++) {
        cin >> task >> value;
        if (task == 'A') {
            root = insert(root, value);
            cout << getbalance(root) << "\n";
        }
        else if (task == 'D') {
            root = remove(root, value);
            cout << getbalance(root) << "\n";
        }
        else if (task == 'C') {
            cout << (check(root, value) ? "Y" : "N") << "\n";
        }
    }

    return 0;
}
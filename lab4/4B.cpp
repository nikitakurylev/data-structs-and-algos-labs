#include <iostream>

using namespace std;

int arr[1000000];
int head = 0;
int tail = 0;
int length = 0;
void enqueue(int x) {
    arr[tail] = x;
    if (tail == 999999)
        tail = 0;
    else
        tail++;
    length++;
}
int dequeue() {
    int x = arr[head];
    if (head == 999999)
        head = 0;
    else
        head++;
    length--;
    return x;
}
int main()
{
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    char cmd;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == '+') {
            cin >> x;
            enqueue(x);
        }
        else
        {
            cout << dequeue() << "\n";
        }
    }
    return 0;
}
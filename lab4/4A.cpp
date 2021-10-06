
#include <iostream>

using namespace std;

int arr[1000000];
int top = 0;

bool empty() {
	return top == 0;
}
void push(int x) {
	top++;
	arr[top] = x;
}
int pop() {
	if (empty())
		cerr << "underflow" << endl;
	else
	{
		top--;
		return arr[top + 1];
	}
}
int main()
{
	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n;
	char cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == '+') {
			cin >> x;
			push(x);
		}
		else
		{
			cout << pop() << "\n";
		}
	}
	return 0;
}

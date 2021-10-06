
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
    //cout << "pushed " << x << "\n";
}
int pop() {
    if (empty())
        cerr << "underflow" << endl;
    else
    {
        top--;
        //cout << "popped " << arr[top + 1] << "\n";
        return arr[top + 1];
    }
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main()
{
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s) {
        if (is_number(s)) {
            push(stoi(s));
        }
        else switch (s[0])
        {
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(-pop());
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        default:
            break;
        }

    }
    cout << pop();
    return 0;
}

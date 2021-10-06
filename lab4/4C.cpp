
#include <iostream>

using namespace std;

char arr[1000000];
int top = 0;

bool empty() {
	return top == 0;
}
void push(char x) {
	top++;
	arr[top] = x;
}
char pop() {
	if (empty())
		return '0';
	else
	{
		top--;
		return arr[top + 1];
	}
}
int main()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	while (cin >> s){
		bool good = true;
		for(int i = 0; i < s.size(); i++){
			if(s[i]==')'){
				if(pop()!='('){
					good=false;
					break;
				}
			}		
			else if(s[i]==']'){
				if(pop()!='['){
					good=false;
					break;
				}
			}
			else if(s[i]=='(' || s[i]=='[')
				push(s[i]);
		}
		if(top!=0)
			good=false;
		if(good)
			cout << "YES\n";
		else
			cout << "NO\n";
		top=0;
	}
	return 0;	
}



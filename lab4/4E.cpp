
#include <iostream>

using namespace std;

int arr[1000000];
int length = 0;
int binSearchFirst(int key){
	int left = -1;
	int right = length;
	while(left < right - 1){
		int mid = (left + right) / 2;
		if(arr[mid] < key)
			left = mid;
		else
			right = mid;
	}
	return right;
}
int binSearchLast(int key){
	int left = -1;
	int right = length;
	while(left < right - 1){
		int mid = (left + right) / 2;
		if(arr[mid] <= key)
			left = mid;
		else
			right = mid;
	}
	return left;
}

int main()
{
	freopen("binsearch.in", "r", stdin);
	freopen("binsearch.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> length;
	for(int i = 0; i < length; i++)
		cin >> arr[i];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int bin = binSearchFirst(x);
		if(arr[bin]!=x)
			cout << "-1 -1\n";
		else
			cout << bin + 1 << ' ' << binSearchLast(x) + 1 << '\n';
	}
	return 0;	
}



#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("r","holiday.in",stdin);
	freopen("w","holiday.out",stdout); 
	int n,m,k,arr[10005];
	cin >> n >> m >> k;
	for (int i = 1;i < n;i++){
		cin >> arr[i];
	}
	for (int j = 1;j <= m;j++){
		int x,y;
		cin >> x >> y;
		//add(x,y);
		//add(y,x);
	}
	cout << n;
	return 0;
}

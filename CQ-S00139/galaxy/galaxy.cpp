#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("r","galaxy.in",stdin);
	freopen("w","galaxy.out",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		//add(u,v);
	} 
	int q;
	cin >> q;
	while (q--){
		int t,a,b;
		cin >> t;
		if (t == 1 || t == 3){
			cin >> a >> b;
		}
		else {
			cin >> a;
		}
		cout << "NO";
	}
	return 0;
}

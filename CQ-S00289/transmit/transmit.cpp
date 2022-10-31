#include <bits/stdc++.h>
using namespace std;
int v[1000005];
vector<int> G[100005];
queue<int> q;
struct node {
	int num;
	int status;
	node(){
		
	}
	node(int _num,int _status){
		num = _num;
		status = _status;
	}
};
int bfs(int s,int t){
	
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,q,k;
	cin >> n >> q >> k;
	for (int i =  0;i < n;i++) {
		cin >> v[i];
	}
	for (int i =0;i < n - 1;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i =0;i < q;i++) {
		int s,t;
		cin >> s>>t;
	}
	return 0;
}

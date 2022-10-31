#include<bits/stdc++.h>
#include<vector>
using namespace std;
int f[2505][2505];
int v[200005];
int n,Q,k;
vector<int>ver[2505];
void add(int x,int y){
	ver[x].push_back(y);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(i!=j)f[i][j]=0x3f3f3f3f;
	
	cin>>n>>Q>>k;
	for(int i=1;i<=n;i++)cin>>v[i];
	int x,y;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	int s,t;
	for(int i=1;i<=Q;i++){
		cin>>s>>t;
	}
	cout<<"Good Luck CSP 2022!"<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool a[10001][10001];
int n,m,q;
bool check(){
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]=1)cnt++;
		}
		if(cnt!=1)return 0;
	}
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int b;
		cin>>b;
		if(b==1){
			int u,v;
			cin>>u>>v;
			a[u][v]=0;
			a[v][u]=0;
		}
		if(b==2){
			int u;
			cin>>u;
			for(int i=1;i<=n;i++){
				a[i][u]=0;
			}
		}
		if(b==3){
			int u,v;
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
		}
		if(b==4){
			int u;
			cin>>u;
			for(int i=1;i<=n;i++){
				a[i][u]=1;
			}
		}
		if(check())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

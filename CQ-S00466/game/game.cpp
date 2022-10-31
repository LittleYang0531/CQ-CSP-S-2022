#include<bits/stdc++.h>
using namespace std;
#define maxn 1e9
int n,m,q,a[10000],b[10000],c[10000][10000],l1,r1,l2,r2,maxx=-maxn,minn=maxn,minn1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdin);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
	for(int i=1;i<=q;i++){
		int o;
		cin>>l1>>r1>>l2>>r2;
		maxx=-maxn;
		for(int j=l1;j<=r1;j++){
			minn=maxn;
			for(int k=l2;k<=r2;k++){
				minn=min(minn,c[j][k]);
				minn1=min(minn1,c[j][k]);
			}
			maxx=max(minn,maxx);
		}
		cout<<maxx<<endl;
	}
	return 0;
}


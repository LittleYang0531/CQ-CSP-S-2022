#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005][100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
int n,m,q;
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
for(int z=1;z<=q;z++){
	int l1,r1,l2,r2,d=-1000000;
	cin>>l1>>r1>>l2>>r2;
	for(int i=l1;i<=r1;i++){
		int e=0;
	for(int j=l2;j<=r2;j++){
		if(c[i][j]<0)e=1;
	}
	if(e!=1)
	for(int j=1;j<=m;j++)
	if(d<c[i][j])d=c[i][j];
	}
	cout<<d<<endl;
}
	return 0;
}

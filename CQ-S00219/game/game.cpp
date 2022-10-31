#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[10005],b[10005],c[1005][1005];
struct S_T{
	long long t[4002];
	void Build(int x,int l,int r,int i){
		if(l==r){
			t[x]=c[i][l];
			return;
		}
		int mid=(l+r)/2;
		Build(x*2,l,mid,i);
		Build(x*2+1,mid+1,r,i);
		t[x]=min(t[x*2],t[x*2+1]);
	}
	long long query(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R)return t[x];
		long long mid=(l+r)/2;
		if(R<=mid)return query(x*2,l,mid,L,R);
		else if(mid<L)return query(x*2+1,mid+1,r,L,R);
		else return min(query(x*2,l,mid,L,R),query(x*2+1,mid+1,r,L,R));
	}
}stM[1002];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	for(int i=1;i<=n;i++)stM[i].Build(1,1,m,i);
	while(q--){
		long long l1,r1,l2,r2,Max=-1e18;
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++){
			Max=max(Max,stM[i].query(1,1,m,l2,r2));
		}
		printf("%lld\n",Max);
	}
	return 0;
}/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/

#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
typedef long long ll;
const ll inf=1e18;
const int N=1e5+5;
int n,m,q,X,Y;
int a[N],b[N],c[N],d[N],id1[N],id2[N];
int lg[N];
struct ST{
	bool OP;// 0:max  1:min
	int st[20][N];
	inline int Max(int a,int b){return ((a>b)^OP)?a:b;}
	void build(int n,int *a){
		for(int i=1;i<=n;i++)st[0][i]=a[i];
		for(int i=1;1<<i<=n;i++)
			for(int j=1;j<=n-(1<<i)+1;j++)
				st[i][j]=Max(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	inline int get(int l,int r){
		int k=lg[r-l+1];
		return Max(st[k][l],st[k][r-(1<<k)+1]);	
	}
}s1,s2,s3,s4,s5,s6;
inline ll calc(int l,int r,ll x){
	ll res;
	if(x<0)res=x*s5.get(l,r);
	else res=x*s6.get(l,r);
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=in(),m=in(),q=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<=m;i++)b[i]=in();
	for(int i=2;i<=100000;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		if(a[i]>=0)c[++X]=a[i];
		else d[++Y]=a[i];
		id1[i]=X,id2[i]=Y;
	}
	s1.OP=0,s1.build(X,c);
	s2.OP=1,s2.build(X,c);
	s3.OP=0,s3.build(Y,d);
	s4.OP=1,s4.build(Y,d);
	s5.OP=0,s5.build(m,b);
	s6.OP=1,s6.build(m,b);
	while(q--){
		int l1=in(),r1=in(),l2=in(),r2=in();
		ll ans=-inf;
		if(id1[l1-1]!=id1[r1]){
			int l=id1[l1-1]+1,r=id1[r1];
			ans=max(ans,calc(l2,r2,s1.get(l,r)));
			ans=max(ans,calc(l2,r2,s2.get(l,r)));
		}
		if(id2[l1-1]!=id2[r1]){
			int l=id2[l1-1]+1,r=id2[r1];
			ans=max(ans,calc(l2,r2,s3.get(l,r)));
			ans=max(ans,calc(l2,r2,s4.get(l,r)));	
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100005][2];
int maxn[400005][2],mixn[400005][2];
int minn[400005][2],mann[400005][2];
void bt(int p,int l,int r,int op) {
	mixn[p][op]=(1e9)+1;
	mann[p][op]=-(1e9)-1;
	if(l==r) {
		maxn[p][op]=a[l][op];minn[p][op]=a[l][op];
		if(a[l][op]>=0) mixn[p][op]=a[l][op];
		if(a[l][op]<=0) mann[p][op]=a[l][op];
		return ;
	}
	int mid=l+r>>1;
	bt(p<<1,l,mid,op);
	bt(p<<1|1,mid+1,r,op);
	maxn[p][op]=max(maxn[p<<1][op],maxn[p<<1|1][op]);
	minn[p][op]=min(minn[p<<1][op],minn[p<<1|1][op]);
	mixn[p][op]=min(mixn[p<<1][op],mixn[p<<1|1][op]);
	mann[p][op]=max(mann[p<<1][op],mann[p<<1|1][op]);
}
int g(int p,int l,int r,int x,int y,int op,int ui) {
	if(x<=l&&r<=y) {
//		cout<<ui<<" "<<op<<" "<<l<<" "<<r<<":";
//		if(ui==1) cout<<maxn[p][op]<<endl;
//		if(ui==2) cout<<mixn[p][op]<<endl;
//		if(ui==3) cout<<minn[p][op]<<endl;
//		if(ui==4) cout<<mann[p][op]<<endl;
		if(ui==1) return maxn[p][op];
		if(ui==2) return mixn[p][op];
		if(ui==3) return minn[p][op];
		if(ui==4) return mann[p][op];
	}
	int mid=l+r>>1;
	if(x<=mid&&y>mid) {
		if(ui==1||ui==4) return max(g(p<<1,l,mid,x,y,op,ui),g(p<<1|1,mid+1,r,x,y,op,ui));
		if(ui==2||ui==3) return min(g(p<<1,l,mid,x,y,op,ui),g(p<<1|1,mid+1,r,x,y,op,ui));
	} else if(x<=mid) return g(p<<1,l,mid,x,y,op,ui);
	else if(y>mid) return g(p<<1|1,mid+1,r,x,y,op,ui);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for(int i=1;i<=m;i++) scanf("%d",&a[i][1]);
	bt(1,1,n,0);bt(1,1,m,1);
	while(q--) {
		long long ans=(-1e18)-1;
		int l,r,l1,r1;
		int x,y,u,v;
		scanf("%d%d%d%d",&l,&r,&l1,&r1);
		x=g(1,1,m,l1,r1,1,1);
		y=g(1,1,m,l1,r1,1,3);
		if(x<=0) {
			u=g(1,1,n,l,r,0,3);
			if(u<=0) printf("%lld\n",1ll*u*x);
			else printf("%lld\n",1ll*u*y);
		} else if(y>=0) {
			u=g(1,1,n,l,r,0,1);
			if(u>=0) printf("%lld\n",1ll*u*y);
			else printf("%lld\n",1ll*u*x);
		} else{
			u=g(1,1,n,l,r,0,2);
			v=g(1,1,n,l,r,0,4);
			if(u!=((1e9)+1)) ans=max(ans,1ll*u*y);
			if(v!=(-(1e9)-1)) ans=max(ans,1ll*v*x);
			printf("%lld\n",ans);
		}
	}
	return 0;
}


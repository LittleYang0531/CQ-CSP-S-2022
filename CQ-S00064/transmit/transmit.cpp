#include<bits/stdc++.h>
using namespace std;
int n,q,k;
int v[400005],elast[200005],nxt[400005],f[200005][20],d[200005],tot;
long long a[200005],sum[200005],minn[200005];
void add(int x,int y) {
	v[++tot]=y;
	nxt[tot]=elast[x];
	elast[x]=tot;
}
void dfs(int x,int fa) {
	minn[x]=a[x];
	f[x][0]=fa;sum[x]=sum[fa]+a[x];d[x]=d[fa]+1;
	for(int i=1;i<=19;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=elast[x];i;i=nxt[i]) {
		int y=v[i];
		if(y!=fa) {
			dfs(y,x);
			minn[x]=min(minn[x],a[y]);
		}
	}
}
int L(int x,int y) {
	if(d[x]>d[y]) swap(x,y);
	for(int i=19;i>=0;i--)
		if(d[x]<=d[f[y][i]]) y=f[y][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
long long F[200005],F1[200005],tt,tot1,tot2;
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n-1;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	if(k==1) {
		while(q--) {
			int x,y;
			scanf("%d%d",&x,&y);
			int lca=L(x,y);
			printf("%lld\n",sum[x]+sum[y]-sum[lca]-sum[f[lca][0]]);
		}
	} else {
		while(q--) {
			int x,y;
			scanf("%d%d",&x,&y);
			int lca=L(x,y);tot2=d[x]+d[y]-d[lca]-d[f[lca][0]];
			tot1=tot2+1;tt=0;
			long long op=1e18,lo=1e18;
			while(lca!=x) {
				F[++tt]=a[x];
				F1[tt]=minn[x];
				x=f[x][0];
				
			}
			F[++tt]=a[lca];
			F1[tt]=minn[lca];
			while(lca!=y) {
				F[--tot1]=a[y];
				F1[tot1]=minn[y];
				y=f[y][0];
			}
			if(k==2) {
				F[2]+=F[1];
				for(int i=3;i<=tot2;i++) 
					F[i]+=min(F[i-1],F[i-2]);
				printf("%lld\n",F[tot2]);
			}
			if(k==3) {
				if(lca!=1) op=a[f[lca][0]];
				F[2]+=F[1];
				F1[1]+=F[1];
				F[3]+=F[1];
				F1[2]+=F[1];
				F1[3]+=F[1];
				if(tt>=1&&tt-1<=2) lo=min(lo,F[1]);
				if(tt>=1&&tt-1==1) lo=min(lo,F1[1]);
				if(tt>=2&&tt-2<=2) lo=min(lo,F[2]);
				if(tt>=2&&tt-2==1) lo=min(lo,F1[2]);
				if(tt>=3&&tt-3<=2) lo=min(lo,F[3]);
				if(tt>=3&&tt-3==1) lo=min(lo,F1[3]);
				if(tt<=3) op+=F[1];
				for(int i=4;i<=tot2;i++) {
					if(tt<i&&i-tt<=2) F[i]+=min(F[i-1],min(F[i-2],min(op,min(F[i-3],min(F1[i-1],F1[i-2])))));
					else F[i]+=min(F[i-1],min(F[i-2],min(F[i-3],min(F1[i-1],F1[i-2]))));
					if(tt<i&&i-tt==1) F1[i]+=min(F1[i-1],min(F[i-2],min(F[i-1],op)));
					else F1[i]+=min(F1[i-1],min(F[i-2],F[i-1]));
					if(tt>=i&&tt-i<=2) lo=min(lo,F[i]);
					if(tt>=i&&tt-i==1) lo=min(lo,F1[i]);
					if(tt==i) op+=lo;
				}
				printf("%lld\n",F[tot2]);
			}
			for(int i=1;i<=tot2;i++) F[i]=0,F1[i]=0;
		}
	}
	return 0;
}


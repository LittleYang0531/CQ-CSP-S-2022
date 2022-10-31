#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace tokidosaya {
#define lc id<<1
#define rc id<<1|1
	const int maxn=1e5+5;
	struct seg {
		struct tree {
			int l,r,mid;
		} t[maxn*4];
		int mx[maxn*4],mn[maxn*4],df[maxn*4],dz[maxn*4],xf[maxn*4],xz[maxn*4];
		//注意绝对值较小的负数应该更大！！
		void pushup(int id) {
			mx[id]=max(mx[lc],mx[rc]),mn[id]=min(mn[lc],mn[rc]);
			df[id]=max(df[lc],df[rc]),dz[id]=max(dz[lc],dz[rc]);
			xf[id]=min(xf[lc],xf[rc]),xz[id]=min(xz[lc],xz[rc]);
		}
		void build(int id,int l,int r,int *a) {
			t[id]=(tree) {
				l,r,l+r>>1
			};
			if(l==r) {
				mx[id]=mn[id]=a[l];
				if(a[l]<0)df[id]=xf[id]=a[l],dz[id]=-1e9,xz[id]=1e9;
				else dz[id]=xz[id]=a[l],df[id]=-1e9,xf[id]=1e9;
				return;
			}
			int mid=l+r>>1;
			build(lc,l,mid,a),build(rc,mid+1,r,a);
			pushup(id);
		}
		int askmax(int id,int l,int r,int *a) {
			if(t[id].l>=l&&t[id].r<=r)return a[id];
			int sum=-1e9;
			if(l<=t[id].mid)sum=max(sum,askmax(lc,l,r,a));
			if(r>t[id].mid)sum=max(sum,askmax(rc,l,r,a));
			return sum;
		}
		int askmin(int id,int l,int r,int *a) {
			if(t[id].l>=l&&t[id].r<=r)return a[id];
			int sum=1e9;
			if(l<=t[id].mid)sum=min(sum,askmin(lc,l,r,a));
			if(r>t[id].mid)sum=min(sum,askmin(rc,l,r,a));
			return sum;
		}
	} s1,s2;
	int a[maxn],b[maxn],sza[maxn],sfa[maxn],sz[maxn],sf[maxn],n,m,q;
	int main() {
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		int l1,r1,l2,r2;
		n=read(),m=read(),q=read();
		for(int i=1; i<=n; i++)a[i]=read(),sza[i]=sza[i-1],sfa[i]=sfa[i-1],(a[i]>=0?sza:sfa)[i]++;
		s1.build(1,1,n,a);
		for(int i=1; i<=m; i++)b[i]=read(),sz[i]=sz[i-1],sf[i]=sf[i-1],(b[i]>=0?sz:sf)[i]++;
		s2.build(1,1,m,b);
		while(q--) {
			l1=read(),r1=read(),l2=read(),r2=read();
			ll ans=-1e18;
			if(sf[r2]==sf[l2-1]) {
				//全正，选最大的数
				ans=s1.askmax(1,l1,r1,s1.mx);
				if(ans>=0)ans*=s2.askmin(1,l2,r2,s2.xz);
				else ans*=s2.askmax(1,l2,r2,s2.dz);
			} else if(sz[r2]==sz[l2-1]) {
				//全负，选最小的数
				ans=s1.askmin(1,l1,r1,s1.mn);
				if(ans>=0)ans*=s2.askmin(1,l2,r2,s2.xf);
				else ans*=s2.askmax(1,l2,r2,s2.df);
			} else {
				if(sza[r1]!=sza[l1-1])ans=max(ans,1ll*s1.askmin(1,l1,r1,s1.xz)*s2.askmin(1,l2,r2,s2.xf));
				if(sfa[r1]!=sfa[l1-1])ans=max(ans,1ll*s1.askmax(1,l1,r1,s1.df)*s2.askmax(1,l2,r2,s2.dz));
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main() {
	return tokidosaya::main();
}


#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n,m,q,a[N],b[N];
struct bb{
	int l,r,mx,mi,ml,mr;
};
struct ST{
	bb p[N*4];
	void pushup(int x){
		int l=x*2,r=x*2+1;
		p[x].mx=max(p[l].mx,p[r].mx);
		p[x].mi=min(p[l].mi,p[r].mi);
		p[x].ml=min(p[l].ml,p[r].ml);
		p[x].mr=max(p[l].mr,p[r].mr);
	}
	void build(int l,int r,int x,int ty){
		p[x]={l,r};
		if(l==r){
			if(ty==1){
				p[x].mx=p[x].mi=a[l];
				if(a[l]>=0){
					p[x].ml=a[l];
					p[x].mr=-1e9;
				}else{
					p[x].mr=a[l];
					p[x].ml=1e9;
				}
			}else {
				p[x].mx=p[x].mi=b[l];
				if(b[l]>=0){
					p[x].ml=b[l];
					p[x].mr=-1e9;
				}else{
					p[x].mr=b[l];
					p[x].ml=1e9;
				}
			}
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,x*2,ty),build(mid+1,r,x*2+1,ty);
		pushup(x);
	}
	int ask(int l,int r,int x,int ty){
		if(l<=p[x].l&&p[x].r<=r){
			if(ty==0)return p[x].mx;
			if(ty==1)return p[x].mi;
			if(ty==2)return p[x].ml;
			if(ty==3)return p[x].mr;
		}
		int mid=(p[x].l+p[x].r)>>1,ans;
		if(ty==0||ty==3){
			ans=-1e9;
			if(l<=mid)ans=max(ans,ask(l,r,x*2,ty));
			if(r>mid)ans=max(ans,ask(l,r,x*2+1,ty));
		}else{
			ans=1e9;
			if(l<=mid)ans=min(ans,ask(l,r,x*2,ty));
			if(r>mid)ans=min(ans,ask(l,r,x*2+1,ty));
		}
		return ans;
	}
}s1,s2;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",b+i);
	}
	s1.build(1,n,1,1);
	s2.build(1,n,1,2);
	while(q--){
		int l1,r1,l2,r2,ans=0;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		int mx1=s1.ask(l1,r1,1,0),mi1=s1.ask(l1,r1,1,1);
		int mx2=s2.ask(l2,r2,1,0),mi2=s2.ask(l2,r2,1,1);
		if(mi2>=0){
			ans=min(mx1*mi2,mx1*mx2);
		}else if(mx2<=0){
			ans=min(mi1*mi2,mi1*mx2);
		}else{
			ans=max(s1.ask(l1,r1,1,2)*mi2,s1.ask(l1,r1,1,3)*mx2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


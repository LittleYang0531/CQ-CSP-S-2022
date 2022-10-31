#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e9+10;
int n,m,q;
ll w[N];
struct node{
	int l,r;
	ll maxz,minz,maxf,minf;
	bool fg0;
}tr1[N<<2],tr2[N<<2];
void pushup1(int u){
	tr1[u].maxf=max(tr1[u<<1].maxf,tr1[u<<1|1].maxf);
	tr1[u].maxz=max(tr1[u<<1].maxz,tr1[u<<1|1].maxz);
	tr1[u].minf=min(tr1[u<<1].minf,tr1[u<<1|1].minf);
	tr1[u].minz=min(tr1[u<<1].minz,tr1[u<<1|1].minz);
	tr1[u].fg0=tr1[u<<1].fg0||tr1[u<<1|1].fg0;
}
void pushup2(int u){
	tr2[u].maxf=max(tr2[u<<1].maxf,tr2[u<<1|1].maxf);
	tr2[u].maxz=max(tr2[u<<1].maxz,tr2[u<<1|1].maxz);
	tr2[u].minf=min(tr2[u<<1].minf,tr2[u<<1|1].minf);
	tr2[u].minz=min(tr2[u<<1].minz,tr2[u<<1|1].minz);
	tr2[u].fg0=tr2[u<<1].fg0||tr2[u<<1|1].fg0;
}
void build1(int u,int l,int r){
	tr1[u].l=l,tr1[u].r=r;
	if(l==r){
		tr1[u]={l,l,w[l]>0?w[l]:0,w[l]>0?w[l]:inf,w[l]<0?w[l]:-inf,w[l]<0?w[l]:0,!w[l]};
		return ;
	}
	int mid=(l+r)>>1;
	build1(u<<1,l,mid),build1(u<<1|1,mid+1,r);
	pushup1(u);
}
void build2(int u,int l,int r){
	tr2[u].l=l,tr2[u].r=r;
	if(l==r){
		tr2[u]={l,l,w[l]>0?w[l]:0,w[l]>0?w[l]:inf,w[l]<0?w[l]:-inf,w[l]<0?w[l]:0,!w[l]};
		return ;
	}
	int mid=(l+r)>>1;
	build2(u<<1,l,mid),build2(u<<1|1,mid+1,r);
	pushup2(u);
}
node query1(int u,int l,int r){
	if(l<=tr1[u].l&&tr1[u].r<=r){
		return tr1[u];
	}
	int mid=(tr1[u].l+tr1[u].r)>>1;
	node res,lres={l,mid,0,inf,-inf,0,0},rres={mid+1,r,0,inf,-inf,0,0};
	if(l<=mid) lres=query1(u<<1,l,r);
	if(r>mid) rres=query1(u<<1|1,l,r);
	res.maxf=max(lres.maxf,rres.maxf);
	res.maxz=max(lres.maxz,rres.maxz);
	res.minf=min(lres.minf,rres.minf);
	res.minz=min(lres.minz,rres.minz);
	res.fg0=lres.fg0||rres.fg0;
	return res;
}
node query2(int u,int l,int r){
	if(l<=tr2[u].l&&tr2[u].r<=r){
		return tr2[u];
	}
	int mid=(tr2[u].l+tr2[u].r)>>1;
	node res,lres={l,mid,0,inf,-inf,0},rres={mid+1,r,0,inf,-inf,0};
	if(l<=mid) lres=query2(u<<1,l,r);
	if(r>mid) rres=query2(u<<1|1,l,r);
	res.maxf=max(lres.maxf,rres.maxf);
	res.maxz=max(lres.maxz,rres.maxz);
	res.minf=min(lres.minf,rres.minf);
	res.minz=min(lres.minz,rres.minz);
	res.fg0=lres.fg0||rres.fg0;
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	build1(1,1,n);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	build2(1,1,m);
	int a,b,c,d;
	while(q--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		node res1=query1(1,a,b),res2=query2(1,c,d);
		ll ans=-9e18;
		if(res1.fg0||(res2.maxz==0&&res2.minf==0)){
			ans=0;
		}
		if(res2.maxz>0) ans=max(ans,(res1.minf<0?res1.maxf:-inf)*res2.maxz);
		else if(res1.minf<0) ans=max(ans,res1.minf*(res2.minf<0?res2.maxf:inf));
		if(res2.minf<0) ans=max(ans,(res1.maxz>0?res1.minz:inf)*res2.minf);
		else if(res1.maxz>0) ans=max(ans,res1.maxz*(res2.maxz>0?res2.minz:-inf));
		if(res2.fg0) ans=min(ans,(ll)0);
		printf("%lld\n",ans);
	}
	return 0;
}

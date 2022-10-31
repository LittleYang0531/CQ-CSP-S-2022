#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct aa{
	int za,zi,fa,fi;
	aa(){
		fa=za=-2e9;
		fi=zi=2e9;
	}
}a[2][4*N];
aa up(aa a,aa b){
	aa ans;
	ans.za=max(a.za,b.za);
	ans.zi=min(a.zi,b.zi);
	ans.fa=max(a.fa,b.fa);
	ans.fi=min(a.fi,b.fi);
	return ans;
}
void build(int g,int l,int r,int v){
	if(l==r){
		int cs=0;
		scanf("%d",&cs);
		if(cs>=0) a[v][g].za=a[v][g].zi=cs;
		if(cs<=0) a[v][g].fa=a[v][g].fi=cs;
		return;
	}
	int mid=(l+r)/2;
	build(2*g,l,mid,v);
	build(2*g+1,mid+1,r,v);
	a[v][g]=up(a[v][2*g],a[v][2*g+1]);
}
aa da(int g,int l,int r,int l1,int r1,int v){
	if(l1<=l && r<=r1) return a[v][g];
	aa ans;
	int mid=(l+r)/2;
	if(l1<=mid) ans=da(2*g,l,mid,l1,r1,v);
	if(r1>mid) ans=up(da(2*g+1,mid+1,r,l1,r1,v),ans);
	return ans;
}
int n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	build(1,1,n,0);
	build(1,1,m,1);
	while(q--){
		int l1=0,r1=0,l2=0,r2=0;
		long long ans=-1e18;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		aa an1=da(1,1,n,l1,r1,0),an2=da(1,1,m,l2,r2,1);
		an2.za=max(an2.za,an2.fa);
		an2.zi=min(an2.zi,an2.fi);
		if(an1.za>=0){
			ans=max((long long)(an1.za)*(long long)(an2.zi)
			,(long long)(an1.zi)*(long long)(an2.zi));
		}
		if(an1.fi<=0){
			ans=max(ans,max(
			(long long)(an1.fa)*(long long)(an2.za)
			,(long long)(an1.fi)*(long long)(an2.za)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

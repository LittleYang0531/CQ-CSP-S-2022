#include<bits/stdc++.h>
#define maxn 1001
#define ll long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
int n,m,T;
ll a[maxn],b[maxn],ans;
ll tr[maxn*maxn*4];
struct Tree{
	void updata(int p){
		tr[p]=min(tr[ls],tr[rs]);
	}
	void add(int l,int r,int p,int x,ll w){
		if(l==r){
			tr[p]=w;
			return;
		}
		int mid=l+r>>1;
		if(mid>=x){
			add(l,mid,p<<1,x,w);
		}else{
			add(mid+1,r,p<<1|1,x,w);
		}
		updata(p);
	}
	ll query(int l,int r,int p,int x,int y){
		if(l>=x&&r<=y){
			return tr[p];
		}
		int mid=l+r>>1;
		ll ans=0x7f7f7f7f7f7f7f7f;
		if(mid>=x){
			ans=min(ans,query(l,mid,ls,x,y));
		}
		if(mid<y){
			ans=min(ans,query(mid+1,r,rs,x,y));
		}
		return ans;
	}
}t;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	//cout<<a[i]*b[i]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t.add(1,n*m,1,(i-1)*m+j,a[i]*b[j]);
		}
	}
	while(T--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ans=-0x7f7f7f7f7f7f7f7f;
		for(int i=l1;i<=r1;i++){
			ll now=t.query(1,n*m,1,(i-1)*m+l2,(i-1)*m+r2);
			//cout<<now<<endl;
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


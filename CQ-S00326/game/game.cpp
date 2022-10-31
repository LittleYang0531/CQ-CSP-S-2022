#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=(-1*1e18)-100;
const int N=1000+10;
struct node{
	ll l,r,num;
}t[N][N*5];
ll n,m,q;
ll a[N],b[N];
ll cnt[205][205][205];
void build(int l,int r,int p,int line){
	t[line][p].l=l,t[line][p].r=r;
	if(l==r){
		t[line][p].num=a[line]*b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p<<1,line);
	build(mid+1,r,(p<<1)+1,line);
	t[line][p].num=min(t[line][p<<1].num,t[line][(p<<1)+1].num);
}
ll memfind(int l,int r,int p,int line){
	if(cnt[line][l][r]) return cnt[line][l][r];
	else{
		if(t[line][p].l==l&&t[line][p].r==r){
			return cnt[line][l][r]=t[line][p].num;
		}
		int mid=(t[line][p].l+t[line][p].r)>>1;
		if(mid<l) return cnt[line][l][r]=memfind(l,r,(p<<1)+1,line);
		else if(mid>=r) return cnt[line][l][r]=memfind(l,r,p<<1,line);
		else return cnt[line][l][r]=min(memfind(l,mid,p<<1,line),memfind(mid+1,r,(p<<1)+1,line));
	}
}
ll find(int l,int r,int p,int line){
	if(t[line][p].l==l&&t[line][p].r==r){
		return t[line][p].num;
	}
	int mid=(t[line][p].l+t[line][p].r)>>1;
	if(mid<l) return find(l,r,(p<<1)+1,line);
	else if(mid>=r) return find(l,r,p<<1,line);
	else return min(find(l,mid,p<<1,line),find(mid+1,r,(p<<1)+1,line));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=n;i++){
		build(1,m,1,i);
	}
	if(n<=200&&m<=200&&q<=200){
		for(int i=1;i<=q;i++){
			int l_1,l_2,r_1,r_2;
			ll ans=inf;
			scanf("%d%d%d%d",&l_1,&r_1,&l_2,&r_2);
			for(int j=l_1;j<=r_1;j++){
				ll num=memfind(l_2,r_2,1,j);
				if(ans<num) ans=num;
			}
			printf("%lld\n",ans);
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int l_1,l_2,r_1,r_2;
			ll ans=inf;
			scanf("%d%d%d%d",&l_1,&r_1,&l_2,&r_2);
			for(int j=l_1;j<=r_1;j++){
				ll num=find(l_2,r_2,1,j);
				if(ans<num) ans=num;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

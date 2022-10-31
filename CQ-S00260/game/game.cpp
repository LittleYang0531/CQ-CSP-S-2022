#include<iostream> 
#include<cstdio>
#include<map>
#include<vector> 
#include<algorithm>
using namespace std;
struct node{
	int l,r,cnt1,cnt2,cnt,mx,mn,mx_z,mx_f,mn_z,mn_f;//cnt1正，cnt2负,cnt零 
}t[1000005][2];
int n,m,a[1000005][2];
void merge(node &a,node &b,node &c){//b,c合为 a
	a.cnt=b.cnt+c.cnt;
	a.cnt1=b.cnt1+c.cnt1;
	a.cnt2=b.cnt2+c.cnt2;
	a.mn=min(b.mn,c.mn);
	a.mx=max(b.mx,c.mx);
	a.mx_z=max(b.mx_z,c.mx_z);
	a.mx_f=max(b.mx_f,c.mx_f);
	a.mn_z=min(b.mn_z,c.mn_z);
	a.mn_f=min(b.mn_f,c.mn_f);
	return ;
}
void build(int x,int l,int r,int c){
	int mid=l+r>>1;
	t[x][c].l=l,t[x][c].r=r;
	if(l==r){
		t[x][c]={l,r,a[l][c]>0,a[l][c]<0,a[l][c]==0,a[l][c],a[l][c],a[l][c]>0?a[l][c]:0,a[l][c]<0?a[l][c]:-0x3f3f3f3f,a[l][c]>0?a[l][c]:0x3f3f3f3f,a[l][c]<0?a[l][c]:0};
		return ;
	}
	build(x<<1,l,mid,c);
	build(x<<1|1,mid+1,r,c);
	merge(t[x][c],t[x<<1][c],t[x<<1|1][c]); 
	return ;
}
int len(int x,int c){
	return t[x][c].r-t[x][c].l+1;
} 
node find(int x,int l,int r,int c){
	if(l<=t[x][c].l&&t[x][c].r<=r)return t[x][c];
	node ans={0,0,0,0,0,-0x3f3f3f3f,0x3f3f3f3f,0,-0x3f3f3f3f,0x3f3f3f3f,0};
	int mid=t[x][c].l+t[x][c].r>>1;
	if(l<=mid){
		node s=find(x<<1,l,r,c);
		merge(ans,ans,s);
	}
	if(mid<r){
		node s=find(x<<1|1,l,r,c);
		merge(ans,ans,s);
	}
	return ans;
}
void solve(){
	//puts("S");
	int l1,r1,l2,r2;
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	node a=find(1,l1,r1,0);
	node b=find(1,l2,r2,1);
	//cnt1正，cnt2负,cnt零 
	if(a.cnt1==0){
		if(b.cnt1==0){
			printf("%lld\n",1ll*a.mn*b.mx); 
			return ;
		}
		if(b.cnt2==0){
			printf("%lld\n",1ll*a.mx*b.mx);
			return ;
		}
		printf("%lld\n",1ll*a.mx*b.mx);
	}
	else if(a.cnt2==0){
		if(b.cnt1==0){
			printf("%lld\n",1ll*a.mn*b.mn);
			return ;
		}
		if(b.cnt2==0){
			printf("%lld\n",1ll*a.mx*b.mn);
			return ;
		}
		printf("%lld\n",1ll*a.mn*b.mn);
	}
	else {
		if(b.cnt1==0){
			printf("%lld\n",1ll*a.mn*b.mx);
			return ;	
		}
		if(b.cnt2==0){
			printf("%lld\n",1ll*a.mx*b.mn);
			return ;
		}
		if(a.cnt)printf("0\n");
		else {
			printf("%lld\n",max(1ll*a.mx_f*b.mx_z,1ll*a.mn_z*b.mn_f));
		}
	}
	return ;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t=0;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)scanf("%d",&a[i][0]);
	for(int i=1;i<=m;i++)scanf("%d",&a[i][1]); 
	build(1,1,n,0);
	build(1,1,m,1);
	while(t--)solve();
	return 0;
}

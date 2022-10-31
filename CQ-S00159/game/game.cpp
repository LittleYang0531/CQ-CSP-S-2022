#include<iostream>
#include<cstdio>
using namespace std;
int tmn[4][400010],tmx[4][400010],a[100010],b[100010];
int sum0[100010],sum1[100010],sum2[100010];
void pup(int num,int k){
	tmn[num][k]=min(tmn[num][k*2],tmn[num][k*2+1]);
	tmx[num][k]=max(tmx[num][k*2],tmx[num][k*2+1]);
	return;
}
void bud(int num,int k,int l,int r){
	if(l==r){
		if(num==1){
			tmn[1][k]=tmx[1][k]=b[l];
		}
		if(num==0){
			tmn[0][k]=tmx[0][k]=a[l];
		}
		if(num==2){
			if(a[l]<0)tmn[2][k]=tmx[2][k]=a[l];
			else tmn[2][k]=tmx[2][k]=-0x3f3f3f3f;
		}
		if(num==3){
			if(a[l]>0)tmn[3][k]=tmx[3][k]=a[l];
			else tmn[3][k]=tmx[3][k]=0x3f3f3f3f;
		}
		return;
	}
	int mid=(l+r)>>1;
	bud(num,k*2,l,mid);
	bud(num,k*2+1,mid+1,r);
	pup(num,k);
	return;
}
int ask(int num,int k,int l,int r,int x,int y,bool typ){
	if(x<=l&&r<=y){
		if(typ){
			return tmx[num][k];
		}else{
			return tmn[num][k];
		}
	}
	int mid=(l+r)>>1;
	if(typ){
		int rt=-0x3f3f3f3f;
		if(x<=mid)rt=max(rt,ask(num,k*2,l,mid,x,y,typ));
		if(y>mid)rt=max(rt,ask(num,k*2+1,mid+1,r,x,y,typ));
		return rt;
	}else{
		int rt=0x3f3f3f3f;
		if(x<=mid)rt=min(rt,ask(num,k*2,l,mid,x,y,typ));
		if(y>mid)rt=min(rt,ask(num,k*2+1,mid+1,r,x,y,typ));
		return rt;
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum0[i]=sum0[i-1];
		sum1[i]=sum1[i-1];
		sum2[i]=sum2[i-1];
		if(a[i]<0)sum0[i]++;
		if(a[i]==0)sum1[i]++;
		if(a[i]>0)sum2[i]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	bud(1,1,1,m);
	bud(0,1,1,n);
	bud(2,1,1,n);
	bud(3,1,1,n);
	for(int i=1;i<=q;i++){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long ans=-0x3f3f3f3f3f3f3f3f;
		if(sum0[r1]-sum0[l1-1]>0){
			ans=max(ans,1ll*ask(2,1,1,n,l1,r1,true)*ask(1,1,1,m,l2,r2,true));
			ans=max(ans,1ll*ask(0,1,1,n,l1,r1,false)*ask(1,1,1,m,l2,r2,true));
		}
		if(sum2[r1]-sum2[l1-1]>0){
			ans=max(ans,1ll*ask(0,1,1,n,l1,r1,true)*ask(1,1,1,m,l2,r2,false));
			ans=max(ans,1ll*ask(3,1,1,n,l1,r1,false)*ask(1,1,1,m,l2,r2,false));
		}
		if(sum1[r1]-sum1[l1-1]>0){
			ans=max(ans,0ll);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/

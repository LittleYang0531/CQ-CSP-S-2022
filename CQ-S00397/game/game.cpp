#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
#define ll long long
const ll INF=1e18+5;
int n,m,q,l1,r1,l2,r2;
ll a[MAXN],b[MAXN],maxz,minz,maxf,minf,tmp;
struct SG{
	struct ren{
		int l,r;
		ll maxn,minn;
	}t[MAXN<<2];
	void pup(int p){t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);}
	void bui(int id,int p,int l,int r){
		t[p].l=l;t[p].r=r;
		if(l==r){
			if(id==1){
				if(a[l]>=0){
					t[p].maxn=t[p].minn=a[l];
				}
				else t[p].maxn=-INF,t[p].minn=INF;
			}
			else if(id==2){
				if(a[l]<0){
					t[p].maxn=t[p].minn=a[l];
				}
				else t[p].maxn=-INF,t[p].minn=INF;
			}
			else{
				t[p].maxn=t[p].minn=b[l];
			}
			return;
		}
		int mid=(l+r)>>1;
		bui(id,p<<1,l,mid);bui(id,p<<1|1,mid+1,r);
		pup(p);
	}
	ll sea(bool f,int p,int l,int r){
//		printf("PP:%d %d %lld\n",t[p].l,t[p].r,t[p].maxn);
		if(t[p].l>=l&&t[p].r<=r){
			if(f) return t[p].maxn;
			else return t[p].minn;
		}
		int mid=(t[p].l+t[p].r)>>1;
		ll tmp;
		if(f){
			tmp=-INF;
			if(l<=mid) tmp=max(tmp,sea(f,p<<1,l,r));
			if(r>mid) tmp=max(tmp,sea(f,p<<1|1,l,r));
			return tmp;
		}
		else{
			tmp=INF;
			if(l<=mid) tmp=min(tmp,sea(f,p<<1,l,r));
			if(r>mid) tmp=min(tmp,sea(f,p<<1|1,l,r));
			return tmp;
		}
	}
}T1,T2,T3;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%5lld ",a[i]*b[i]);
//		}
//		printf("\n");
//	}
	T1.bui(1,1,1,n);
	T2.bui(2,1,1,n);
	T3.bui(3,1,1,m);
//	printf("CCCCCCCCCCCCCC:%lld\n",T1.sea(1,1,2,3));
	for(int i=1;i<=q;i++){
		tmp=-INF;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		maxz=T1.sea(1,1,l1,r1),minz=T1.sea(0,1,l1,r1),maxf=T2.sea(1,1,l1,r1),minf=T2.sea(0,1,l1,r1);
		ll mi=T3.sea(0,1,l2,r2),ma=T3.sea(1,1,l2,r2);
//		printf("RE:%lld %lld %lld %lld\n",maxz,minz,maxf,minf);
		if(maxz!=-INF){
			tmp=max(tmp,maxz*mi);
		}
		if(minz!=INF){
			tmp=max(tmp,minz*mi);
		}
		if(maxf!=-INF){
			tmp=max(tmp,maxf*ma);
		}
		if(minf!=INF){
			tmp=max(tmp,minf*ma);
		}
		printf("%lld\n",tmp);
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/

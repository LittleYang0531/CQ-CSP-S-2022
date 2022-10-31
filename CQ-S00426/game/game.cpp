#include<bits/stdc++.h>
using namespace std;

//T2£¬Ã»ÓÐ1 

const int N = 1e5+10;

int n,m,q,a[N],b[N],mada,madb,mida,midb,la,lb,ra,rb,alingz,alingf;

struct node{
	int l,r,mina,maxa,maxb,minb,zhenglinga,fulinga;
}tr[N*4];

void pushup(int u){
	tr[u].mina=min(tr[u<<1].mina,tr[u<<1|1].mina);
	tr[u].minb=min(tr[u<<1].minb,tr[u<<1|1].minb);
	tr[u].maxa=max(tr[u<<1].maxa,tr[u<<1|1].maxa);
	tr[u].maxb=max(tr[u<<1].maxb,tr[u<<1|1].maxb);
	tr[u].zhenglinga=min(tr[u<<1].zhenglinga,tr[u<<1|1].zhenglinga);
	tr[u].fulinga=max(tr[u<<1].fulinga,tr[u<<1|1].fulinga);
}

void mtree(int l,int r,int u){
	if(l==r){
		tr[u]={l,l,a[l],a[l],b[r],b[r],0,0};
		tr[u].zhenglinga=a[l]>=0?a[l]:1e9;
		tr[u].fulinga=a[l]<=0?a[l]:-1e9;
		if(r>n){
			tr[u].maxa=-1e9,tr[u].mina=1e9,tr[u].zhenglinga=1e9,tr[u].fulinga=-1e9;
		}
		if(r>m) tr[u].maxb=-1e9,tr[u].minb=1e9;
		
		return ;
	}
	int mid=l+r>>1;
	mtree(l,mid,u<<1);
	mtree(mid+1,r,u<<1|1);
	tr[u]={l,r};
	pushup(u);
}

void merge(int L,int R,int u,int ab) {
	if(tr[u].r<L || tr[u].l>R) return;
	if(L<=tr[u].l && tr[u].r<=R){
		if(ab==1){//a-->1    b-->0
			mada=max(tr[u].maxa,mada);
			mida=min(tr[u].mina,mida);
			alingz=min(alingz,tr[u].zhenglinga);
			alingf=max(alingf,tr[u].fulinga);
		}
		else{
			madb=max(tr[u].maxb,madb);
			midb=min(tr[u].minb,midb);
		}
		return ;
	}
	if(tr[u].r>=L) merge(L,R,u<<1|1,ab);
	if(tr[u].l<=R) merge(L,R,u<<1,ab);
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	mtree(1,max(n,m),1);
	while(q--){
		scanf("%d%d%d%d",&la,&ra,&lb,&rb);
		alingz=mida=midb=1e9;alingf=mada=madb=-1e9;
		merge(la,ra,1,1);merge(lb,rb,1,0);
		if(midb<0 && madb>0) {
			printf("%lld\n",max(1ll*alingz*midb,1ll*alingf*madb));
		}
		else if(midb>0 && madb>0) {
			printf("%lld\n",min(1ll*midb*mada,1ll*madb*mada));
			continue;
		}
		else{
			printf("%lld\n",min(1ll*madb*mida,1ll*midb*mida));
			continue;
		}
	}
	
	return 0;
}

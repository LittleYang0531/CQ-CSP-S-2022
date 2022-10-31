#include<bits/stdc++.h>
#define ls(i) i<<1
#define rs(i) i<<1^1
using namespace std;
const int N=1e5+5,inf=1e9+7;
const long long inff=1e18+7;
int n,m,q;
struct tree{
	long long maxn,minn;
}ta[6*N],tb[6*N];
long long a[N],b[N];
void builda(int le,int ri,int x){
	if(le==ri){
		ta[x].maxn=a[le];
		ta[x].minn=a[le];
		return;
	}
	int mid=(le+ri)>>1;
	builda(le,mid,ls(x));
	builda(mid+1,ri,rs(x));
	ta[x].maxn=max(ta[ls(x)].maxn,ta[rs(x)].maxn);
	ta[x].minn=min(ta[ls(x)].minn,ta[rs(x)].minn);
}
void buildb(int le,int ri,int x){
	if(le==ri){
		tb[x].maxn=b[le];
		tb[x].minn=b[le];
		return;
	}
	int mid=(le+ri)>>1;
	buildb(le,mid,ls(x));
	buildb(mid+1,ri,rs(x));
	tb[x].maxn=max(tb[ls(x)].maxn,tb[rs(x)].maxn);
	tb[x].minn=min(tb[ls(x)].minn,tb[rs(x)].minn);
}
long long findmina(int ql,int qr,int le,int ri,int x){
	if(ql<=le&&qr>=ri)return ta[x].minn;
	long long ret=inf;
	int mid=(le+ri)>>1;
	if(ql<=mid)ret=min(ret,findmina(ql,qr,le,mid,ls(x)));
	if(qr>mid)ret=min(ret,findmina(ql,qr,mid+1,ri,rs(x)));
	return ret;
}
long long findmaxa(int ql,int qr,int le,int ri,int x){
	if(ql<=le&&qr>=ri)return ta[x].maxn;
	long long ret=-inf;
	int mid=(le+ri)>>1;
	if(ql<=mid)ret=max(ret,findmaxa(ql,qr,le,mid,ls(x)));
	if(qr>mid)ret=max(ret,findmaxa(ql,qr,mid+1,ri,rs(x)));
	return ret;
}
long long findmaxb(int ql,int qr,int le,int ri,int x){
	if(ql<=le&&qr>=ri)return tb[x].maxn;
	long long ret=-inf;
	int mid=(le+ri)>>1;
	if(ql<=mid)ret=max(ret,findmaxb(ql,qr,le,mid,ls(x)));
	if(qr>mid)ret=max(ret,findmaxb(ql,qr,mid+1,ri,rs(x)));
	return ret;
}
long long findminb(int ql,int qr,int le,int ri,int x){
	if(ql<=le&&qr>=ri)return tb[x].minn;
	long long ret=inf;
	int mid=(le+ri)>>1;
	if(ql<=mid)ret=min(ret,findminb(ql,qr,le,mid,ls(x)));
	if(qr>mid)ret=min(ret,findminb(ql,qr,mid+1,ri,rs(x)));
	return ret;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	    scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	    scanf("%lld",&b[i]);
	builda(1,n,1);
	buildb(1,n,1);
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l2==r2){
			if(b[l2]<0)printf("%lld\n",b[l2]*findmina(l1,r1,1,n,1));
			else printf("%lld\n",b[l2]*findmaxa(l1,r1,1,n,1));
			continue;
		}
		long long ans=-inff;
		for(int i=l1;i<=r1;i++){
			if(a[i]<0){
				ans=max(ans,a[i]*findmaxb(l2,r2,1,n,1));
			}
			else{
				ans=max(ans,a[i]*findminb(l2,r2,1,n,1));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//Ô¤¼ÆµÃ·Ö75 QwQ 

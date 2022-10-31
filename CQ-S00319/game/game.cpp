#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e5+10;
inline int read(){
	int x=0;
	bool flag=false;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	if(flag)return -x;
	return x;
}
struct tree{
	int l,r;
	int Min,Max;
	int ne1,ne2;
	bool li_0;
};
struct segment_tree{
	tree tr[N<<2];
	void pushup(tree &U,tree &L,tree &R){
		U.Max=max(L.Max,R.Max);
		U.Min=min(L.Min,R.Min);
		U.li_0=L.li_0||R.li_0;
		if(U.li_0)
			U.ne1=U.ne2=0;
		else{
			U.ne1=min(L.ne1,R.ne1);
			U.ne2=max(L.ne2,R.ne2);
		}
	}
	void pushup(int u){
		pushup(tr[u],tr[u<<1],tr[u<<1|1]);
	}
	void build(int u,int l,int r,int a[]){
		tr[u]=(tree){l,r};
		if(l==r){
			tr[u].Max=tr[u].Min=a[l];
			tr[u].li_0=a[l]==0;
			tr[u].ne1=2e9;
			tr[u].ne2=-2e9;
			if(tr[u].li_0){
				tr[u].ne1=tr[u].ne2=0;
				return;
			}
			if(a[l]>0)tr[u].ne1=a[l];
			else tr[u].ne2=a[l];
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid,a);
		build(u<<1|1,mid+1,r,a);
		pushup(u);
	}
	tree query(int u,int l,int r){
		if(tr[u].l>=l&&tr[u].r<=r)
			return tr[u];
		int mid=tr[u].l+tr[u].r>>1;
		if(mid>=r)return query(u<<1,l,r);
		if(mid<l)return query(u<<1|1,l,r);
		tree U,L,R;
		L=query(u<<1,l,r),R=query(u<<1|1,l,r);
		pushup(U,L,R);
		return U;
	}
}tr1,tr2;
int a[N],b[N];
int n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	tr1.build(1,1,n,a);
	tr2.build(1,1,m,b);
	int l1,r1,l2,r2;
	tree A,B;
	while(q--){
		l1=read(),r1=read();
		l2=read(),r2=read();
		A=tr1.query(1,l1,r1);
		B=tr2.query(1,l2,r2);
		if(B.Min<=0&&B.Max>=0){
			printf("%lld",max(1ll*A.ne1*B.Min,1ll*A.ne2*B.Max));
		}
		else if(B.Min>0){
			if(A.Max<0)
				printf("%lld",1ll*A.Max*B.Max);
			else
				printf("%lld",1ll*A.Max*B.Min);
		}
		else{
			if(A.Min>0)
				printf("%lld",1ll*A.Min*B.Min);
			else
				printf("%lld",1ll*A.Min*B.Max);
		}
		putchar('\n');
	}
	return 0;
} 

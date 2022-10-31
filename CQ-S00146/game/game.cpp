#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
const int N=1e5+10;
int val[N],b[N],a[N],n,m;
struct tr{
	int mi;
};
	tr t1[N<<2];
	void pushup1(int k,int pd){
		if(pd>1)
		t1[k].mi=min(t1[k<<1].mi,t1[k<<1|1].mi);
		else t1[k].mi=t1[k<<1].mi;
	}
	void build1(int l,int r,int k){
		if(l==r){
			t1[k].mi=val[l];
			return ;
		}
		int mid=(l+r)>>1;
		int pd=0;
		if(mid>=l)build1(l,mid,k<<1),pd++;
		if(mid<r)build1(mid+1,r,k<<1|1),pd++;
		pushup1(k,pd);
	}
	int query1(int l,int r,int k,int L,int R){
		if(L<=l&&R>=r){
			return t1[k].mi;
		}
		int mid=(l+r)>>1,res=1e16;
		if(mid>=L)res=query1(l,mid,k<<1,L,R);
		if(mid<R)res=min(res,query1(mid+1,r,k<<1|1,L,R));
		return res;
	}
void solve1(int l1,int l2,int r2){
	int x=query1(1,m,1,l2,r2);
	printf("%lld\n",x*a[l1]);
}

	tr t2[N<<2];
	void pushup2(int k,int pd){
//		if(pd>1)
		t2[k].mi=max(t2[k<<1].mi,t2[k<<1|1].mi);
//		else t2[k].mi=t2[k<<1].mi;
	}
	void build2(int l,int r,int k){
		if(l==r){
			t2[k].mi=val[l];
			return ;
		}
		int mid=(l+r)>>1;
		int pd=0;
//		if(mid>=l)
		build2(l,mid,k<<1),pd++;
//		if(mid<r)
		build2(mid+1,r,k<<1|1),pd++;
		pushup2(k,pd);
	}
	int query2(int l,int r,int k,int L,int R){
		if(L<=l&&R>=r){
			return t2[k].mi;
		}
		int mid=(l+r)>>1,res=-1e15;
		if(mid>=L)res=query2(l,mid,k<<1,L,R);
		if(mid<R)res=max(res,query2(mid+1,r,k<<1|1,L,R));
		return res;
	}
void solve2(int l1,int l2,int r2){
	int x=query2(1,n,1,l2,r2);
	printf("%lld\n",x*b[l1]);
}
void solve3(int q){
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		val[i]=read();
	}
	build1(1,m,1);
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		int x=query1(1,m,1,l2,r2),ans=a[l1]*x;
		for(int i=l1+1;i<=r1;i++){
			ans=max(ans,a[i]*x);
		}
		printf("%lld\n",ans);
	}
}

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	int f1=1,f2=1;
	int q=read();
	
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<0)f1=0;
		val[i]=a[i];
	}
	build2(1,n,1);
//	cout<<query2(1,n,1,1,n)<<endl;
	for(int i=1;i<=m;i++){
		b[i]=read();
		if(b[i]<0)f2=0;
		val[i]=b[i];
	}
	build1(1,m,1);
	if(n<=2000&&m<=2000&&q<=2000&&f1&&f2){
		solve3(q);
		return 0;
	}
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(l1==r1){
			solve1(l1,l2,r2);continue;
		}
		else if(l2==r2){
			solve2(l2,l1,r1);continue;
		}
	}
	return 0;
}

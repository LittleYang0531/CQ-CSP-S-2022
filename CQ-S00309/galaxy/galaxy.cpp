#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
int n,m,q;
unordered_set<int>G[500005],M[500005];
struct ST{
	struct Node{
		int l,r,minn,maxn;
	}c[20000005];
	void Build(int q,int l,int r){
		c[q].l=l,c[q].r=r,c[q].maxn=c[q].minn=0;
		if(l==r)return;
		int mid=l+r>>1;
		Build(q<<1,l,mid);
		Build(q<<1|1,mid+1,r);
	}
	void Add(int q,int x,int y){
		if(c[q].l==c[q].r){
			c[q].maxn+=y;
			c[q].minn+=y;
			return;
		}
		int mid=c[q].l+c[q].r>>1;
		if(x<=mid)Add(q<<1,x,y);
		else Add(q<<1|1,x,y);
		c[q].maxn=max(c[q<<1].maxn,c[q<<1|1].maxn);
		c[q].minn=min(c[q<<1].minn,c[q<<1|1].minn); 
	}
	int Getmax(int q,int l,int r){
		if(l<=c[q].l&&c[q].r<=r)return c[q].maxn;
		int mid=c[q].l+c[q].r>>1,res=0;
		if(l<=mid)res=max(res,Getmax(q<<1,l,r));
		if(mid<r)res=max(res,Getmax(q<<1|1,l,r));
		return res;
	}
	int Getmin(int q,int l,int r){
		if(l<=c[q].l&&c[q].r<=r)return c[q].minn;
		int mid=c[q].l+c[q].r>>1,res=INT_MAX;
		if(l<=mid)res=min(res,Getmin(q<<1,l,r));
		if(mid<r)res=min(res,Getmin(q<<1|1,l,r));
		return res;
	}
}T;
struct node{
	int op,x,y;
}t[500005];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	T.Build(1,1,n);
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),M[v].insert(u),T.Add(1,u,1);
	q=read();
	bool f=0;
	for(int i=1;i<=q;i++){
		t[i].op=read();
		if(t[i].op&1)t[i].x=read(),t[i].y=read();
		else f=1,t[i].x=read();
	}
	int op,x,y,Min,Max;
	for(int i=1;i<=q;i++){
		op=t[i].op;
		if(op==1){
			x=t[i].x,y=t[i].y;
			T.Add(1,x,-1);
			if(f){
				G[y].insert(x);
				M[y].erase(M[y].find(x));
			}
		}
		else if(op==2){
			x=t[i].x;
			for(auto i:M[x])T.Add(1,i,-1),G[x].insert(i);
			M[x].clear();
		}
		else if(op==3){
			x=t[i].x,y=t[i].y;
			T.Add(1,x,1);
			if(f){
				G[y].erase(G[y].find(x));
				M[y].insert(x);
			}
		}
		else{
			x=t[i].x;
			for(auto i:G[x])T.Add(1,i,1),M[x].insert(i);
			G[y].clear();
		}
		Min=T.Getmin(1,1,n);Max=T.Getmax(1,1,n);
		if(Min==1&&Max==1)puts("YES");
		else puts("NO");
	}
	return 0;
}

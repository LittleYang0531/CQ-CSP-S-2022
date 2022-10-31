#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
namespace shik{
	const ll inf=1e18;
	const int N=2e5+5;
	int lim;
	struct matrix{
		ll a[3][3];
		matrix operator*(const matrix &b)const
		{
			
			matrix c;
			for(int i=0;i<lim;i++)
			for(int j=0;j<lim;j++)c.a[i][j]=inf;
			ll res;
			for(int i=0;i<lim;i++)
			for(int k=0;k<lim;k++)if((res=a[i][k])<inf)
			for(int j=0;j<lim;j++)c.a[i][j]=min(c.a[i][j],res+b.a[k][j]);
			return c;
		}
		matrix operator+(const matrix &b)const
		{
			matrix c;
			for(int i=0;i<lim;i++)c.a[i][0]=inf;
			ll res;
			for(int i=0;i<lim;i++)
			for(int k=0;k<lim;k++)if((res=a[i][k])<inf)c.a[i][0]=min(c.a[i][0],res+b.a[k][0]);
			return c;
		}
		void cons(int v,ll v2)
		{
			for(int i=0;i<lim;i++)a[0][i]=v;
			for(int i=1;i<lim;i++)
			for(int j=0;j<lim;j++)if(j!=i-1)a[i][j]=inf;
			if(lim>=3)a[1][1]=v2;
		}
	};
	struct node{
		int l,r;
		matrix w,w2;
	}q[N<<2];
	#define lc (x<<1)
	#define rc ((x<<1)|1)
	struct edge{
		int x,y;
	}g[N<<1];
	int fa[N],k[N],si[N],er[N],t[N],df[N],idf[N],v[N],d[N];
	ll v2[N];
	int su=0,tot=0;
	vector<pair<int,int> >res;
	inline char gc()
	{
		static char buf[1<<16],*S,*T;
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,1<<16,stdin);
			if(S==T)return EOF;
		}
		return *(S++);
	}
	#define getchar gc
	inline ll read()
	{
		char h=getchar();
		ll y=0,q=1;
		while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
		while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
		return y*q;
	}
	inline void add(int a,int b){g[++su]=(edge){k[a],b};k[a]=su;}
	inline void pushup(int x){q[x].w=q[lc].w*q[rc].w;q[x].w2=q[rc].w2*q[lc].w2;}
	void build(int x,int l,int r)
	{
		q[x].l=l;q[x].r=r;
		if(l==r)return (void)(q[x].w.cons(v[idf[l]],v2[idf[l]]),q[x].w2.cons(v[idf[l]],v2[idf[l]]));
		int m=(l+r)>>1;
		build(lc,l,m);build(rc,m+1,r);
		pushup(x);
	}
	void query(int x,int l,int r,int ty,matrix &ans)
	{
		if(l>q[x].r||q[x].l>r)return;
		if(q[x].l>=l&&q[x].r<=r)return (void)(ans=(ty?q[x].w:q[x].w2)+ans);
		if(ty)query(rc,l,r,ty,ans),query(lc,l,r,ty,ans);
		else query(lc,l,r,ty,ans),query(rc,l,r,ty,ans);
	}
	void dfs1(int x)
	{
		si[x]=1;
		for(int y,i=k[x];i;i=g[i].x)if((y=g[i].y)!=fa[x])
		{
			fa[y]=x;d[y]=d[x]+1;
			dfs1(y);
			si[x]+=si[y];
			if(si[er[x]]<si[y])er[x]=y;
		}
	}
	void dfs2(int x,int to)
	{
		t[x]=to;df[x]=++tot;idf[tot]=x;v2[x]=inf;
		if(!er[x])return;
		dfs2(er[x],to);
		for(int i=k[x];i;i=g[i].x)if(!t[g[i].y])dfs2(g[i].y,g[i].y);
	}
	inline ll Tquery(int x,int y)
	{
		matrix ans;
		for(int i=0;i<lim;i++)ans.a[i][0]=(i==lim-1?0:inf);
		res.clear();
		while(t[x]!=t[y])
		{
			if(d[t[x]]>d[t[y]])
			{
				res.push_back(make_pair(df[t[x]],df[x]));
				x=fa[t[x]];
			}
			else
			{
				query(1,df[t[y]],df[y],1,ans);
				y=fa[t[y]];
			}
		}
		if(d[x]<d[y])query(1,df[x],df[y],1,ans);
		else query(1,df[y],df[x],0,ans);
		for(int i=res.size()-1;~i;i--)query(1,res[i].first,res[i].second,0,ans);
		return ans.a[0][0];
	}
	int main()
	{
		freopen("transmit.in","r",stdin);
		freopen("transmit.out","w",stdout);
		int n=read(),m=read();lim=read();
		for(int i=1;i<=n;i++)v[i]=read();
		for(int a,b,i=1;i<n;i++)a=read(),b=read(),add(a,b),add(b,a);
		dfs1(1);dfs2(1,1);
		for(int i=1;i<=n;i++)v2[i]=inf;
		for(int i=1;i<=n;i++)
		for(int j=k[i];j;j=g[j].x)v2[i]=min(v2[i],(ll)v[g[j].y]);
		build(1,1,n);
		while(m--)
		{
			int x=read(),y=read();
			cout<<Tquery(x,y)<<"\n";
		}
		return 0;
	}
}
signed main(){return shik::main();}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7

4 7
5 6
1 2
*/

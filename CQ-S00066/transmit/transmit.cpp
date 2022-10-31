#include<bits/stdc++.h>
namespace ifzw{
#define ll long long
#define dd double
#define LL __int128
#define ull unsigned ll
#define uLL __uint128_t 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=2e5+5;
int n,Q,k;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
//改成 lct 就差一个 upd log^2。 
//是不是可以树上倍增啊 是吧 ？   
int dfx[xx],dep[xx],f[xx],siz[xx],son[xx],top[xx],val[xx],mn[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,f[x]=y,siz[x]=1;
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>mx)mx=siz[e[i].to],son[x]=e[i].to;
	}
}
int cst;
void dfss(int x,int y)
{
	top[x]=y,dfx[x]=++cst;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]<dep[y])return x;
	return y;
}
namespace k1
{
	ll s[xx];
	void pre(int x,int y)
	{
		s[x]=s[y]+val[x];
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			pre(e[i].to,x);
		}
	}
	void solve()
	{
		pre(1,0);
		while(Q--)
		{
			int x=read(),y=read(),L=lca(x,y);
			cout<<s[x]+s[y]-s[L]-s[f[L]]<<"\n";
		}
	}
}
namespace jps
{
	ll dp[xx];
	struct nd
	{
		int x;
		ll ds;
		bool operator<(const nd&w)const
		{
			return ds>w.ds;
		}
	};
	priority_queue<nd>q;
	int pr[xx];
	void upd(int x,ll v,int y)
	{
		if(dp[x]>v)
			dp[x]=v,pr[x]=y,q.push({x,v});
	}
	int vis[xx];
	void runbf(int x)
	{
		for(int i=1;i<=n;i++)dp[i]=1e18,vis[x]=0;
		dp[x]=val[x];
		q.push({x,val[x]});
		while(!q.empty())
		{
			int x=q.top().x;
//			cerr<<x<<"$\n";
			q.pop();
			if(vis[x])continue;
			vis[x]=1;
			for(int i=h[x];i;i=e[i].next)
			{
				int A=e[i].to;
				upd(A,dp[x]+val[A],x);
				for(int i=h[A];i;i=e[i].next)
				{
					int B=e[i].to;
					upd(B,dp[x]+val[B],x);
					for(int i=h[B];i;i=e[i].next)
					{
						int C=e[i].to;
						upd(C,dp[x]+val[C],x);
					}
				}
			}
		}
	}
	ll ls[xx];
	void solve()
	{
		while(Q--)
		{
			int x=read(),y=read();
//			runbf(x);
//			cout<<dp[y]<<"#\n";
//			vector<int>lin;
//			lin.push_back(y);
//			while(y!=x)
//			{
//				y=pr[y];
//				lin.push_back(y);
//			}
//			for(auto it:lin)cout<<it<<"\n";
//			exit(0);
			if(dep[x]<dep[y])swap(x,y);
			basic_string<int>z1,z2,id;
			while(dep[x]!=dep[y])
				z1.push_back(x),x=f[x];
			while(x!=y)
				z1.push_back(x),x=f[x],z2.push_back(y),y=f[y];
			z1.push_back(x);
			reverse(z2.begin(),z2.end());
			id=z1+z2;
			for(auto it:id)dp[it]=ls[it]=1e18;
			dp[id[0]]=val[id[0]];
			int sz=id.size();
			for(int i=0;i<=sz;i++)ls[i]=1e18;
//			cerr<<sz<<"$\n";
			for(int i=1;i<sz;i++)
			{
				x=id[i];
				for(int j=i-1;j>=i-k;j--)
				{
					if(j<0)continue;
					dp[x]=min(dp[x],val[x]+dp[id[j]]);
				}
				if(k==3)
				{
					ls[i]=ls[i-1]+mn[x];
					if(i>=2)ls[i]=min(ls[i],dp[id[i-2]]+mn[id[i]]);
					//出两步。 
					if(i>=2)dp[x]=min(dp[x],ls[i-2]+val[x]);
//					if(i>=4)
//						dp[x]=min(dp[x],dp[id[i-4]]+mn[id[i-2]]+val[x]);
				}
			}
			//注意到可以在中间转中间点。 
//			for(auto it:id)cout<<it<<" ";
//			puts("");
			cout<<dp[id[sz-1]]<<"\n";
		}
	}
}
struct mc
{
	ll a[2][2];
	int st[2],ed[2],sz;
};
mc operator+(const mc&A,const mc&B)
{
	if(!A.sz)return B;
	if(!B.sz)return A;
	mc c;
	c.sz=A.sz+B.sz;
//	if(A.sz==1&&B.sz==1)
//	{
//		int x=A.st[0],y=B.st[0];
//		c={val[x],val[x]+val[y],(ll)1e18,val[y],x,y,x,y,2};
//	}
//	else 
//	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c.a[i][j]=1e18;
				for(int a=0;a<=1;a++)
				{
					for(int b=0;b<=1;b++)
					{
						if(a==0&&b==1)continue;
						c.a[i][j]=min(c.a[i][j],A.a[i][a]+val[B.st[b]]+B.a[b][j]);
					}
				}
			}
		}
		c.st[0]=A.st[0];
		c.st[1]=A.st[1];
		c.ed[0]=B.ed[0];
		c.ed[1]=B.ed[1];
		if(A.sz==1)c.st[1]=B.st[0];
		if(B.sz==1)c.ed[0]=A.ed[1];
//	}
	return c;
}
mc dp[xx][19];
mc dw[xx][19];
int jp[xx][19];
const ll inf=1e18;
mc gone(int i)
{
	return (mc){val[i],inf,inf,inf,i,0,0,i,1};
}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),Q=read(),k=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0),dfss(1,1);
	if(k==1)
	{
		k1::solve();
		return 0;
	}
	int md=*max_element(dep+1,dep+n+1);
	for(int x=1;x<=n;x++)
	{
		mn[x]=val[x];
		for(int i=h[x];i;i=e[i].next)mn[x]=min(mn[x],val[e[i].to]);
	}
	if(md<=100||(n<=2000&&Q<=2000))
	{
		jps::solve();
		exit(0);
	}
	//70 pts。 
	//剩下就是写矩阵了 5^4 * log 。 
	//最后 15 pts 不要了。 
	if(k==2)
	{
		for(int i=1;i<=n;i++)dp[i][0]=gone(i);
		for(int i=1;i<=n;i++)dw[i][0]=gone(i);
		for(int i=1;i<=n;i++)jp[i][0]=f[i];
		for(int j=1;j<=18;j++)for(int i=1;i<=n;i++)jp[i][j]=jp[jp[i][j-1]][j-1];
		for(int j=1;j<=18;j++)for(int i=1;i<=n;i++)if(jp[i][j])dp[i][j]=dp[i-1][j]+dp[jp[i][j]][j-1];
		for(int j=1;j<=18;j++)for(int i=1;i<=n;i++)if(jp[i][j])dw[i][j]=dw[jp[i][j]][j-1]+dw[i-1][j];
		
		while(Q--)
		{
			int x=read(),y=read();
			int L=lca(x,y);
			mc nw={},li={};
			while(dep[x]>dep[L])
			{
				nw=nw+dp[x][__lg(dep[x]-dep[L])];
				x=jp[x][__lg(dep[x]-dep[L])];
			}
			while(dep[y]>dep[L])
			{
				li=dw[y][__lg(dep[y]-dep[L])]+li;
				y=jp[y][__lg(dep[y]-dep[L])];
			}
			nw=nw+gone(L)+li;
			cout<<nw.a[0][1]<<"\n";
		}
		
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}

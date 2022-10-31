#include<bits/stdc++.h>
using namespace std;
namespace CSP2022_Senior_2022_10_29
{
	namespace IO
	{
		const int buf_size=1<<20;
		char buf[buf_size],*S,*T;
		inline char read_char()
		{
			if(S==T)
				T=(S=buf)+fread(buf,1,buf_size,stdin);
			return S!=T?*(S++):EOF;
		}
		inline int read_int()
		{
			char c=read_char();
			bool neg=false;
			while(c<'0'||c>'9')
			{
				neg=(c=='-');
				c=read_char();
			}
			int x=0;
			while(c>='0'&&c<='9')
			{
				x=x*10+(c^'0');
				c=read_char();
			}
			return neg?-x:x;
		}
		char fw[buf_size];
		int pw;
		inline void flush()
		{
			fwrite(fw,1,pw,stdout);
			pw=0;
		}
		inline void write_char(char x)
		{
			fw[pw++]=x;
			if(pw==buf_size)
				flush();
		}
		inline void write_ll(long long x)
		{
			if(!x)
			{
				write_char('0');
				return;
			}
			if(x<0)
			{
				write_char('-');
				x=-x;
			}
			char st[26];
			int tp=0;
			while(x)
			{
				st[++tp]=x%10^'0';
				x/=10;
			}
			while(tp>0)
				write_char(st[tp--]);
		}
	}
	int n,q,k;
	const int max_n=2e5+5;
	const int max_Q=2e5+5;
	int End[max_n<<1],Last[max_n],Next[max_n<<1],E=1;
	inline void add_edge(int x,int y)
	{
		End[++E]=y,Next[E]=Last[x],Last[x]=E;
		End[++E]=x,Next[E]=Last[y],Last[y]=E;
	}
	int v[max_n],s[max_Q],t[max_Q];
	/*
	namespace Solution_1
	{
		int dep[max_n],fath[max_n],son[max_n],sz[max_n];
		void dfs1(int x,int fa)
		{
			dep[x]=dep[fa]+1;
			fath[x]=fa;
			sz[x]=1;
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(y!=fa)
				{
					dfs1(y,x);
					sz[x]+=sz[y];
					if(sz[y]>sz[son[x]])
						son[x]=y;
				}
			}
		}
		int tp[max_n];
		void dfs2(int x,int tp_now)
		{
			tp[x]=tp_now;
			if(son[x])
			{
				dfs2(son[x],tp_now);
				for(int i=Last[x];i;i=Next[i])
				{
					int y=End[i];
					if(y!=fath[x]&&y!=son[x])
						dfs2(y,y);
				}
			}
		}
		inline int get_LCA(int x,int y)
		{
			while(tp[x]!=tp[y])
			{
				if(dep[tp[x]]<dep[tp[y]])
					swap(x,y);
				x=fath[tp[x]];
			}
			return dep[x]<dep[y]?x:y;
		}
		int val[max_n];
		long long dp[max_n];
		inline void solve()
		{
			dfs1(1,0),dfs2(1,1);
			for(int i=1;i<=Q;++i)
			{
				int S=s[i],T=t[i],p=get_LCA(S,T),x=S,sz=0;
				while(x!=fath[p])
				{
					val[++sz]=v[x];
					x=fath[x];
				}
				int now=sz;
				x=T;
				while(x!=p)
				{
					val[++sz]=v[x];
					x=fath[x];
				}
				reverse(val+now+1,val+sz+1);
				if(i==5)
				{
					for(int i=1;i<=sz;++i)
						fprintf(stderr,"i=%d val[i]=%d\n",i,val[i]);
				}
				dp[1]=val[1];
				for(int i=2;i<=sz;++i)
				{
					dp[i]=1e18;
					for(int j=1;j<=k&&i-j>=1;++j)
						dp[i]=min(dp[i],dp[i-j]+val[i]);
				}
				IO::write_ll(dp[sz]);
				IO::write_char('\n');
			}
		}
	}
	*/
	namespace Solution_1
	{
		const int max_n=2e3+5;
		int d[max_n][max_n];
		void dfs(int x,int fa,int rt)
		{
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(y!=fa)
				{
					d[rt][y]=d[rt][x]+1;
					dfs(y,x,rt);
				}
			}
		}
		vector<int> edge[max_n];
		long long dis[max_n];
		typedef pair<long long,int> P;
		priority_queue<P,vector<P>,greater<P> > Q;
		inline void dijkstra(int s)
		{
			for(int i=1;i<=n;++i)
				dis[i]=1e18;
			dis[s]=v[s];
			Q.push(P(v[s],s));
			while(!Q.empty())
			{
				int x=Q.top().second;
				long long d=Q.top().first;
				Q.pop();
				if(dis[x]<d)
					continue;
				for(int y:edge[x])
				{
					if(dis[y]>dis[x]+v[y])
					{
						dis[y]=dis[x]+v[y];
						Q.push(P(dis[y],y));
					}
				}
			}
		}
		inline void solve()
		{
			for(int i=1;i<=n;++i)
				dfs(i,0,i);
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
				{
					if(d[i][j]<=k)
						edge[i].push_back(j);
				}
			for(int i=1;i<=q;++i)
			{
				int S=s[i],T=t[i];
				dijkstra(S);
				IO::write_ll(dis[T]);
				IO::write_char('\n');
			}
		}
	}
	namespace Solution_2
	{
		int dep[max_n],fath[max_n],son[max_n],sz[max_n];
		long long sum[max_n];
		void dfs1(int x,int fa)
		{
			dep[x]=dep[fa]+1;
			sum[x]=sum[fa]+v[x];
			fath[x]=fa;
			sz[x]=1;
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(y!=fa)
				{
					dfs1(y,x);
					sz[x]+=sz[y];
					if(sz[y]>sz[son[x]])
						son[x]=y;
				}
			}
		}
		int tp[max_n];
		void dfs2(int x,int tp_now)
		{
			tp[x]=tp_now;
			if(son[x])
			{
				dfs2(son[x],tp_now);
				for(int i=Last[x];i;i=Next[i])
				{
					int y=End[i];
					if(y!=fath[x]&&y!=son[x])
						dfs2(y,y);
				}
			}
		}
		inline int get_LCA(int x,int y)
		{
			while(tp[x]!=tp[y])
			{
				if(dep[tp[x]]<dep[tp[y]])
					swap(x,y);
				x=fath[tp[x]];
			}
			return dep[x]<dep[y]?x:y;
		}
		inline void solve()
		{
			dfs1(1,0),dfs2(1,1);
			for(int i=1;i<=q;++i)
			{
				int S=s[i],T=t[i];
				IO::write_ll(sum[S]+sum[T]-sum[get_LCA(S,T)]*2+v[get_LCA(S,T)]);
				IO::write_char('\n');
			}
		}
	}
	int main()
	{
		freopen("transmit.in","r",stdin);
		freopen("transmit.out","w",stdout);
		n=IO::read_int(),q=IO::read_int(),k=IO::read_int();
		for(int i=1;i<=n;++i)
			v[i]=IO::read_int();
		for(int i=1;i<=n-1;++i)
		{
			int a=IO::read_int(),b=IO::read_int();
			add_edge(a,b);
		}
		for(int i=1;i<=q;++i)
			s[i]=IO::read_int(),t[i]=IO::read_int();
		if(k==1)
			Solution_2::solve();
		else if(n<=2e3&&q<=2e3)
			Solution_1::solve();
		IO::flush();
		return 0;
	}
}
int main()
{
	return CSP2022_Senior_2022_10_29::main();
}



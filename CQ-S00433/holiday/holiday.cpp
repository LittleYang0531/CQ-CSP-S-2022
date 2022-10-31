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
		inline long long read_ll()
		{
			char c=read_char();
			bool neg=false;
			while(c<'0'||c>'9')
			{
				neg=(c=='-');
				c=read_char();
			}
			long long x=0;
			while(c>='0'&&c<='9')
			{
				x=x*10+(c^'0');
				c=read_char();
			}
			return neg?-x:x;
		}
	}
	const int max_n=2500+5;
	const int max_m=1e4+5;
	int End[max_m<<1],Last[max_n],Next[max_m<<1],E=1;
	inline void add_edge(int x,int y)
	{
		End[++E]=y,Next[E]=Last[x],Last[x]=E;
		End[++E]=x,Next[E]=Last[y],Last[y]=E;
	}
	long long s[max_n];
	int id[max_n];
	inline bool cmp(int x,int y)
	{
		return s[x]>s[y];
	}
	int dis[max_n][max_n]; // about 24 MiB
	int que[max_n],n,m,k;
	inline void BFS(int s)
	{
		for(int i=1;i<=n;++i)
			dis[s][i]=1e9;
		dis[s][s]=0;
		int sz=0;
		que[++sz]=s;
		for(int t=1;t<=sz;++t)
		{
			int x=que[t],d=dis[s][x];
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(dis[s][y]==1e9)
				{
					dis[s][y]=d+1;
					que[++sz]=y;
				}
			}
		}
	}
	int cand[max_n][8],sz[max_n];
	int main()
	{
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
		n=IO::read_int(),m=IO::read_int(),k=IO::read_int()+1;
		for(int i=2;i<=n;++i)
			s[i]=IO::read_ll();
		for(int i=1;i<=m;++i)
		{
			int x=IO::read_int(),y=IO::read_int();
			add_edge(x,y);
		}
		for(int i=1;i<=n;++i)
			BFS(i);
		int tot=0;
		for(int i=2;i<=n;++i)
		{
			if(dis[1][i]<=k)
				id[++tot]=i;
		}
		sort(id+1,id+tot+1,cmp);
		for(int x=2;x<=n;++x)
			for(int j=1;j<=tot&&sz[x]<4;++j)
			{
				int y=id[j];
				if(dis[x][y]<=k)
					cand[x][++sz[x]]=y;
			}
		long long ans=0;
		for(int B=2;B<=n;++B)
			for(int C=B+1;C<=n;++C)
			{
				if(dis[B][C]>k)
					continue;
				for(int i=1;i<=sz[B];++i)
				{
					int A=cand[B][i];
					if(A==B||A==C)
						continue;
					for(int j=1;j<=sz[C];++j)
					{
						int D=cand[C][j];
						if(D==A||D==B||D==C)
							continue;
						ans=max(ans,s[A]+s[B]+s[C]+s[D]);
//						if(s[A]+s[B]+s[C]+s[D]==30)
//							fprintf(stderr,"A=%d B=%d C=%")
					}
				}
			}
		assert(ans>=4);
		printf("%lld\n",ans);
		return 0;
	}
}
int main()
{
	return CSP2022_Senior_2022_10_29::main();
}



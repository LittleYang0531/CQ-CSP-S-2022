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
		inline void write_int(int x)
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
	inline void YES()
	{
		IO::write_char('Y');
		IO::write_char('E');
		IO::write_char('S');
		IO::write_char('\n');
	}
	inline void NO()
	{
		IO::write_char('N');
		IO::write_char('O');
		IO::write_char('\n');
	}
	int n,m,q;
	const int max_n=5e5+5;
	const int max_m=5e5+5;
	const int max_q=5e5+5;
	int u[max_m],v[max_m];
	struct Order
	{
		int t,u,v;
	}O[max_q];
	namespace Solution_1
	{
		inline bool check()
		{
			return n<=1e3&&m<=1e4&&q<=1e3;
		}
		const int max_n=1e3+5;
		const int max_m=1e4+5;
		int End[max_m],Last[max_n],Next[max_m],E; // complement graph
		inline void add_edge(int x,int y)
		{
			End[++E]=y;
			Next[E]=Last[x];
			Last[x]=E;
		}
		int cnt[max_n];
		multiset<int> S;
		inline void del(int x)
		{
			S.erase(S.find(cnt[x]));
		}
		inline void add(int x)
		{
			S.insert(cnt[x]);
		}
		typedef pair<int,int> P;
		map<P,bool> exist,ok;
		inline void solve()
		{
			for(int i=1;i<=m;++i)
			{
				add_edge(v[i],u[i]);
				++cnt[u[i]];
				exist[P(u[i],v[i])]=true;
				ok[P(u[i],v[i])]=true;
			}
			for(int i=1;i<=n;++i)
				S.insert(cnt[i]);
			for(int i=1;i<=q;++i)
			{
				int t=O[i].t,u=O[i].u,v=O[i].v;
				if(t==1)
				{
					del(u);
					--cnt[u];
					add(u);
					assert(exist[P(u,v)]&&ok[P(u,v)]);
					ok[P(u,v)]=false;
				}
				else if(t==3)
				{
					del(u);
					++cnt[u];
					add(u);
					assert(exist[P(u,v)]&&!ok[P(u,v)]);
					ok[P(u,v)]=true;
				}
				else if(t==2)
				{
					for(int k=Last[u];k;k=Next[k])
					{
						int v=End[k];
						if(ok[P(v,u)])
						{
							ok[P(v,u)]=false;
							del(v);
							--cnt[v];
							add(v);
						}
					}
				}
				else
				{
					for(int k=Last[u];k;k=Next[k])
					{
						int v=End[k];
						if(!ok[P(v,u)])
						{
							ok[P(v,u)]=true;
							del(v);
							++cnt[v];
							add(v);
						}
					}
				}
				if(*S.begin()==1&&*S.rbegin()==1)
					YES();
				else
					NO();
			}
		}
	}
	namespace Solution_2
	{
		inline bool check()
		{
			for(int i=1;i<=q;++i)
			{
				if(O[i].t==4)
					return false;
			}
			return true;
		}
		int End[max_m],Last[max_n],Next[max_m],E; // complement graph
		inline void add_edge(int x,int y)
		{
			End[++E]=y;
			Next[E]=Last[x];
			Last[x]=E;
		}
		int cnt[max_n];
		multiset<int> S;
		inline void del(int x)
		{
			S.erase(S.find(cnt[x]));
		}
		inline void add(int x)
		{
			S.insert(cnt[x]);
		}
		vector<int> repair[max_n];
		bool mark[max_n];
		typedef pair<int,int> P;
		map<P,bool> ok;
		inline void solve()
		{
			for(int i=1;i<=m;++i)
			{
				add_edge(v[i],u[i]);
				++cnt[u[i]];
				ok[P(u[i],v[i])]=true;
			}
			for(int i=1;i<=n;++i)
				S.insert(cnt[i]);
			for(int i=1;i<=q;++i)
			{
				int t=O[i].t,u=O[i].u,v=O[i].v;
				if(t==1)
				{
					del(u);
					--cnt[u];
					add(u);
					assert(ok[P(u,v)]);
					ok[P(u,v)]=false;
				}
				else if(t==3)
				{
					del(u);
					++cnt[u];
					add(u);
					repair[v].push_back(u);
					assert(!ok[P(u,v)]);
					ok[P(u,v)]=true;
				}
				else
				{
					assert(t==2);
					if(mark[u])
					{
						for(int x:repair[u])
						{
							if(!ok[P(x,u)])
								continue;
							ok[P(x,u)]=false;
							del(x);
							--cnt[x];
							add(x);
						}
						repair[u].clear();
					}
					else
					{
						mark[u]=true;
						for(int k=Last[u];k;k=Next[k])
						{
							int v=End[k];
							if(ok[P(v,u)])
							{
								ok[P(v,u)]=false;
								del(v);
								--cnt[v];
								add(v);
							}
						}
						repair[u].clear();
					}
				}
				if(*S.begin()==1&&*S.rbegin()==1)
					YES();
				else
					NO();
			}
		}
	}
	int main()
	{
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
		n=IO::read_int(),m=IO::read_int();
		for(int i=1;i<=m;++i)
			u[i]=IO::read_int(),v[i]=IO::read_int();
		q=IO::read_int();
		for(int i=1;i<=q;++i)
		{
			O[i].t=IO::read_int(),O[i].u=IO::read_int();
			if(O[i].t==1||O[i].t==3)
				O[i].v=IO::read_int();
		}
		if(Solution_1::check())
			Solution_1::solve();
		else if(Solution_2::check())
			Solution_2::solve();
		IO::flush();
		return 0;
	}
}
int main()
{
	return CSP2022_Senior_2022_10_29::main();
}



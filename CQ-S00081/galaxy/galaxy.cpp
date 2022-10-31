#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
template<typename T>inline void read(T &a)
{
	a = 0;
	int f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c))	a = a * 10 + c - 48,c = getchar();
	a *= f;
}

template<typename T,typename ...L>inline void read(T&a,L&...l)
{
	read(a),read(l...);
}

template<typename T>inline void write(T &a)
{
	T x = a;
	char ch[20];
	int top = 0;
	if(x < 0)
		putchar('-'),x = -x;
	do{
		ch[top++] = x % 10 + '0',x /= 10;
	}while(x);
	while(top--)
		putchar(ch[top]);
	putchar('\n');
}

template<typename T,typename ...L>inline void write(T&a,L&...l)
{
	write(a),write(l...);
}

set<int> st[N];
vector<int> vc[N];
int n,m,q,t,u,v,dout[N];//tcl，只能写暴力了（悲） 
map<int,int> mp;

bool check()
{
	return (signed)mp.size() == 1 && (mp.begin()->first) == 1;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;i++)
	{
		read(u,v);
		st[v].insert(u); 
		vc[v].push_back(u);
		dout[u]++;
	}
	for(int i=1;i<=n;i++)
		mp[dout[i]]++;
	st[v].insert(INT_MAX);
	scanf("%d",&q);
	while(q--)
	{
		read(t);
		if(t == 1)
		{
			read(u,v);
			mp[dout[u]]--;
			if(mp[dout[u]] == 0)
				mp.erase(dout[u]);
			dout[u]--;
			mp[dout[u]]++;
			st[v].erase(u);
		 } 
		else if(t == 2)
		{
			read(v);
			for(auto it = st[v].begin();it != st[v].end();it++)
			{
				u = *it;
				if(u == INT_MAX)	break;
				mp[dout[u]]--;
				if(mp[dout[u]] == 0)
					mp.erase(dout[u]);
				dout[u]--;
				mp[dout[u]]++;
			}
			st[v].clear();
		}
		else if(t == 3)
		{
			read(u,v);
			mp[dout[u]]--;
			if(mp[dout[u]] == 0)
				mp.erase(dout[u]);
			dout[u]++;
			mp[dout[u]]++;
			st[v].insert(u);
		}
		else///ll复杂度假了 
		{
			read(v);
			for(int i=0;i<(signed)vc[v].size();i++)
			{
				if(*st[v].lower_bound(vc[v][i]) == vc[v][i]) continue;
				int u = vc[v][i];
				mp[dout[u]]--;
				if(mp[dout[u]] == 0)
					mp.erase(dout[u]);
				dout[u]++;
				mp[dout[u]]++;
				st[v].insert(u);
			 } 
		}
		if(check())
		{
			putchar('Y');
			putchar('E');
			putchar('S');
			putchar('\n');
		}
		else
		{
			putchar('N');
			putchar('O');
			putchar('\n');
		}
	}
}


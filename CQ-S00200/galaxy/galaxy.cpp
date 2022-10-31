/*
wonwon~ wonderhoy!
Wonderhoy!
Wonderhoy wonderhoy wa hohou!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))	f=(c=='-'?-1:f),c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
//set<int> S[50005],T[500005];
unordered_set<int> S[500005],T[500005];
int n,m;
int deg[500005];
int sr;
inline void add(int c)
{
	if(deg[c]==1)	++sr;
	++deg[c];
	if(deg[c]==1)	--sr;
}
inline void sub(int c)
{
	if(deg[c]==1)	++sr;
	--deg[c];
	if(deg[c]==1)	--sr;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	LL c=0;
	n=read(),m=read();
	sr=n;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		S[v].insert(u);
		add(u);
	}
	int q=read();
	while(q-->0)
	{
		int op=read();
		if(op==1)
		{
			int u=read(),v=read();
			T[v].insert(u);
			S[v].erase(S[v].find(u));
			++c;
			sub(u);
		}
		if(op==3)
		{
			int u=read(),v=read();
			S[v].insert(u);
			T[v].erase(T[v].find(u));
			++c;
			add(u);
		}
		if(op==2)
		{
			int v=read();
			for(auto u:S[v])	T[v].insert(u),sub(u);
			c+=LL(S[v].size());
			S[v].clear();
		}
		if(op==4)
		{
			int v=read();
			for(auto u:T[v])	S[v].insert(u),add(u);
			c+=LL(T[v].size());
			T[v].clear();
		}
		puts(sr?"NO":"YES");
	}
//	printf("%lld\n",c);
	return 0;
}

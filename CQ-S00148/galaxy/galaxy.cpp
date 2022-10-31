#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>

template<typename T>
inline void read(T &a)
{
	char c;
	bool flag=0;
	while(!isdigit(c=getchar()))
		flag|=(c=='-');
	a=0;
	for(a=c-'0';isdigit(c=getchar());a=a*10+c-'0');
	flag&&(a=-a);
}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10,M=5e4+10;
int n,m,q;
int h[N],e[M],ne[M],idx;
inline void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool visp[N],vise[M];
int din[N],dout[N];
set<int> zero;

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(visp,1,sizeof visp);
	memset(vise,1,sizeof vise);
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		din[v]++,dout[u]++;
		add(u,v);
	}
	for(int i=1;i<=n;i++)	if(dout[i]==0)	zero.emplace(i); 
	read(q);
	while(q--)
	{
		int t,u,v;
		read(t);
		if(t==1)
		{
			read(u),read(v);
			din[v]--;
			dout[u]--;
			if(dout[u]==0)	zero.emplace(u);
		}else if(t==1)
		{
			read(u),read(v);
			if(dout[u]==0)	zero.erase(zero.find(u));
			dout[u]++;
			din[v]++;
		}
		puts(zero.empty()?"YES":"NO");
	}
	
	return 0;
}


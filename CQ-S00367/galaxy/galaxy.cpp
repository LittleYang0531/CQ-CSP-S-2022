#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace pokopoko
{
int read()
{
	int bj=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')bj=-1;
	int x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	return x*bj;
}
const int N=5e5+5;
int n,m,q;
struct node{int x,y;}a[N];
namespace sub1
{
	const int N=1005;
	int u[N][N],e[N][N],c[N],t[N];
	void upd(int x,int k){t[c[x]]--,c[x]+=k,t[c[x]]++;}
	int main()
	{
		int o,x,y;
		for(int i=1;i<=m;i++)x=a[i].x,y=a[i].y,u[x][y]=e[x][y]=1,c[x]++;
		for(int i=1;i<=n;i++)t[c[i]]++;
		while(q--)
		{
			o=read();
			if(o==1)x=read(),y=read(),e[x][y]=0,upd(x,-1);
			if(o==2)
			{
				x=read();
				for(int i=1;i<=n;i++)if(e[i][x])e[i][x]=0,upd(i,-1);
			}
			if(o==3)x=read(),y=read(),e[x][y]=1,upd(x,1);
			if(o==4)
			{
				x=read();
				for(int i=1;i<=n;i++)if(u[i][x]&&!e[i][x])e[i][x]=1,upd(i,1);
			}
			printf((t[1]==n)?"YES\n":"NO\n");
		}
		return 0;
	}
}
namespace sub2
{
	const int lim=1e6;
	vector<int> v[N];
	unordered_map<ll,int> mp;
	int c[N],t[N];
	ll bs[N];
	void upd(int x,int k){t[c[x]]--,c[x]+=k,t[c[x]]++;}
	int main()
	{
		int o,x,y;
		for(int i=1;i<=m;i++)x=a[i].x,y=a[i].y,v[y].push_back(x),c[x]++;
		for(int i=1;i<=n;i++)t[c[i]]++,bs[i]=1ll*lim*i;
		while(q--)
		{
			o=read();
			if(o==1)x=read(),y=read(),mp[bs[y]+x]=1,upd(x,-1);
			if(o==2)
			{
				x=read();
				for(auto y:v[x])if(!mp[bs[x]+y])upd(y,-1),mp[bs[x]+y]=1;
				v[x].clear();
			}
			if(o==3)x=read(),y=read(),mp[bs[y]+x]=0,upd(x,1),v[y].push_back(x);
			printf((t[1]==n)?"YES\n":"NO\n");
		}
		return 0;
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read();
	q=read();
	if(n<=1000&&q<=1000)sub1::main();
	else sub2::main();
	return 0;
}
};
int main(){pokopoko::main();return 0;}

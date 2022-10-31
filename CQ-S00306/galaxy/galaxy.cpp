#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,m,q,a[N][N],unable[N][N],d[N];
inline int re()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
bool check()
{
	for(int i=1;i<=n;i++) if(d[i]!=1) return 0;
	return 1;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=re(),m=re();
	for(int i=1,u,v;i<=m;i++) u=re(),v=re(),a[u][v]=1,d[u]++;
	q=re();
	for(int op,u,v;q--;)
	{
		op=re(),u=re();
		if(op==1) unable[u][re()]=1,d[u]--;
		if(op==2) 
		{
			for(int v=1;v<=n;v++)
				if(a[v][u])
				{
					if(!unable[v][u]) d[v]--;
					unable[v][u]=1;
				}
		}
		if(op==3) unable[u][re()]=0,d[u]++;
		if(op==4)
		{
			for(int v=1;v<=n;v++)
				if(a[v][u])
				{
					if(unable[v][u]) d[v]++;
					unable[v][u]=0;
				}
		}
		if(check()) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
d**kwish       \
hhpq			\
push_and_knock   \
junkfood 		  \
multiset		   \				
horse               \                   Orz
chicken(unrated)    /
stasis             /
jason_sun         /
rxm              /
geng            /
captainWei     /
soup          /
*/

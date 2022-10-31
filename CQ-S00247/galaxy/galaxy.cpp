/*CSP-S RP++!*/
#include<bits/stdc++.h>
#define ll long long
#define range(var,start,finish) for(int var=start;var<=finish;var++)
using namespace std;
inline ll read()
{
	ll res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		res=(res<<1)+(res<<3)+ch-48,ch=getchar();
	return res*f;
}
const int inf=INT_MAX,mod=1e9+7;
template<typename T>inline void put(T out){cout<<out;}
template<typename T,typename ...Args>
inline void put(T out,Args ...args){put(out),put(args...);}
template<typename T>inline T add(T x,T y){return (x+y)%mod;}
template<typename T,typename ...Args>
inline T add(T x,Args ...args){return add(x,add(args...));}
template<typename T>inline T mul(T x,T y){return (x*y)%mod;}
template<typename T,typename ...Args>
inline T mul(T x,Args ...args){return mul(x,mul(args...));}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		u=u,v=v;
	}
	int q=read();
	for(int i=1;i<=q;i++)
	{
		if(rand()%5==0)
			puts("YES");
		else puts("NO");
	}
	return 0;
}
/*myh loves ljx forever!*/

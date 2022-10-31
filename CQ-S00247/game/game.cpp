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
const ll inf=LONG_LONG_MAX,mod=1e9+7,maxn=1e5+50;
template<typename T>inline void put(T out){cout<<out;}
template<typename T,typename ...Args>
inline void put(T out,Args ...args){put(out),put(args...);}
template<typename T>inline T add(T x,T y){return (x+y)%mod;}
template<typename T,typename ...Args>
inline T add(T x,Args ...args){return add(x,add(args...));}
template<typename T>inline T mul(T x,T y){return (x*y)%mod;}
template<typename T,typename ...Args>
inline T mul(T x,Args ...args){return mul(x,mul(args...));}
ll x[maxn],y[maxn];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i]=read();
	while(q--)
	{
		ll l1=read(),r1=read(),l2=read(),r2=read();
		ll ans=-inf;
		for(int i=l1;i<=r1;i++)
		{
			ll tmp=inf;
			for(int j=l2;j<=r2;j++) tmp=min(tmp,x[i]*y[j]);
			ans=max(ans,tmp);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*myh loves ljx forever!*/

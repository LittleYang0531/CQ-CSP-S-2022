#include<bits/stdc++.h>
#define inl inline
using namespace std;
const int N=5e5+5;
struct E {int ne,to; }e[N];
int n,m,an,ec,h[N],s[N];
inl int Read()
{
	int s=0; char c; while(!isdigit(c=getchar()));
	for(;isdigit(c);c=getchar()) s=s*10+c-'0'; return s;
}
namespace Hash
{
	struct HA {int ne,x,y; bool v; }ha[N];
	const int ba=13331,ham=99991; int hc,h[ham];
	inl void Insert(int x,int y)
	{
		int t=(1ll*x*ba+y)%ham;
		ha[++hc]=(HA){h[t],x,y,true}; h[t]=hc;
	}
	inl int Get(int x,int y)
	{
		int t=(1ll*x*ba+y)%ham;
		for(int i=h[t];i;i=ha[i].ne)
			if(ha[i].x==x&&ha[i].y==y) return i;
	}
}
inl void Add(int y,int x)
{
	e[++ec]=(E){h[y],x}; h[y]=ec;Hash::Insert(x,y); ++s[x];
}
inl void Ad(int p) {an-=s[p]==1; an+=(++s[p])==1; }
inl void De(int p) {an-=s[p]==1; an+=(--s[p])==1; }
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=Read(); m=Read(); for(int i=1;i<=m;++i) Add(Read(),Read());
	for(int i=1;i<=n;++i) an+=s[i]==1;
	for(int T=Read(),op,x,y;T;puts(an==n?"YES":"NO"),--T)
		if((op=Read())==1) x=Read(), y=Read(), Hash::ha[Hash::Get(x,y)].v=false, De(x);
		else if(op==3) x=Read(), y=Read(), Hash::ha[Hash::Get(x,y)].v=true, Ad(x);
		else if(op==2)
		{
			for(int i=h[y=Read()],t;i;i=e[i].ne)
				if(Hash::ha[t=Hash::Get(x=e[i].to,y)].v) Hash::ha[t].v=false, De(x);
		}
		else
		{
			for(int i=h[y=Read()],t;i;i=e[i].ne)
				if(!Hash::ha[t=Hash::Get(x=e[i].to,y)].v) Hash::ha[t].v=true, Ad(x);
		}
	return 0;
}

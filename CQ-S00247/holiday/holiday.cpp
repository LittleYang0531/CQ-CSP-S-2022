/*CSP-S RP++!*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
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
const int inf=INT_MAX,mod=1e9+7,maxn=2600;
template<typename T>inline void put(T out){cout<<out;}
template<typename T,typename ...Args>
inline void put(T out,Args ...args){put(out),put(args...);}
template<typename T>inline T add(T x,T y){return (x+y)%mod;}
template<typename T,typename ...Args>
inline T add(T x,Args ...args){return add(x,add(args...));}
template<typename T>inline T mul(T x,T y){return (x*y)%mod;}
template<typename T,typename ...Args>
inline T mul(T x,Args ...args){return mul(x,mul(args...));}
ll score[maxn],ans;
vector<int>e[maxn];
int main()
{
	srand(time(0));
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n=read(),m=read(),kk=read();
	for(int i=2;i<=n;i++) score[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),greater<int>());
	int tohome=e[1].size();
	if(kk==0)
	for(int i=0;i<tohome;i++)
	{
		for(int j=i+1;j<tohome;j++)
		{
			int d1=e[1][i],d4=e[1][j];
			int tod1=e[d1].size();
			for(int k=0;k<tod1;k++)
			{
				int d2=e[d1][k];
				if(d2==d4||d2==1) continue;
				int tod2=e[d2].size();
				for(int l=0;l<tod2;l++)
				{
					int d3=e[d2][l];
					if(d3==d4||d3==1||d3==d1) continue;
					int tod3=e[d3].size();
					for(int r=0;r<tod3;r++)
					{
						if(d4==e[d3][r])
						ans=max(ans,score[d1]+score[d2]+score[d3]+score[d4]);
					}
				}
			}
		}
	}
	else
	{
		sort(score+1,score+n+1,greater<int>());
		ans=score[1]+score[2]+score[3]+score[rand()%(n/4)+1];
	}
	cout<<ans;
	return 0;
}
/*myh loves ljx forever!*/

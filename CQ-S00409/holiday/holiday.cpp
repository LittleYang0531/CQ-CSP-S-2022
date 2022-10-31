#include<bits/stdc++.h>
#define inl inline
using namespace std;
typedef long long ll;
const int N=2505,M=1e4+5;
struct E {int ne,to; }e[M*2];
int n,m,K,ec,h[N],dis[N],f[N][3]; ll an,a[N];
bool vst[N][N];
queue<int> q[2];
inl ll Read()
{
	ll s=0,f=1; char c; while(!isdigit(c=getchar())) c=='-'&&(f=-f);
	for(;isdigit(c);c=getchar()) s=s*10+c-'0'; return s*f;
}
inl void Add(int x,int y)
{
	e[++ec]=(E){h[x],y}; h[x]=ec;
	e[++ec]=(E){h[y],x}; h[y]=ec;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=Read(); m=Read(); K=Read()+1;
	for(int i=2;i<=n;++i) a[i]=Read();
	while(m--) Add(Read(),Read());
	for(int i=1;i<=n;++i)
	{
		while(!q[0].empty()) q[0].pop(); while(!q[1].empty()) q[1].pop();
		memset(dis,-1,sizeof(dis)); dis[i]=0; q[0].push(i);
		for(int j=1,la=0,no=1;j<=K;++j,la=no,no^=1)
		{
			for(;!q[la].empty();q[la].pop())
			{
				int u=q[la].front();
				for(int k=h[u];k;k=e[k].ne)
				{
					int v=e[k].to; if(~dis[v]) continue;
					dis[v]=j; vst[i][v]=true; q[no].push(v);
				}
			}
		}
	}
	for(int i=2;i<=n;++i) if(!vst[1][i]) continue;
		else for(int j=2;j<=n;++j) if(!vst[i][j]) continue;
			else if(a[i]>a[f[j][0]]) f[j][2]=f[j][1], f[j][1]=f[j][0], f[j][0]=i;
			else if(a[i]>a[f[j][1]]) f[j][2]=f[j][1], f[j][1]=i;
			else if(a[i]>a[f[j][2]]) f[j][2]=i;
	for(int i=2;i<=n;++i) for(int j=2;j<=n;++j) if(!vst[i][j]) continue;
		else for(int pi=0;pi<3&&f[i][pi];++pi) for(int pj=0;pj<3&&f[j][pj];++pj)
			if(f[i][pi]!=j&&f[j][pj]!=i&&f[i][pi]!=f[j][pj])
				an=max(an,a[i]+a[j]+a[f[i][pi]]+a[f[j][pj]]);
	printf("%lld\n",an);
	return 0;
}

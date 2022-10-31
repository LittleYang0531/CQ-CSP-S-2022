#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace pokopoko
{
const int N=3005;
int n,m,q;
vector<int> v[N],e[N];
ll ans,a[N];
int d[N],mx[N],sx[N],tx[N];
void bfs(int x)
{
	int o=x;
	queue<int> tq;
	for(int i=1;i<=n;i++)d[i]=-1;
	tq.push(x);d[x]=0;
	while(!tq.empty())
	{
		x=tq.front(),tq.pop();
		for(auto y:e[x])if(d[y]==-1)d[y]=d[x]+1,tq.push(y);
	}
	for(int i=1;i<=n;i++)if(d[i]>0&&d[i]<=q)v[o].push_back(i);
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int x,y;
	scanf("%d %d %d",&n,&m,&q);q++;
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d %d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++)bfs(i);
	for(auto k3:v[1])
		for(auto k2:v[k3])
		{
			if(a[k3]>a[mx[k2]])tx[k2]=sx[k2],sx[k2]=mx[k2],mx[k2]=k3;
			else if(a[k3]>a[sx[k2]])tx[k2]=sx[k2],sx[k2]=k3;
			else if(a[k3]>a[tx[k2]])tx[k2]=k3;
		}
	for(int k1=2;k1<=n;k1++)
	{
		for(auto k2:v[k1])
		{
			x=((mx[k1]!=k2)?mx[k1]:sx[k1]);
			y=((mx[k2]!=k1&&mx[k2]!=x)?mx[k2]:((sx[k2]!=k1&&sx[k2]!=x)?sx[k2]:tx[k2]));
			if(x&&y)ans=max(ans,a[k1]+a[k2]+a[x]+a[y]);
			y=((mx[k2]!=k1)?mx[k2]:sx[k2]);
			x=((mx[k1]!=k2&&mx[k1]!=y)?mx[k1]:((sx[k1]!=k2&&sx[k1]!=y)?sx[k1]:tx[k1]));
			if(x&&y)ans=max(ans,a[k1]+a[k2]+a[x]+a[y]);
		}
	}
	printf("%lld",ans);
	return 0;
}
};
int main(){pokopoko::main();return 0;}

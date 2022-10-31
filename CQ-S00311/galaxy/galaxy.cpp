#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2505;
int n,m,q,t;
struct graph{
	int g[N][N];
	int rd[N],cd[N];
}ori,now;
bitset<N> vst;
bool infff(int r)
{
	vst.set(r);
	for(int y=1;y<=n;y++) 
	{
		if(now.g[r][y] && vst[y]) return true;
		else if(now.g[r][y] && infff(y)) return true;
	}
	return false;
}
void check()
{
	for(int i=1;i<=n;i++) if(now.cd[i]!=1) return void(puts("NO"));
	for(int i=1;i<=n;i++)
	{
		vst.reset();
		if(!infff(i)) return void(puts("NO"));
	}
	puts("YES");
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		ori.g[x][y]++;ori.cd[x]++,ori.rd[y]++;
		now.g[x][y]++;now.cd[x]++,now.rd[y]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d %d",&x,&y);
			now.g[x][y]=0; now.cd[x]--,now.rd[y]--;
		}
		else if(t==2)
		{
			scanf("%d",&x);
			for(int i=1;i<=n;i++)
				if(now.g[i][x]) now.g[i][x]=0,now.cd[i]--,now.rd[y]--; 
		}
		else if(t==3)
		{
			scanf("%d %d",&x,&y);
			now.g[x][y]=1; now.cd[x]++,now.rd[y]++;
		}
		else
		{
			scanf("%d",&x);
			for(int i=1;i<=n;i++)
			{
				if(!now.g[i][x] && ori.g[i][x]) now.g[i][x]=1,now.cd[i]++,now.rd[x]++;
			}
		}
		check();
	}
	return 0;
}

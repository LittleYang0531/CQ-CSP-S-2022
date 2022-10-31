#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[2505],x,y,d[2505][2505],ans;
bool f[2505];
vector<int> v[2505];
queue<int> q;
void hs()
{
	q.push(1);
	while(q.size())
	{
		int w=q.front();
		q.pop();
		for(int i=0; i<v[w].size(); ++i)
		{
			int x=v[w][i];
			d[x][w]=0,d[w][x]=0;
			for(int j=1; j<=n; ++j) if(j!=w && j!=x) d[w][j]=min(d[w][j],d[x][j]+1),d[j][w]=min(d[j][w],d[x][j]+1);
			for(int j=1; j<=n; ++j) if(j!=w && j!=x) d[x][j]=min(d[x][j],d[w][j]+1),d[j][x]=min(d[j][x],d[w][j]+1);
			if(!f[x]) q.push(x);
			f[x]=1;
		}
	}
	return;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(d,1000000,sizeof d);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	hs();
	for(int i=2; i<=n; ++i)
		if(d[1][i]<=k)
			for(int ii=2; ii<=n; ++ii)
				if(d[i][ii]<=k)
					for(int iii=2; iii<=n; ++iii)
						if(d[ii][iii]<=k && iii!=i)
							for(int iiii=2; iiii<=n; ++iiii)
								if(d[iii][iiii]<=k && d[iiii][1]<=k && iiii!=i && iiii!=ii)
									ans=max(ans,a[i]+a[ii]+a[iii]+a[iiii]);
	printf("%d",ans);
	return 0;
}

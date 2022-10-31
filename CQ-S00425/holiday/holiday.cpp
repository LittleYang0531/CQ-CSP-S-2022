#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2505,M=20005;
const ll inf=2e18;

int n,m,k,idx;
int head[N],dist[N][N],mid[N][2];
ll ans;
ll val[N],maxn[N][3];
queue<int> q;
struct edge
{
	int fr,to,ne;
}e[M];

void add(int x,int y)
{
	e[++idx].fr=x;
	e[idx].to=y;
	e[idx].ne=head[x];
	head[x]=idx;
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	//freopen("holiday3.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&val[i]);
		maxn[i][0]=maxn[i][1]=maxn[i][2]=-inf;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int s=1;s<=n;s++)
	{
		while(!q.empty())q.pop();
		memset(dist[s],0x3f,sizeof dist[s]);
		q.push(s);
		dist[s][s]=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].to;
				//cout<<i<<"   ----   "<<v<<"   ----   "<<dist[i][v]<<endl;
				if(dist[s][v]>dist[s][u]+1)
				{
					dist[s][v]=dist[s][u]+1;
					q.push(v);
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			cout<<i<<"    "<<j<<"   "<<dist[i][j]<<endl;*/
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(i!=j&&dist[1][i]<=k&&dist[i][j]<=k)
			{
				if(val[i]+val[j]>maxn[j][0])
				{
					maxn[j][2]=maxn[j][1];
					maxn[j][1]=maxn[j][0];
					mid[j][1]=mid[j][0];
					maxn[j][0]=val[i]+val[j];
					mid[j][0]=i;
				}
				else if(val[i]+val[j]>maxn[j][1])
				{
					maxn[j][2]=maxn[j][1];
					maxn[j][1]=val[i]+val[j];
					mid[j][1]=i;
				}
				else if(val[i]+val[j]>maxn[j][2])
				{
					maxn[j][2]=val[i]+val[j];
				}
			}
	/*for(int i=2;i<=n;i++)
	{
		cout<<i<<"  -----   "<<maxn[i][0]<<"   -----   "<<maxn[i][1]<<"   ---   "<<mid[i][0]<<"   ----   "<<mid[i][1]<<endl;
	}*/
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(i!=j&&dist[i][j]<=k)
			{
				if(mid[i][0]==mid[j][0]||mid[i][0]==j||mid[j][0]==i)
				{
					if(mid[i][0]!=j)
					{
						if(mid[j][1]==mid[i][0]||mid[j][1]==i)ans=max(ans,maxn[i][0]+maxn[j][2]);
						else ans=max(ans,maxn[i][0]+maxn[j][1]);
					}
					if(mid[j][0]!=i)
					{
						if(mid[i][1]==mid[j][0]||mid[i][1]==j)ans=max(ans,maxn[i][2]+maxn[j][0]);
						else ans=max(ans,maxn[i][1]+maxn[j][0]);
					}
					if(mid[i][1]!=mid[j][1]&&mid[i][1]!=j&&mid[j][1]!=i)ans=max(ans,maxn[i][1]+maxn[j][1]);
				}
				else ans=max(ans,maxn[i][0]+maxn[j][0]);
				//cout<<i<<"   ----   "<<j<<"   ---   "<<ans<<endl;
			}
	printf("%lld",ans);
	return 0;
}


/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/



/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/

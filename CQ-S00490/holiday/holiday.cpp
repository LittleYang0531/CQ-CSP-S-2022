#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2505;
const int M=10005;
int n,m,k;
int dis[N][N];//dis[i][j]-i到j所需的转车次数 
ll s[N];
struct EDGE{
	int to,nt,w;
}edge[M<<1];
int cnt,head[N];
void add(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nt=head[u];
	head[u]=cnt;
}

void init()//预处理i到j的路程长度 
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<(dis[i][j]>3000?-1:dis[i][j])<<" ";
		cout<<"\n";
		cin>>n;
	}*/
}


struct POT{
	int id,ti;
	ll w;
	vector<int> vec;
};
bool check(const vector<int> v,const int x)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==x) return false;
	return true;
}
void solve1()
{
	ll dp[N][6];//dp[i][j]-到节点i用了j次所得到的最大值 
	queue<POT> que;
	memset(dp,0,sizeof(dp));
	POT root;
	root.id=1;root.ti=0;root.w=0;root.vec.clear();
	que.push(root);
	while(!que.empty())
	{
		POT u=que.front();
		que.pop();
		if(u.w<dp[u.id][u.ti]||u.ti>4) continue;
		for(int i=head[u.id];i;i=edge[i].nt)
		{
			int v=edge[i].to;
			if(v==1&&u.ti!=4) continue;
			if(dp[v][u.ti+1]<dp[u.id][u.ti]+s[v]&&check(u.vec,v))
			{
				dp[v][u.ti+1]=dp[u.id][u.ti]+s[v];
				u.vec.push_back(v);
				que.push(POT{v,u.ti+1,dp[v][u.ti+1],u.vec});
			}
		}
	}
	printf("%lld\n",dp[1][5]);
}

void solve2()
{
	ll dp[N][6];//dp[i][j]-到节点i用了j次所得到的最大值 
	queue<POT> que;
	memset(dp,0,sizeof(dp));
	POT root;
	root.id=1;root.ti=0;root.w=0;root.vec.clear();
	que.push(root);
	while(!que.empty())
	{
		POT u=que.front();
		que.pop();
		if(u.w<dp[u.id][u.ti]||u.ti>4) continue;
		for(int v=1;v<=n;v++)
		{
			if(v==u.id||dis[u.id][v]>k) continue;
			if(v==1&&u.ti!=4) continue;
			if(dp[v][u.ti+1]<dp[u.id][u.ti]+s[v]&&check(u.vec,v))
			{
				dp[v][u.ti+1]=dp[u.id][u.ti]+s[v];
				u.vec.push_back(v);
				que.push(POT{v,u.ti+1,dp[v][u.ti+1],u.vec});
			}
		}
	}
	printf("%lld\n",dp[1][5]);
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&k);
	k++;//将转车次数变为路径长度 
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dis[x][y]=1;
		dis[y][x]=1;
		add(x,y);
		add(y,x);
	}
	if(k==1) solve1();
	else
	{
		init();
		solve2();
	}
	return 0;
}

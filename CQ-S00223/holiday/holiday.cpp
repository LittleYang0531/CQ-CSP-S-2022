#include<queue> 
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
queue<int> que;
int n,m,k,u,v,mx[2510][3],dep[2510];
bool able[2510][2510];
int head[2510],to[20010],nxt[20010],cntot;
long long ans,s[2510];
void addedge(int one,int ano)
{
	nxt[++cntot]=head[one];
	to[cntot]=ano;
	head[one]=cntot;
	nxt[++cntot]=head[ano];
	to[cntot]=one;
	head[ano]=cntot;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	++k;
	for(int i=2;i<=n;++i)	scanf("%lld",&s[i]);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)	dep[j]=INF;
		dep[i]=0;
		que.push(i);
		while(!que.empty())
		{
			int x=que.front();
			que.pop();
			if(dep[x]==k)	continue;
			for(int j=head[x];j;j=nxt[j])
			{
				int y=to[j];
				if(dep[y]>dep[x]+1)
				{
					dep[y]=dep[x]+1;
					que.push(y);
				}
			}
		}
		for(int j=1;j<=n;++j)
		{
			if(dep[j]<=k&&dep[j])
			{
				able[i][j]=1;
//				fprintf(stderr,"     %d %d\n",i,j); 
			} 
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!able[1][i])	continue;
		for(int j=1;j<=n;++j)
		{
			if(able[i][j])
			{
				if(s[i]>s[mx[j][0]])
				{
					mx[j][2]=mx[j][1];
					mx[j][1]=mx[j][0];
					mx[j][0]=i;
				}
				else if(s[i]>s[mx[j][1]])
				{
					mx[j][2]=mx[j][1];
					mx[j][1]=i;
				}
				else if(s[i]>s[mx[j][2]])	mx[j][2]=i;
			}
		}
	}
	for(int i=2;i<=n;++i)
	{
//		fprintf(stderr,"          %d %d %d\n",mx[i][0],mx[i][1],mx[i][2]);
		for(int j=i+1;j<=n;++j)
		{
			if(!able[i][j])	continue;
			for(int k=0;k<3;++k)
			{
				if(!mx[i][k])	continue;
				for(int l=0;l<3;++l)
				{
					if(!mx[j][l])	continue;
					if(i!=mx[j][l]&&j!=mx[i][k]&&mx[j][l]!=mx[i][k])
					{
						ans=max(ans,s[i]+s[j]+s[mx[i][k]]+s[mx[j][l]]);
//						fprintf(stderr," %d %d %d %d %lld\n",i,j,mx[i][k],mx[j][l],s[i]+s[j]+s[mx[i][k]]+s[mx[j][l]]);
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

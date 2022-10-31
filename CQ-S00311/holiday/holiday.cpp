#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2505;
int n,m,k,tot;
int to1[N],to2[N],to5[N];
ll v[N],Ans;
int ori[N][N];
int g[N][N];
int d[N];
bitset<N> vst;
priority_queue< pair<int,int> > q;
void dij(int st)
{
	vst.reset();
	for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
	d[st]=0; q.push(make_pair(-d[st],st));
	while(q.size())
	{
		int r=q.top().second; q.pop();
		if(vst[r]) continue;
		vst[r]=true;
		for(int y=1;y<=n;y++)
		{
			if(ori[r][y]!=0x3f3f3f3f && !vst[y] && d[y]>d[r]+ori[r][y])
			{
				d[y]=d[r]+ori[r][y];
				q.push(make_pair(-d[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++) g[st][i]=d[i];
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(ori,0x3f,sizeof(ori));
	scanf("%d %d %d",&n,&m,&k);++k;
	for(int i=2;i<=n;ori[i][i]=0,i++) scanf("%lld",v+i);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		ori[x][y]=ori[y][x]=1;
	}
	for(int k=1;k<=n;k++) dij(k);
	for(int i=2;i<=n;i++)
		if(g[1][i]<=k) to1[++tot]=i;
	for(int i=1;i<=tot;i++)
	{
		int s1=to1[i];
		for(int j=i+1;j<=tot;j++)
		{
			int s2=to1[j];
			ll tmp=v[s1]+v[s2];
			for(int s3=2;s3<=n;s3++)
			{
				if(g[s1][s3]>k || s3==s1 || s3==s2) continue;
				for(int s4=2;s4<=n;s4++)
				{
					if(g[s2][s4]>k || g[s3][s4]>k || s4==s1 || s4==s2 || s4==s3) continue;
					Ans=max(Ans,tmp+v[s3]+v[s4]);
//					printf("%d %d %d %d %d\n",s1,s2,s3,s4,tmp+v[s3]+v[s4]);
				}
			}
		}
	}
	printf("%lld\n",Ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int h[40005],cnt;
struct edge{int next,to;}e[40005];
void add(int x,int y){e[++cnt]=(edge){h[x],y},h[x]=cnt;}
int bj[2505],ans,a[2505];
int q[2505],top;

void dfs(int x,int fa,int cnt,int sum)
{
//	cout<<"from "<<fa<<" to "<<x<<" cnt="<<cnt<<endl;
	bj[x]=1;
	q[++top]=x;
	if(cnt>4)
	{
		bj[x]=0;
		return;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==fa)continue;
//		cout<<"x="<<x<<" y="<<y<<endl;
		if(bj[y])
		{
//			cout<<y<<" marked"<<endl;
			if(y==1&&cnt==4)
			{
//				cout<<"return 1 from "<<x<<endl;
//				for(int i=1;i<=top;i++)
//					cout<<q[i]<<" ";
//				cout<<endl;
				ans=max(ans,sum);
			}
			else continue;
		}
		dfs(y,x,cnt+1,sum+a[y]);
	}
	bj[x]=0;
	top--;
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	if(k==0)
	{
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	return 0;
}

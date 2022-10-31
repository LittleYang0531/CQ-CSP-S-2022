#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v;
}b[114514];
//我是zz我应该先开t3的 
bool vis[5005][5005]={false};//判断u-v是否有虫洞 
//以下是从u-v 
int a[5005][5005]={0};//考虑建立邻接矩阵,使用Folyd判断是否联通 
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m,q,ch=0;
	int maxx=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].u,&b[i].v),a[b[i].u][b[i].v]=1,vis[b[i].u][b[i].v]=true,maxx=max(maxx,b[i].u);
	scanf("%d",&q);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			a[u][v]=0;
			ch++;
		 } 
		 if(t==2)
		 {
		 	int u;
		 	scanf("%d",&u);
		 	for(int i=1;i<=maxx;i++)
		 	{
		 		if(vis[i][u]==true)
		 		{
		 			a[i][u]=0;
		 			ch++;
			 	}
			 }
		 }
		 if(t==3)
		 {
		 	int u,v;
			scanf("%d%d",&u,&v);
			a[u][v]=1;
			ch--;
		 }
		 if(t==4)
		 {
		 	int u;
		 	scanf("%d",&u);
		 	for(int i=1;i<=maxx;i++)
		 	{
		 		if(vis[i][u]==true)
		 		{
		 			a[i][u]=1;
		 			ch--;
			 	}
			 }
		 }
		 if(ch==0)
		 {
		 	cout<<"YES\n";
		 }
		 else{
		 	cout<<"NO\n";
		 }
	} 
	return 0;
}


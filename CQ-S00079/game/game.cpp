#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,q;
int a[N];
int b[N];
int vis1[N],vis2[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	int l1,r1,l2,r2;
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1&&l2==r2)
		{
			cout<<a[l1]*b[l2]<<endl;
			continue;
		}
		int u=0,v=1e9;
		for(int i=l1;i<=r1;i++)
			if(vis1[i]==0)u=max(u,a[i]),vis1[i]=1;
		for(int i=l2;i<=r2;i++)
			if(vis2[i]==0)v=min(v,b[i]),vis2[i]=1;
		cout<<u*v<<endl;
	}
	return 0;
}

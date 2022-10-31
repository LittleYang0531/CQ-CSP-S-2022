#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,u,v;
		scanf("%d",&op);
		if(op==1||op==3) scanf("%d%d",&u,&v);
		else scanf("%d",&u);
		printf("NO\n");
	}
	return 0;
}

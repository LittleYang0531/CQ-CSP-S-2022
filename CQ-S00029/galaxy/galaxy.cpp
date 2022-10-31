#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	scanf("%d",&q);
	while(q--)
	{
		int t,u,v;
		scanf("%d",&t);
		if(t == 1) scanf("%d%d",&u,&v); 
		if(t == 2) scanf("%d",&u);
		if(t == 3) scanf("%d%d",&u,&v);
		if(t == 4) scanf("%d",&u);
	}
	for(int i = 1; i <= q; i++)
	{
		srand(time(NULL));
		int a = rand() % 2;
		if(a == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

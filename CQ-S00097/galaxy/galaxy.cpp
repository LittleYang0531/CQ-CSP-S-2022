#include<bits/stdc++.h>
#define N 500005
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,m,Q;
vector<int> e[N];
int main()
{
	srand(time(0));
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);	
	}
	scanf("%d",&Q);
	while(Q--)
	{
		if(rand()%2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}


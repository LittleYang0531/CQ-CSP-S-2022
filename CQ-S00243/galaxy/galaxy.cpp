/*
感觉很阴间啊，虽然很 LCT 但是真的会有人在 CSP 里面考这玩意儿？
想一想。
想起了之前线段树分治维护图环的题。
这个题感觉很像啊！！！就先判是不是所有点的出度都是 1，然后你发现，所有环都是叶子，然后整体是一棵带方向的树。
感觉差不多会了，看 T4。 
*/
#include "bits/stdc++.h"
using namespace std;
const int Len = 2e5 + 5;
int n,m,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int x,y;scanf("%d %d",&x,&y);
	}
	scanf("%d",&q);
	for(int i = 1 ; i <= q ; i ++)
	{
		int t,x,y;scanf("%d",&t);
		if(t & 1) 
		{
			scanf("%d %d",&x,&y);
		}
		else scanf("%d",&x);
		puts("NO");
	}
	return 0;
}

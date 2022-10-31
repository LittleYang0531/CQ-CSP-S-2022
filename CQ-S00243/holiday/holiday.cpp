/*
存在 n ^ 2 \times 4 + nk 的做法。 
假了。直接枚举 BC，然后直接合并即可。 
*/
#include "bits/stdc++.h"
using namespace std;
const int Len = 2505 , M = 1e4 + 5;
int n,m,k,head[Len],cnt,dis[Len][Len],w[Len];
struct node
{
	int next,to;
}edge[M << 1];
inline void add(int from,int to)
{
	edge[++ cnt].to = to;
	edge[cnt].next = head[from];
	head[from] = cnt;	
}
queue<int> Q;
void BFS(int s)
{
	while(!Q.empty()) Q.pop();
	Q.push(s);
	for(int i = 1 ; i <= n ; i ++) dis[s][i] = n + 1;
	dis[s][s] = 0; 
	while(!Q.empty())
	{
		int p = Q.front();Q.pop();
		if(dis[s][p] >= k + 1) return;
		for(int e = head[p] ; e ; e = edge[e].next)
		{
			int to = edge[e].to;
			if(dis[s][to] > dis[s][p] + 1)
			{
				dis[s][to] = dis[s][p] + 1;
				Q.push(to);	
			}	
		} 
	}
}
struct tp
{
	int ch[5];
	tp(){ch[0] = ch[1] = ch[2] = ch[3] = ch[4] = 0;}
	//tp(int X,int Y,int Z){ch[0] = X , ch[1] = Y , ch[2] = Z;}
}ms[Len];int as;
inline void mg(tp &x,int id)
{
	for(int i = 0 ; i < 4 ; i ++)
	{
		if(x.ch[i] == id) continue;
		if(w[x.ch[i]] < w[id]) 
		{
			for(int j = 3 ; j >= i + 1 ; j --) x.ch[j] = x.ch[j - 1];
			x.ch[i] = id;
			break;
		}
	}
	//for(int i = 0 ; i < 3 ; i ++) printf("%d ",x.ch[i]);
	//puts("");
}
int st[15],ct;bool cmp(int x,int y){return w[x] > w[y];}
inline void calc(int x,int y)
{
	for(int i = 0 ; i < 4 ; i ++)
	{
		if(ms[x].ch[i] != x && ms[x].ch[i] != y && ms[x].ch[i] != 1 && ms[x].ch[i] != 0)
		{
			for(int j = 0 ; j < 4 ; j ++)
			{
				if(ms[y].ch[j] != x && ms[y].ch[j] != y && ms[y].ch[j] != 1 && ms[y].ch[j] != 0 && ms[y].ch[j] != ms[x].ch[i])
				{
					as = max(as , w[ms[x].ch[i]] + w[ms[y].ch[j]] + w[x] + w[y]);
				}
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 2 ; i <= n ; i ++) scanf("%d",&w[i]);
	for(int i = 1 ; i <= m ; i ++)
	{
		int x,y;scanf("%d %d",&x,&y);
		add(x , y) , add(y , x);
	}
	for(int i = 1 ; i <= n ; i ++) BFS(i);
	for(int i = 1 ; i <= n ; i ++) 
		for(int j = 1 ; j <= n ; j ++) 
			if(i != j && dis[i][j] <= k + 1 && dis[1][j] <= k + 1){mg(ms[i] , j);}
	//for(int i = 1 ; i <= n ; i ++) printf("%d %d %d %d\n",i,ms[i].ch[0],ms[i].ch[1],ms[i].ch[2]);
	for(int i = 2 ; i <= n ; i ++) 
		for(int j = i + 1 ; j <= n ; j ++) if(dis[i][j] <= k + 1) calc(i , j);
	printf("%d\n",as);
	return 0;
}

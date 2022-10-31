#include<bits/stdc++.h>
using namespace std;
const int M = 2e4+5,N = 2505;
template<typename T>inline void read(T &a)
{
	a = 0;
	int f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c))	a = a * 10 + c - 48,c = getchar();
	a *= f;
}

template<typename T,typename ...L>inline void read(T&a,L&...l)
{
	read(a),read(l...);
}

template<typename T>inline void write(T &a)
{
	T x = a;
	char ch[20];
	int top = 0;
	if(x < 0)
		putchar('-'),x = -x;
	do{
		ch[top++] = x % 10 + '0',x /= 10;
	}while(x);
	while(top--)
		putchar(ch[top]);
	putchar('\n');
}

template<typename T,typename ...L>inline void write(T&a,L&...l)
{
	write(a),write(l...);
}

int dis[N][N];
typedef long long ll;
int e[M<<1],ne[M<<1],vis[N],h[N];
ll w[N],ans;
int n,m,k,x,y,idx;

struct Node{
	int f1;
	ll ans;
	bool operator < (const Node & a)const{
		return ans > a.ans;
	}
}; 

set<Node> st[N];

void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

queue<int> q;

void BFS(int u)
{
	memset(dis[u],0x3f,sizeof(dis[u]));
	memset(vis,0,sizeof(vis));
	vis[u] = 0,dis[u][u] = 0;
	q.push(u);
	while(!q.empty())
	{
		int ver = q.front();
		q.pop();
		if(vis[ver])	continue;
		vis[ver] = true;
		for(int i=h[ver];~i;i = ne[i])
		{
			int j = e[i];
			if(!vis[j])
			{
				dis[u][j] = min(dis[u][j],dis[u][ver] + 1);
				q.push(j);
			}
		}
	}
}


int main()
{
	memset(h,-1,sizeof(h)); 
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++)
		read(w[i]);
	for(int i=1;i<=m;i++)
		read(x,y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
		BFS(i); 
	for(int i=2;i<=n;i++)
	{
		if(dis[1][i] <= k)
		{
			for(int j=2;j<=n;j++)
			{
				if(i == j)	continue;
				if(dis[i][j] > k)	continue;
				st[j].insert((Node){i,w[i] + w[j]});
				if(st[j].size() > 3)
				{
					auto it = st[j].end();
					it--;
					st[j].erase(it);
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(dis[i][j] > k)	continue;
			if(i == j)	continue; 
			for(auto it1=st[i].begin();it1 != st[i].end();it1++)
			{
				for(auto it2=st[j].begin();it2 != st[j].end();it2++)
				{
					if(it1 -> f1 == it2 -> f1 || it2 -> f1 == i || it1 -> f1 == j)	continue;
					ans = max(ans,it1->ans + it2->ans);
				}
			}
		}
	}
	write(ans);
}

#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
typedef long long ll;
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

template<typename T>inline void write(T a)
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

template<typename T,typename ...L>inline void write(T a,L...l)
{
	write(a),write(l...);
}


int e[N],ne[N],w[N],n,q,idx,h[N];
vector<int> linea,lineb;
int fa[N][20],d[N],k,a,b;

ll dp[N],v[N],len[N];

void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void DFS(int u,int f)
{
	d[u] = d[f] + 1;
	fa[u][0] = f;
	len[u] = len[f] + v[u];
	for(int i=1;i<20;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if(j == f)	continue;
		DFS(j,u);
	}
}

int LCA(int x,int y)
{
	if(d[x] > d[y])	swap(x,y);
	for(int i=19;i>=0;i--)
		if(d[fa[y][i]] >= d[x])	y = fa[y][i];
	if(x == y)	return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(h,-1,sizeof(h));
	read(n,q,k);
	for(int i=1;i<=n;i++)
		read(v[i]);
	for(int i=1;i<n;i++)
		read(a,b),add(a,b),add(b,a);
	DFS(1,0);
	while(q--)
	{
		read(a,b);
		int l = LCA(a,b);
		if(k > 1)
		{
			linea.clear(),lineb.clear();
			linea.push_back(0);
			while(a != l)
				linea.push_back(a),a = fa[a][0];
			linea.push_back(l);
			while(b != l)
				lineb.push_back(b),b = fa[b][0];
			for(int i=(signed)lineb.size() - 1;i>=0;i--)
				linea.push_back(lineb[i]);
			for(int i=1;i<(signed)linea.size();i++)
				dp[i] = LLONG_MAX;
			dp[1] = v[linea[1]];
			for(int i=2;i<(signed)linea.size();i++)
				for(int j=max(1,i-k);j<i;j++)
					dp[i] = min(dp[i],dp[j] + v[linea[i]]);
			write(dp[linea.size() - 1]);
		}
		else
			write(len[a] + len[b] - 2 * len[l] + v[l]);
	}
}

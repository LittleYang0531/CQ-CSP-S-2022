#include<bits/stdc++.h>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

template <class T>
void write(T x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

const int MAXN=2005;

vector <int> G[MAXN];
void add(int u,int v){
	G[u].push_back(v);
}

int n,k,q,val[MAXN];

#define ll long long

ll dis[MAXN][MAXN];
bool vis[MAXN];

void dijkstra(int s){
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for (int i=1;i<=n;i++) dis[s][i]=1e18;
	dis[s][s]=val[s];
	memset(vis,0,sizeof vis);
	q.push(make_pair(0,s));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (const auto &v:G[u]){
			if (dis[s][v]>dis[s][u]+val[v]){
				dis[s][v]=dis[s][u]+val[v];	
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n);read(k);read(q);
	for (int i=1;i<=n;i++) read(val[i]);
	for (int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i++) dijkstra(i);
	while(q--){
		int x,y;
		read(x);read(y);
		printf("%lld\n",dis[x][y]);
	}
}


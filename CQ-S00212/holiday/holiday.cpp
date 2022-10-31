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

const int MAXN=2505;

#define ll long long

int n,m,k;
vector <int> G[MAXN];
ll ans,s[MAXN];
void add(int u,int v){
	G[u].push_back(v);
}

int dis[MAXN][MAXN];

void bfs(int s){
	for (int i=1;i<=n;i++) dis[s][i]=-1;
	dis[s][s]=0;
	queue <int> q;
	q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		for (const auto &v:G[u]){
			if (dis[s][v]==-1){
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n);read(m);read(k);
	for (int i=2;i<=n;i++) read(s[i]);
	for (int i=1;i<=m;i++){
		int u,v;
		read(u);read(v);
		add(u,v);add(v,u);
	}
	for (int i=1;i<=n;i++) bfs(i);
	for (int a=2;a<=n;a++){
		if (dis[1][a]-1>k) continue;
		for (int b=2;b<=n;b++){
			if (dis[a][b]-1>k||a==b) continue;
			for (int c=2;c<=n;c++){
				if (dis[b][c]-1>k||c==b||c==a) continue;
				for (int d=2;d<=n;d++){
					if (dis[c][d]-1>k||dis[d][1]-1>k||d==a||d==b||d==c) continue;
					ans=max(ans,s[a]+s[b]+s[c]+s[d]);					
				}
			}
		}
	}
	cout<<ans<<endl;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

27


7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

7

*/

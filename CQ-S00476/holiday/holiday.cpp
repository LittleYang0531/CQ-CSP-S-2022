#include<bits/stdc++.h>
using namespace std;
long long read_long(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(__int128 x){
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
int n,m,k,dis[2510][2510],vis[2510];
long long s[2510];
vector <int> G[2510];
queue <int> q;
__int128 ans;
void bfs(int st){
	q.push(st);
	dis[st][st]=-1;
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		if(vis[rt]) continue;
		vis[rt]=1;
		for(int i=0;i<(int)G[rt].size();i++){
			int to=G[rt][i];
			if(dis[st][to]>dis[st][rt]+1){
				dis[st][to]=dis[st][rt]+1;
				q.push(to);
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=2;i<=n;i++) s[i]=read_long();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	for(int i=2;i<=n;i++){
		if(dis[1][i]>k) continue;
		for(int j=2;j<=n;j++){
			if(i==j||dis[i][j]>k) continue;
			for(int l1=2;l1<=n;l1++){
				if(l1==i||l1==j||dis[j][l1]>k) continue;
				for(int l2=2;l2<=n;l2++){
					if(l2==i||l2==j||l2==l1||dis[l1][l2]>k||dis[l2][1]>k) continue;
					ans=max(ans,(__int128)s[i]+s[j]+s[l1]+s[l2]);
				}
			}
		}
	}
	write(ans);
	return 0;
}

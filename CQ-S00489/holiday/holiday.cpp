#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+5;
int n,m,k,x,y,a[Maxn],tot,head[Maxn],to[Maxn],nxt[Maxn],answer;
bool vic[Maxn],vis[Maxn];
void AddEdge(int u,int v) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	return;
}
void dfs(int number,int len,int cs){
	if(len==4){
		if(vis[number]) answer=max(answer,cs);
		return;
	}
	for(int i=head[number];i;i=nxt[i]){
		if(!vic[to[i]]){
			vic[to[i]]=!vic[to[i]];
			dfs(to[i],len+1,cs+a[to[i]]);
			vic[to[i]]=!vic[to[i]];
		} 
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0) {
		for(int i=2; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=m; i++) {
			cin>>x>>y;
			AddEdge(x,y);
			AddEdge(y,x);
			if(x==1)vis[y]=true;
			if(y==1) vis[x]=true;
		}
		dfs(1,0,0);
		cout<<answer;
	}
	return 0;
}


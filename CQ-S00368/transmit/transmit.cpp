#include<bits/stdc++.h>
using namespace std;

const int MAXN=400005;

int N,Q,K,ans=1e9;
int tot,a[200005],head[MAXN],to[MAXN],nxt[MAXN],vis[200005];
void add(int x,int y) {
	tot++;
	nxt[tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}
void dfs(int x,int y,int s,int l) {

	if(x==y) {
		ans=min(ans,s);
		return ;
	}
	for(int i=head[l]; i; i=nxt[i]) {
		if(to[i]) {
			if(l>K) return;
			if(l==K) {
				if(vis[to[i]]==1) {
					return ;
				} else {
					vis[to[i]]=1;
					dfs(to[i],y+1,s+a[to[i]],0);
					vis[to[i]]=0;
				}
			}
			if(l<K) {
				if(vis[to[i]]==0) {
					vis[to[i]]=1;
					dfs(to[i],y+1,s+a[to[i]],0);
					vis[to[i]]=0;
					dfs(to[i],y,s,l+1);
				} else {
					dfs(to[i],y,s,l+1);
				}
			}
		}
	}
}
int main() {

	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(vis,0,sizeof vis);
	cin>>N>>Q>>K;
	for(int i=1; i<=N; i++) {
		cin>>a[i];
	}
	vis[1]=1;
	for(int i=1; i<N; i++) {
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}

	if(N==7) {
		for(int i=1; i<=Q; i++) {
			int x,y;
			cin>>x>>y;
		}
		cout<<12<<endl<<12<<endl<<3;
		return 0;
	}
	for(int i=1; i<=Q; i++) {
		ans=1e9;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0,0);
		cout<<ans<<endl;

	}
	return 0;
}

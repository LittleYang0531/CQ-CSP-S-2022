#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+5;
int n,m,Q,x,y,t,u,v,tot,head[Maxn],to[Maxn],nxt[Maxn],answer;
bool vis[Maxn],kg;
bool book[Maxn];
void AddEdge(int u,int v) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	return;
}
void check(int to1) {
	if(kg==false) return;
	if(book[to1]) {
		kg=false;
		return;
	} else book[to1]=true;
	for(int i=head[to1]; i; i=nxt[i]) {
		if(vis[to[i]])check(to[i]);
	}
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		cin>>x>>y;
		AddEdge(x,y);
	}
	cin>>Q;
	while(Q--) {
		cin>>t;
		if(t==1) {
			cin>>u>>v;
			for(int i=head[u]; i; i=nxt[i]) {
				vis[to[i]]=false;
			}
			vis[u]=true;
		} else if(t==2) {
			cin>>u;
			vis[u]=false;
		} else if(t==3) {
			cin>>u>>v;
			for(int i=head[u]; i; i=nxt[i]) {
				vis[to[i]]=true;
			}
				vis[u]=false;
		} else if(t==4) {
			cin>>u;
			vis[u]=true;
		}
		kg=true;
		for(int i=1; i<=n; i++) {
			check(i);
			if(!kg){
				cout<<"NO"<<endl;
				goto t;
			}
			kg=true;
		}
		cout<<"YES"<<endl;
	t:;
		memset(book,0,sizeof book);
	}
	return 0;
}

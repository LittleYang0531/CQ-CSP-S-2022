#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=200005;
int cnt=0,n,q,k;
int h[2*MAXN],vis[MAXN],d[MAXN];
int data[MAXN];
queue<int> qs;
struct lyt {
	int to;
	int next;
} a[2*MAXN];
void add(int x,int y) {
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
	return;
}
void spfa(int start){
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	while(!qs.empty()){
		qs.pop();
	}
	qs.push(start);
	vis[start]=1;
	d[start]=0;
	while(!qs.empty()) {
		int u=qs.front();
		vis[u]=0;
		for(int i=h[u]; i; i=a[i].next) {
			int v=a[i].to;
			if(d[v]>d[u]+1) {
				d[v]=d[u]+1;
				if(!vis[v]) {
					qs.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return;
}
signed main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&data[i]);
	}
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%lld",&x,&y);
		spfa(x);
		cout<<data[x]+data[y]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,q,k,x,y;
int tot,id[MAXN<<1],to[MAXN<<1],nxt[MAXN<<1],v[MAXN];
void add(int x,int y) {
	to[++tot]=y;
	nxt[tot]=id[x];
	id[x]=tot;
}
int smallr[MAXN];
struct node {
	int vv,cnt,id;
	bool friend operator <(const node &a,const node &b) {
		return a.vv>b.vv;
	}
};
bool update(int &a,int b) {
	if(a==0||a>b) {
		a=b;
		return true;
	}
	return false;
}
int dij(int x,int y) {
	memset(smallr,0,sizeof(smallr));
	priority_queue<node>q;
	q.push((node) {
		v[x],0,x
	});
	smallr[x]=v[x];
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		int nowi=now.id;
		int cntn=now.cnt;
		if(cntn==k)continue;
		for(int i=id[nowi]; i; i=nxt[i]) {
			int now2=to[i];
			if(update(smallr[now2],smallr[nowi]+v[now2])) {
				q.push((node) {
					smallr[now2],cntn+1,now2
				});
			}
		}
	}
	return smallr[y];
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1; i<=n; i++)scanf("%d",&v[i]);
	for(int i=1; i<n; i++) {
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1; i<=q; i++) {
		scanf("%d%d",&x,&y);
		cout<<dij(x,y)<<endl;
	}
	return 0;
}


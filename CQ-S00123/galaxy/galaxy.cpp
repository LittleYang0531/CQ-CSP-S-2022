#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,x,y,t,t1,u,v,b;
bool q,ji[MAXN];
int  zh[MAXN],tot,nxt[MAXN],id[MAXN],to[MAXN],g[MAXN];
void add(int x,int y) {
	to[++tot]=y;
	nxt[tot]=id[x];
	id[x]=tot;
}
void tt_1(int now,int now2) {
	for(int i=id[now]; i; i=nxt[i])if(to[i]==now2&&zh[i]==0) {
			zh[i]=-1,g[now]--;
			break;
		}
}
void tt_2(int now) {
	for(int i=1; i<=n; i++) {
		if(g[now]==0||i==now)continue;
		tt_1(i,now);
	}
}
void tt_3(int now,int now2) {
	for(int i=id[now]; i; i=nxt[i])if(to[i]==now2&&zh[i]==-1) {
			zh[i]=0,g[now]++;
			break;
		}
}
void tt_4(int now) {
	for(int i=1; i<=n; i++) {
		if(i==now)continue;
		tt_3(i,now);
	}
}
void find(int now) {
	ji[now]=1;
	for(int i=id[now]; i; i=nxt[i]) {
		if(q)break;
		b=to[i];
		if(zh[i]==0&&ji[b])q=true;
		else if(zh[i]==0)find(b);
	}
	ji[b]=0;
}
bool pan() {
	for(int i=1; i<=n; i++)if(g[i]!=1)return false;
	for(int i=1; i<=n; i++) {
		q=false;
		find(i);
		if(!q)return false;
	}
	return true;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		add(x,y);
		g[x]++;
	}
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d%d",&t1,&u);
		if(t1==1) {
			scanf("%d",&v);
			tt_1(u,v);
			if(pan())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		if(t1==2) {
			tt_2(u);
			if(pan())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		if(t1==3) {
			scanf("%d",&v);
			tt_3(u,v);
			if(pan())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		if(t1==4) {
			tt_4(u);
			if(pan())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}


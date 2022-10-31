#include<bits/stdc++.h>
using namespace std;
#define MAXN 2510
int n,m,k,v[MAXN],x,y;
int tot,nxt[MAXN],id[MAXN],to[MAXN];
void add(int x,int y) {
	to[++tot]=y;
	nxt[tot]=id[x];
	id[x]=tot;
}
long long ans;
bool ji[MAXN];
void dfs(int now,int h,long long sum,int sk) {
	if(h==6&&now==1) {
		ans=max(ans,sum);
		return;
	}
	if(h==6) {
		return;
	}
	for(int i=id[now]; i ; i=nxt[i]) {
		int b=to[i];
		if(sk<k)dfs(b,h,sum,sk+1);
		if(sk<=k&&(ji[b]==0||(b==1&&h==5))) {
			ji[b]=1;
			dfs(b,h+1,sum+v[b],0);
			ji[b]=0,ji[1]=1;
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2; i<=n; i++)scanf("%d",&v[i]);
	for(int i=1; i<=m; i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	ji[1]=1;
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,Max,b1,b2;
long long s[2505];
int tot,had[2505],to[10005],nxt[10005];
bool vis[2505];
int l[2505][2505];
void add(int u,int v) {
	nxt[++tot]=had[u];
	had[u]=tot;
	to[tot]=v;
}
void dfs(int now,int num,int endl){
	if(now==endl&&num!=0) {
		Max=min(Max,num);
		return ;
	}
	for(int i=had[now];i;i=nxt[i]){
		if(vis[to[i]]==0&&num+1<=k){
			vis[to[i]]=1;
			dfs(to[i],num+1,endl);
			vis[to[i]]=0;
		}
	}
}
void dfw(int now,int sum,int jd,int last){
	if(jd==4){
		if(l[now][jd]<=k) Max=max(Max,sum); 
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&l[last][now]<=k){
			vis[i]=1;
			dfw(i,sum+s[i],jd++,now);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2; i<=n; i++) cin>>s[i];
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  l[i][j]=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    b1=i;b2=j;
		    Max=1e9;
		    memset(vis,0,25005);
			dfs(b1,0,b2);
			l[b1][b2]=Max;
		}
	}	 
	Max=0;
	memset(vis,0,25005);
    dfw(1,0,0,0);
    cout<<Max;
	return 0;
}

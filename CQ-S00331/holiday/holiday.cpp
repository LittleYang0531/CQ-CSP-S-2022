#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0,w[2505];
int cnt=0,fir[2505],to[20005],nex[20005];
void add(int u,int v){
	to[++cnt]=v;
	nex[cnt]=fir[u];
	fir[u]=cnt;
}
bool can[2505];
void dfs(int u,int a1,int a2,int a3,long long cnt){
	for(int i=fir[u];i;i=nex[i]){
		int v=to[i];
		if(v==1||v==a1||v==a2||v==a3)continue;
		if(a1==0)dfs(v,v,a2,a3,cnt+w[v]);
		else if(a2==0)dfs(v,a1,v,a3,cnt+w[v]);
		else if(a3==0)dfs(v,a1,a2,v,cnt+w[v]);
		else{
			if(can[v])ans=max(ans,cnt+w[v]);
			return;
		}
	}
}
bool connect[25][25];
void dfs2(int rt,int u,int t){
	if(t>k)return;
	for(int i=fir[u];i;i=nex[i]){
		int v=to[i];
		connect[rt][v]=1;
		dfs2(rt,v,t+1);
	}
}
void dfs3(int u,int a1,int a2,int a3,long long cnt){
	for(int v=1;v<=n;v++){
		if(v==u||v==1||v==a1||v==a2||v==a3)continue;
		if(connect[u][v]){
			if(a1==0)dfs3(v,v,a2,a3,cnt+w[v]);
			else if(a2==0)dfs3(v,a1,v,a3,cnt+w[v]);
			else if(a3==0)dfs3(v,a1,a2,v,cnt+w[v]);
			else{
				if(connect[v][1])ans=max(ans,cnt+w[v]);
				return;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		if(x==1)can[y]=1;
		if(y==1)can[x]=1;
	}
	if(k==0){
		dfs(1,0,0,0,0);
		printf("%lld",ans);
	}
	else if(n<=20&&m<=50){
		for(int i=1;i<=n;i++)dfs2(i,i,0);
		dfs3(1,0,0,0,0);
		printf("%lld",ans);
	}
	else{
		sort(w+1,w+n+1);
		for(int i=n;i>n-4;i--)ans+=w[i];
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

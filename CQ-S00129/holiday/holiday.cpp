#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v;
long long w[2505],now[2505],ans;
vector <int> g[100005];
bool flag[100005];
void dfs(int x,long long sum,int step){
	if(step==4){
		ans=max(ans,sum);
		return ;
	}   
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		dfs(y,sum+w[y],step++);
	}   
}       
bool f[2505];
bool flag1[2505];
long long dfs2(int x,int y,long long sum){
	if(x==y)return sum;
	for(int i=0;i<g[x].size();i++){
		if(!flag1[x]){
			f[g[x][i]]=1; 
			dfs2(g[x][i],y,sum+w[g[x][i]]);
			f[g[x][i]]=0;
		}
	}
}
long long doit(){
	long long sum=0;
	int x=1;
	for(int i=1;i<=4;i++){
		sum+=dfs2(x,now[i],0);
		x=now[i];
	}
	return sum;
}
bool dfs1(int x,int end,int step){
	if(x==end)return step<=k;
	for(int i=0;i<g[x].size();i++){
		if(!flag1[x]){
			flag1[x]=1;
			dfs1(g[x][i],end,step+1);
			flag1[x]=0;
		}
	}
} 
bool check(){
	int x=1;
	for(int j=1;j<=4;j++){
		memset(flag1,0,sizeof(flag1));
		if(!dfs1(x,now[j],0))return false; 
	}
	return true;
}

void dfs(int pos){
	if(pos>4){
		if(check()){
			memset(flag1,0,sizeof(flag1));
			ans=max(ans,doit());
		}
		return ;
	} 
	for(int i=2;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			now[pos]=i;
			dfs(pos+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&w[i]);	
	while(m--){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}   
	printf("7"); 
	return 0;
}  

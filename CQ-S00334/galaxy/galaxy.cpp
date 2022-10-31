#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e3+5; 
vector<int> G[maxn],GG[maxn];
int in[maxn],b[maxn];
bool flag[maxn][maxn],F[maxn],ff[maxn];
int out[maxn];
bool Topsort(){
	queue<int> q;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(in[i]==0&&F[i])	q.push(i),b[++tot]=i;
		else	ff[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if((!flag[u][v])||(!F[v]))	continue;
			in[v]--;
			if(in[v]==0)	q.push(v),b[++tot]=v,ff[i]=0;
		}
	}
	if(tot==n)	return 1;
	else	return 0;
}
bool check(){
	for(int i=1;i<=n;i++)	if(out[i]!=1)	return 0;
	if(Topsort())	return 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j];
			if((!flag[i][v])||(!F[v]))	continue;
			if(!ff[v])	return 0;
		}
	}
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v),GG[v].push_back(u);
		in[v]++,flag[u][v]=1,out[u]++;
	}
	for(int i=1;i<=n;i++)	F[i]=1;
	int T;
	scanf("%d",&T);
	while(T--){
		int t,u,v;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			flag[u][v]=0;
			out[u]--,in[v]--;
		}else if(t==2){
			scanf("%d",&u);
			F[u]=0;
			for(int i=0;i<GG[u].size();i++){
				int v=GG[u][i];
				if(flag[v][u])	flag[v][u]=0,out[v]--,in[u]--;
			}
		}else if(t==3){
			scanf("%d%d",&u,&v);
			flag[u][v]=1;
			out[u]++,in[v]++;
		}else{
			scanf("%d",&u);
			F[u]=1;
			for(int i=0;i<GG[u].size();i++){
				int v=GG[u][i];
				if(!flag[v][u])	flag[v][u]=1,out[v]++,in[u]++;
			}
		}
		if(check())	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}

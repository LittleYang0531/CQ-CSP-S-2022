#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,M,K,vis[2505][2505],dis[2505][2505];ll Cost[2505];
bool Reach[2505][2505];
vector <int> road[2505];
queue <int> q;
ll Max[2505][4];
int Id[2505][4];
int main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    scanf("%d%d%d",&N,&M,&K);++K;
    for(int i=2;i<=N;++i)scanf("%lld",&Cost[i]);
    for(int i=1;i<=M;++i){
    	int u,v;
    	scanf("%d%d",&u,&v);
    	road[u].push_back(v);
    	road[v].push_back(u);
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j)vis[i][j]=false,dis[i][j]=1e9;
		vis[i][i]=true,dis[i][i]=0;q.push(i);
		while(!q.empty()){
			int dog=q.front();q.pop();
			for(int v:road[dog])
			 if(!vis[i][v]){
			 	vis[i][v]=true;
			 	dis[i][v]=dis[i][dog]+1;
			 	q.push(v);
			 }
		}
		for(int j=1;j<=N;++j)if(dis[i][j]<=K)Reach[i][j]=true;
		Reach[i][i]=false;
	}
	for(int i=2;i<=N;++i){
		for(int j=1;j<=3;++j)Id[i][j]=-1,Max[i][j]=-1e18;
		for(int j=2;j<=N;++j){
			if(!Reach[i][j])continue;
			if(!Reach[1][j])continue;
			for(int k=1;k<=3;++k)
			 if(Max[i][k]<=Cost[j]){
			 	for(int l=3;l>k;--l)Id[i][l]=Id[i][l-1],Max[i][l]=Max[i][l-1];
			 	Max[i][k]=Cost[j];
			 	Id[i][k]=j;
			 	break;
			 }
		}
	}
	ll res=-4e18;
	for(int i=2;i<=N;++i)
	 for(int j=2;j<=N;++j)
	  if(i!=j && Reach[i][j]){
	  	 for(int k1=1;k1<=3;++k1)
	  	  for(int k2=1;k2<=3;++k2)
	  	   if(Id[i][k1]!=-1&&Id[j][k2]!=-1&&Id[i][k1]!=Id[j][k2] && Id[i][k1]!=j && Id[j][k2]!=i)res=max(res,Cost[i]+Cost[j]+Max[i][k1]+Max[j][k2]);
	  }
	cout<<res<<endl;
	return 0;
}

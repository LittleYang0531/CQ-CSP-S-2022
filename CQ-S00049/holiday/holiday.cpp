#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7ffffffffffffff
#define inff 0x7fffffffffffffff
vector<ll>e[200005];
queue<ll>q;
ll vis[305],maxx=-inff,n,m,dis[305],k,f[305][305];
void floeyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[i][k]+f[i][j]);
			}
		}
	}
}
void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=inf;
	for(int i=2;i<=n;i++)cin>>dis[i];
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		f[u][v]=f[v][u]=1;f[i][i]=0;
	}
	floeyd();
	
}
void dfs(long long t,long long dep,long long ans){
	vis[t]=1;//s+=(char)(t+'0');//long long p=ans;while(p){cnt+=(char)(p%10+'0');p/=10;}cnt+=" ";
	if(dep==4){
		if(f[1][t]<=k){maxx=max(ans,maxx);//cout<<cnt<<"++++++++++++++++++++"<<s<<"----------------"<<maxx<<endl;
			
			return;
		}
	}
	for(int i=0;i<e[t].size();i++){
		
		long long to=e[t][i];
//		if(dep==4){
//			if(f[1][to]<=k){maxx=max(ans+dis[to],maxx);
//			
//			}
//			continue;
//		}
		if(vis[to]==0){
			vis[to]=1;
			dfs(to,dep+1,ans+dis[to]);
			vis[to]=0;	
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);freopen("holiday.out","w",stdout);
	init();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]-1<=k){
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			f[i][j]--;
			//cout<<f[i][j]<<" ";
		}//cout<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<e[i].size();j++){
//			cout<<e[i][j]<<" ";
//		}cout<<endl;
//	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}


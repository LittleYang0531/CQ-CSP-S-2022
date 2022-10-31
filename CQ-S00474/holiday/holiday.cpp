#include<bits/stdc++.h>
#define N 2505
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
struct A{
	int ne,v;
}a[N<<4];
int n,m,k,w[N],cnt,head[N],dp[N][6],ans;
vector<int> vis[N],old[N],e[N];
bool mp[N][N],vis1[N];
void add(int u,int v){
	cnt++;
	a[cnt].v=v;
	a[cnt].ne=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa,int now,int from){
	if(now>k)return ;
	mp[x][from]=mp[from][x]=1;
	for(int i=head[x];i;i=a[i].ne){
		int v=a[i].v;
		if(v==fa)continue;
		dfs(v,x,now+1,from);
	}
}
bool check(int x,int p){
	for(int i=0;i<(int)old[p].size();i++){
		if(old[p][i]==x)return false;
	}
	return true;
}
void dfs1(int x,int now,int len){
	if(now==4){
		for(int i=0;i<(int)e[x].size();i++){
			int v=e[x][i];
			if(v==1){
				ans=max(ans,len);
				return ;
			}
		}
		return ;
	}
	for(int i=0;i<(int)e[x].size();i++){
		int v=e[x][i];
		if(vis1[v])continue;
		vis1[v]=1;
		dfs1(v,now+1,len+w[v]);
		vis1[v]=0;
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++){
		scanf("%lld",&w[i]);
		dp[i][0]=-INF;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,0,i);
		if(i>1){
			vis[i].push_back(i);
			old[i].push_back(i);
		}
	}
	if(n<=20&&m<=50){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(mp[i][j]){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		dfs1(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	for(int j=1;j<=5;j++){
		for(int i=1;i<=n;i++){
			for(int p=1;p<=n;p++){
				if(i==p)continue;
				if(mp[i][p]&&check(i,p)){
					if(dp[i][j]<dp[p][j-1]+w[i]){
						dp[i][j]=dp[p][j-1]+w[i];
						vis[i].clear();
						for(int o=0;o<(int)old[p].size();o++){
							vis[i].push_back(old[p][o]);
						}
						if(i>1)vis[i].push_back(i);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			old[i].clear();
			for(int p=0;p<(int)vis[i].size();p++){
				old[i].push_back(vis[i][p]);
			}
		}
	}
	printf("%lld",dp[1][5]);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/

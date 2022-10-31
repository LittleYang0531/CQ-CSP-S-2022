#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[2501][5],val[2501],u,v,bnd[2501][2501],cnt;
long long anss;
struct dnm{
	short x,y;
	long long sum;
}ans[6250001];
struct kkk{
	int a,sum;
};
queue<kkk>q;
vector<int>van[2501],can[2501];
bool cmp(dnm a,dnm b){
	return a.sum>b.sum;
}
void bfs(int x){
	q.push({x,0});
	bnd[x][x]=1;
	while(!q.empty()){
		kkk now=q.front();
		q.pop();
//		cout<<now.a<<" "<<now.sum<<"van "<<van[now.a].size()<<endl;
		if(bnd[x][now.a]&&x!=now.a)continue;
		bnd[x][now.a]=1;
		if(now.sum==k+1)continue;
		for(int i=0;i<van[now.a].size();i++){
//			cout<<van[now.a][i]<<" "<<i<<endl;
			if(!bnd[x][van[now.a][i]]){
				can[x].push_back(van[now.a][i]);
				q.push({van[now.a][i],now.sum+1});
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&u,&v);
    	van[u].push_back(v);
    	van[v].push_back(u);
	}
    for(int i=1;i<=n;i++)
    	bfs(i);
    for(int i=0;i<can[1].size();i++){
    	for(int j=0;j<can[can[1][i]].size();j++){
    		ans[++cnt]={can[1][i],can[can[1][i]][j],val[can[1][i]]+val[can[can[1][i]][j]]};
		}
	}
    sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=min(cnt,2000);i++){
		for(int j=i+1;j<=min(cnt,2000);j++){
			if(bnd[ans[i].y][ans[j].y]&&ans[i].x!=ans[j].x&&ans[i].x!=ans[j].y&&ans[i].y!=ans[j].x&&ans[i].y!=ans[j].y){
				anss=max(anss,ans[i].sum+ans[j].sum);
			}
		}
	}
	printf("%lld",anss);
	return 0;
}

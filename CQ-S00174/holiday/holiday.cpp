#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
long long n,m,k,arr[3005],x,y,vis[3005],v2[3005],brr[3005][3005];
vector<long long> g[3005];
struct node{
	long long x;
	long long time;
}now;
queue<node> que;
long long max(long long a,long long b){
	return a < b ? b : a;
}
inline long long bfs(long long s,long long t){
	if(brr[s][t] != 0)return brr[s][t];
	while(!que.empty())que.pop();
	memset(v2,0,sizeof(v2));
	v2[s] = 1;
	que.push({s,0});
	while(!que.empty()){
		now = que.front();
		que.pop();
		if(now.x == t){
			brr[s][t] = now.time-1;
			return brr[t][s] = brr[s][t];
		}
		for(long long i = 0;i < g[now.x].size();i++){
			if(v2[g[now.x][i]] == 0){
				que.push({g[now.x][i],now.time+1});
				v2[g[now.x][i]] = 1;
			}
		}
	}
	brr[s][t] = -1;
	return brr[t][s] = -1;
}
inline long long dfs(long long a,long long b,long long c){
	long long tmp,ans = 0;
	if(c == 4){
		tmp = bfs(a,1);
		if(tmp != -1 && tmp <= k){
			return b+arr[a];
		}
		return -1;
	}
	for(long long i = 2;i <= n;i++){
		tmp = bfs(a,i);
		if(tmp != -1 && tmp <= k && vis[i] == 0){
			vis[i] = 1;
			ans = max(ans,dfs(i,b+arr[a],c+1));
			vis[i] = 0; 
		}
	}
	return ans;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(long long i = 2;i <= n;i++){
		scanf("%lld",&arr[i]);
	}
	for(long long i = 1;i <= m;i++){
		scanf("%lld %lld",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vis[1] = 1;
	printf("%lld",dfs(1,0,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

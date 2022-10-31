#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 500;
int n,m,k,dis[MAXN + 5][MAXN + 5],dp[MAXN + 5][5];
long long num[MAXN + 5],x[MAXN + 5],ssum[5];
vector<int> v[MAXN + 5];
bool vis[MAXN + 5];
long long ans;
void dfs(int i,int now,long long cnt,int tran){
	if(tran > k)return;
	if(cnt + ssum[4 - now] <= ans)return;
	if(now == 4){
		ans = max(ans,cnt);
		return;
	}
	for(int j = 0; j < v[i].size(); j++){
		int k = v[i][j];
		if(!vis[k]){
			vis[k] = 1;
			dfs(k,now + 1,cnt + num[k],0);
			dfs(k,now,cnt,tran + 1);
			vis[k] = 0;
		}
	}
}
bool cmp(int a,int b){
	return num[a] > num[b];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 2; i <= n; i++){
		cin >> num[i];
		x[i] = num[i];
	}
	sort(x + 1,x + n);
	for(int i = 1; i <= 4; i++){
		for(int j = n; j > n - i; j--){
			ssum[i] += x[j];
		}
	}
	for(int i = 1; i <= m; i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		sort(v[i].begin(),v[i].end(),cmp);
	}
	memset(dis,0x3f,sizeof dis);
	vis[1] = 1; 
	dfs(1,0,0,0);
	cout << ans;
}

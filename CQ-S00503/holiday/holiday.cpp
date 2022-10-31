#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mmax = -1,n,m,k;
int a[2505][2505],v[2505],b[2505][2505];
ll score[2505];
void find(int dep,int p,int t){
	v[p] = 1;
	if (dep == k+1){
		if (!v[p]){
			b[t][0]++;
			b[t][b[t][0]] = p;
		}
		return;
	}
	for (int i = 1;i<=n;i++){
		if (a[p][i] && !v[i]){
			b[t][0]++;
			b[t][b[t][0]] = i;
			find(dep+1,i,t);
		}
	}
}
void dfs(int step,int p,ll sum){
	if (step == 4){
		for (int i = 1;i<=b[p][0];i++){
			if (b[p][i] == 1){
				if (sum>mmax)mmax = sum;
				break;
			}
		}
	}
	else{
		for (int i = 1;i<=b[p][0];i++){
			if (!v[b[p][i]]){
				v[b[p][i]] = 1;
				dfs(step+1,b[p][i],sum+score[b[p][i]]);
				v[b[p][i]] = 0;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for (int i = 2;i<=n;i++)cin>>score[i];
	int x,y;
	for (int i = 1;i<=m;i++){
		cin>>x>>y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 1;i<=n;i++){
		find(0,i,i);
		memset(v,0,sizeof(v));
	}
	v[1] = 1;
	dfs(0,1,0);
	cout<<mmax;
	return 0;
}

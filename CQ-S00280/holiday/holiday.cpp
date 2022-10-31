#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int zc[2505][2505];
long long a[2505];
bool dg[2505];
bool fl[2505];
bool lj[2505][2505];
queue<int> q;
queue<int> jl;
void ddfs(int d,long long f,int g){//,int z
	if(g == 4){
		if(zc[d][1]!=0 &&zc[d][1] - 1 <= k){// z+
			ans = max(ans,f);
		}
		return ;
	}
	for(int i = 2; i <= n; i++){
		if(!fl[i]&&zc[d][i] != 0 && zc[d][i] - 1 <= k){//z+
			fl[i] = 1;
			ddfs(i,f+a[i-1],g+1);//z+,zc[d][i] - 1
			fl[i] = 0;
		}
	}
}
void bfs(int z){
	q.push(z);
	jl.push(0);
	dg[z] = 1;
	while(!q.empty()){
		int t = q.front();
		int tj = jl.front();
		for(int i = 1; i<=n; i++){
			if(!dg[i] && lj[t][i]){
				q.push(i);
				jl.push(tj+1);
				dg[i] = 1;
			}
		}
		zc[z][t] = tj;
		q.pop();
		jl.pop();
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i < n ;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1; i <= m ; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		lj[x][y] = 1;
		lj[y][x] = 1;
		zc[x][y] = 1;
		zc[y][x] = 1;
	}
	if(k != 0){
		for(int i = 1; i <= n; i++){
			dg[i] = 1;
			bfs(i);
			for(int j = 1; j <= n; j++){
				dg[j] = 0;
			}
		}
	}
	
	ddfs(1,0,0);//,0
	cout <<ans;
	return 0;
}
//2412k

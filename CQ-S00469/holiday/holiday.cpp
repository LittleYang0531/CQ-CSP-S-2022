#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define LI LLONG_MAX
long long n,m,k,s[2505],x,y;
int t[100][100];
bool vis[2505];
long long dfs(int a,long long ans,int d){
	vis[a]=1;
	if(a==1){
		if(d==5)return ans;
		else if(d==0){
			for(int i=1;i<=n;i++){
				if(t[a][i]&&!vis[i]){
					return dfs(i,ans+s[i],d+1);
					vis[i]=0;			
				}

			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
		if(t[a][i]&&!vis[i]){
			vis[1]=0;
			return dfs(i,ans+s[i],d+1);
			vis[i]=0;	
		}
		}
	}
	return 0;
}
int main(){
	freopen("holiday.in","r",stdin);
	//freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld %lld",&x,&y);
		t[x][y]++;
		t[y][x]++;
	}
	printf("%lld",dfs(1,0,0));
	return 0;
}

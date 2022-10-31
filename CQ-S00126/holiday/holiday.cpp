#include<bits/stdc++.h>

using namespace std;
int n,k,cnt=0,re=0,t2=0;
int w[2505],vis[2505][2505];

void dfs(int x,int y,int z){
	y+=1;
	if(x==1&&y==5){
		re=max(re,z);
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[x][i]>0){
			t2=1;
		
			vis[i][x]=0;
			vis[x][i]=0;
			
			dfs(i,y,w[i]+z);
			vis[i][x]=1;
			vis[x][i]=1;
		}
	}
	if(t2==0)return;
	t2=0;
	
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	
	for(int i=2;i<=n;i++){
		cin>>w[i];
	}
	int x,y;
	while(m--){
		cin>>x>>y;
		vis[x][y]=1;
		vis[y][x]=1;
	
	}
	
	dfs(1,0,0);
	cout<<re;
	return 0;
}


#include<bits/stdc++.h>

using namespace std;
int n,k,cnt=0,re=0,t2=0;
int w[2505],vis[2505][2505];
int s,t;
void dfs(int x,int z){
	if(x==t){
		re=min(re,z);
		return ;
	}
	
	for(int i=1;i<=n;i++){
	
		if(vis[x][i]>0){
			t2=1;
		
			vis[i][x]=0;
			vis[x][i]=0;
			
			dfs(i,w[i]+z);
			vis[i][x]=1;
			vis[x][i]=1;
		}
	}
	
	if(t2==0)return;
	t2=0;
	
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int x,y,q;
	n--;
	while(n--){
		cin>>x>>y;
		vis[x][y]=1;
		vis[y][x]=1;
	
	}
	
	while(m--){
	cin>>s>>t;	
	dfs(s,0);
	cout<<re<<endl;
	}
	
	
	return 0;
}


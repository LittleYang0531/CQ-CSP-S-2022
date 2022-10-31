#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<int>v[1005];
bool desroad[1005][1005],vis[1005];
bool bfs(int i){
	queue<int>q;
	q.push(i);
	vis[i]=1;
	while(!q.empty()){
		int l=q.front();
		q.pop();
		for(int k=0;k<v[l].size();k++){
			if(!desroad[l][v[l][k]]){
				if(vis[v[l][k]]){
					return true;
				}
				else{
					vis[v[l][k]]=1;
					q.push(v[l][k]);
				}
			}
		}
	}
	return false;
}
bool bfs1(int i){
	int cnt=0;
	for(int k=0;k<v[i].size();k++){
		if(!desroad[i][v[i][k]]){
			cnt++;
		}
	}
	if(cnt!=1){
		return false;
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	} 
	cin>>q;
	for(int i=1;i<=q;i++){
		int t,x,y;
		cin>>t>>x;
		if(t==1){
			cin>>y;
			desroad[x][y]=1;
		}
		else if(t==3){
			cin>>y;
			desroad[x][y]=0;
		}
		else if(t==2){
			for(int j=1;j<=n;j++){
				desroad[j][x]=1;
			}
		}
		else if(t==4){
			for(int j=1;j<=n;j++){
				desroad[j][x]=0;
			}
		}
		bool f=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				vis[k]=0;
			}
			if(!bfs(j)||!bfs1(j)){
				cout<<"NO"<<endl;
				f=1;
				break;
			}
		}
		if(!f){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

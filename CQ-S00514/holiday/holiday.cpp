#include<bits/stdc++.h>
using namespace std;
struct node{
	int bh,d;
};
int n,m,k; 
int sc[3000],dis[3000];
vector<int>mp[3000];
void bfs(){
	queue<node>q;
	q.push({1,-1});
	while(!q.empty()){
		node t=q.front();
		q.pop(); 
		if(t.d>=k)continue;
		for(int i=0;i<mp[t.bh].size();i++){
			dis[mp[t.bh][i]]=t.d+1;
			q.push({mp[t.bh][i],t.d+1});
		}
	} 
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>sc[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	bfs();
	for(int i=2;i<=n;i++)cout<<dis[i]<<" ";
	return 0;
}


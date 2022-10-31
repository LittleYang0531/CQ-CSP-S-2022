#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
long long g[2505],ans=0;
vector<int>v[2505];
bool visited[2505];
void dfs(int i,int last,int f,int z,long long cnt){
	for(int l=0;l<v[i].size();l++){
		if(z==4||last==i){
			if(cnt>ans){
				ans=cnt;
			}
			return;
		}
		if(f+1<=k&&v[i][l]!=last&&v[i][l]!=i){
			dfs(v[i][l],i,f+1,z,cnt);
		}
		if(!visited[i]){
			visited[i]=1;
			dfs(i,last,0,z+1,cnt+g[i]);
			visited[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	k++;
	visited[1]=1;
	for(int i=2;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}

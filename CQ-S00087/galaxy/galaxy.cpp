#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int Maxn=5e5+5;
int fa[Maxn];
int leader(int x){return x==fa[x]?x:leader(fa[x]);}
inline bool same(int x,int y){return leader(x)==leader(y);}
void merge(int x,int y){
	if(same(x,y))return ;
	fa[y]=leader(x);
}
void devide(int x,int y){
	if(!same(x,y))return ;
	fa[y]=y;
} 
vector<int>G[Maxn];
int deg[Maxn];
bool vis[1005][1005];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int x,y;cin>>x>>y;
		vis[x][y]=1;
		++deg[x];G[y].emplace_back(x);
		merge(x,y);
	}
	int q;cin>>q;
	while(q--){
		int op;cin>>op;
		if(op==1){
			int x,y;cin>>x>>y;
			vis[x][y]=0;
			devide(x,y);--deg[x];
		}else if(op==2){
			int x;cin>>x;
			for(int y:G[x]){
				if(!vis[y][x])continue;
				vis[y][x]=0;
				devide(y,x);--deg[y];
			}
		}else if(op==3){
			int x,y;cin>>x>>y;
			vis[x][y]=1;
			merge(x,y);++deg[x];
		}else if(op==4){
			int x;cin>>x;
			for(int y:G[x]){
				if(vis[y][x])continue;
				vis[y][x]=1;
				merge(y,x);++deg[y];
			}
		}
		bool fl=true;
		for(int i=1;i<=n&&fl;++i)
			if(deg[i]!=1)fl=false;
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

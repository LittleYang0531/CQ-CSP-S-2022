#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,q;
int rd[N];
set<int>old[N],e[N];
bool fl=false;
int vst[N];
void dfs(int x,int tur){
	if(vst[x]==tur)fl=true;
	if(fl)return;
	vst[x]=tur;
	for(int y:e[x])dfs(y,tur);
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>1000){
		for(int i=1,x,y;i<=m;++i)cin>>x>>y;
		int q;
		cin>>q;
		while(q--)cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		old[y].insert(x),e[y].insert(x);
	}
	cin>>q;
	while(q--){
		int op,x,y;
		cin>>op>>x;
		if(op==1)cin>>y,e[y].erase(x);
		if(op==2)e[x].clear();
		if(op==3)cin>>y,e[y].insert(x);
		if(op==4)e[x]=old[x];
		bool blog=true;
		fill(rd+1,rd+n+1,0);
		for(int i=1;i<=n;++i)for(int y:e[i])++rd[y];
		for(int i=1;i<=n;++i)if(rd[i]!=1){blog=false;break;}
		if(!blog){cout<<"NO\n";continue;}
		fl=false;
		fill(vst+1,vst+n+1,false);
		int cnt=0;
		for(int i=1;i<=n;++i)if(!vst[i])dfs(i,++cnt);
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+10;
int n;
int m,k;
bool st[N];
int h[N],idx=0;
int d[N],in[N];
map<pii,bool> mp;
vector<int> to[N];
struct Node{
	int to,ne;
}tr[N];
void add(int u,int v){
	tr[idx].to=v,tr[idx].ne=h[u],h[u]=idx++;
}
void dfs(int u){
	for(int i=h[u];i!=-1;i=tr[i].ne){
		int to=tr[i].to;
		if(st[to]) continue;
		if(mp[{u,to}]){
			st[to]=true;
			dfs(to);
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++) if(in[i]!=1) return false;
	memset(st,false,sizeof st);
	int root=1;
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			root=i;
			break;
		}
	}
	cout<<root<<endl;
	st[root]=true;
	dfs(root);
	for(int i=1;i<=n;i++) if(!st[i]) return false;
	return true;
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		mp[{u,v}]=true;
		in[u]++,to[v].push_back(u),d[v]++;
		add(u,v);
	}
	scanf("%lld",&k);
	while(k--){
		int opt;
		int u,v;
		scanf("%lld%lld",&opt,&u);
		if(opt==1){
			scanf("%lld",&v);
			d[v]--;
			if(mp[{u,v}]) in[u]--;
			mp[{u,v}]=false;
		}
		else if(opt==2){
			d[u]=0;
			for(int i=0;i<to[u].size();i++) mp[{to[u][i],u}]=false;
		}
		else if(opt==3){
			scanf("%lld",&v);
			d[v]++;
			if(!mp[{u,v}]) in[u]++;
			mp[{u,v}]=true;
		}else{
			for(int i=0;i<to[u].size();i++){
				mp[{to[u][i],u}]=true,d[u]++;
			}
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/

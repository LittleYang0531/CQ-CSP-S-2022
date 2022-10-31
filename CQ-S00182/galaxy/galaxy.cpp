//Linkwish's code
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,Q;
vector<int> e[N];
int tot,rd[N],cd[N],tmp[N];
bool f[N],vis[N];
pair<int,int> edge[N];
map<pair<int,int>,bool> p;
bool dfs(int x){
	vis[x]=1;
	for(int to:e[x]){
		if(!vis[to]){
			if(dfs(to))return f[x]=1;
		}
		else return f[x]=1;
	}
	return f[x]=0;
}
inline bool check(){
	tot=0;
	for(int i=1;i<=n;i++)
		if(cd[i]!=1)return 0;
	for(int i=1;i<=m;i++)
		if(!p[{edge[i].first,edge[i].second}])tot++;
	if(tot!=n){
		return 0;
	}
	for(int i=1;i<=n;i++)vis[i]=f[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!rd[i]){
			dfs(i);
			if(!f[i])return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			if(!f[i])return 0;
		}
	}
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		rd[y]++,cd[x]++,edge[i]={x,y};
	}
	for(int i=1;i<=n;i++)tmp[i]=rd[i];
	int op,x,y;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&op,&x);
		if(op==1||op==3)scanf("%d",&y);
		if(op==1)p[{x,y}]=1,rd[y]--,cd[x]--;
		else if(op==2){
			rd[x]=0;
			for(int i=1;i<=m;i++)
				if(edge[i].second==x&&!p[{edge[i].first,edge[i].second}])
					cd[edge[i].first]--,p[{edge[i].first,edge[i].second}]=1;
		}
		else if(op==3)p[{x,y}]=0,rd[y]++,cd[x]++;
		else{
			rd[x]=tmp[x];
			for(int i=1;i<=m;i++)
				if(edge[i].second==x&&p[{edge[i].first,edge[i].second}])
					cd[edge[i].first]++,p[{edge[i].first,edge[i].second}]=0;
		}
		if(check())puts("YES");
		else puts("NO");
	}
	return 0;
}

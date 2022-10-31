#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,q,k,val[N];
int id,h[N],e[2*N],ne[2*N];
bool vis[N];
int dep[N],f[N][25];
vector<int> v1,v2;
ll dis[N],g[N];
void add(int a,int b){
	id++;
	ne[id]=h[a];
	h[a]=id;
	e[id]=b;
}
void dfs(int x){
	vis[x]=1;
	for(int i=h[x];i;i=ne[i]){
		if(!vis[e[i]]){
			dep[e[i]]=dep[x]+1;
			f[e[i]][0]=x;
			for(int j=1;j<=20;j++){
				f[e[i]][j]=f[f[e[i]][j-1]][j-1];
			}
			dis[e[i]]=dis[x]+val[e[i]];
			dfs(e[i]);
		}
	}
}
int lca(int x,int y){
	int res;
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y){
		res=y;
	}else{
		for(int i=20;i>=0;i--){
			if(f[x][i]!=f[y][i]){
				x=f[x][i];
				y=f[y][i];
			}
		}
		res=f[y][0];
	}
	return res;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dep[1]=1;
	dfs(1);
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		if(k==1){
			int lcast=lca(s,t);
			printf("%lld\n",dis[s]+dis[t]-dis[lcast]-dis[f[lcast][0]]);
		}else{
			v1.clear();
			if(dep[s]<dep[t]){
				swap(s,t);
			}
			while(dep[s]>dep[t]){
				v1.push_back(s);
				s=f[s][0];
			}
			while(s!=t){
				v1.push_back(s);
				v2.push_back(t);
				s=f[s][0];
				t=f[t][0];
			}
			v1.push_back(s);
			for(int i=v2.size()-1;i>=0;i--){
				v1.push_back(v2[i]);
			}
			v2.clear();
			g[0]=val[v1[0]];
			for(int i=1;i<v1.size();i++){
				g[i]=INF;
				for(int j=1;j<=k&&i-j>=0;j++){
					g[i]=min(g[i],g[i-j]);
				}
				g[i]+=val[v1[i]];
			}
			printf("%lld\n",g[v1.size()-1]);
		}
	}
	return 0;
}

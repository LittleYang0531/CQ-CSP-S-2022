#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;

struct edge{
	int v,w;
	edge(int V,int W){
		v=V;
		w=W;
	}
};

struct node{
	int u,dis;
	node(int U,int D){
		u=U;
		dis=D;
	}
	bool operator<(const node& a)const{
		return dis>a.dis;
	}
};

ll n,m,k,a[maxn],dis[maxn],ans;
bool vis[maxn];
priority_queue<node> q;
vector<int> Graph[maxn];

void dfs(int u,int ki,int g,ll sum){
	if(u==1&&ki==5){
		ans=max(ans,sum);
		return;
	}
	else if(ki==5){
		return;
	}
	for(int i=0;i<Graph[u].size();i++){
		int v=Graph[u][i];
		if(g==k){
			if(!vis[v]||(ki==4&&v==1)){
				vis[v]=1;
				dfs(v,ki+1,0,sum+a[v]);
				vis[v]=0;
			}
		}
		else{
			if(!vis[v]||(ki==4&&v==1)){
				vis[v]=1;
				dfs(v,ki+1,0,sum+a[v]);
				vis[v]=0;
			}
			dfs(v,ki,g+1,sum);
		}
	}
}

ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=2;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	vis[1]=1;
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}

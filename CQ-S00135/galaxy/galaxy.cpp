#include<bits/stdc++.h>
#define ll unsigned long long
#pragma GCC optimize(3)
#define N 500009
#define M 1000009
using namespace std;
int n,m,cnt,he[N],l,x,y,q,dfn[N],low[N],id[N],scc_cnt,stk[N],in_stk[N],top,Size[N],din[N],fg[N],timestamps;
struct Edge{
	int ne,to,flag;
}e[M];
void add(int u,int v){
	e[++cnt].ne=he[u];
	e[cnt].to=v;
	he[u]=cnt;
	e[cnt].flag=1;
}
void tarjan(int u){
	dfn[u]=low[u]=++timestamps;
	stk[++top]=u,in_stk[u]=1;
	for(int i=he[u];i;i=e[i].ne){
		if(e[i].flag==0){
			continue;
		}
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in_stk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int y;
		scc_cnt++;
		do{
			y=stk[top--],in_stk[y]=0;
			id[y]=scc_cnt;
			Size[scc_cnt]++;
		}
		while(y!=u);
	}
}
bool can(){
	scc_cnt=0;
	top=0;
	timestamps=0;
	for(int i=1;i<=n;i++){
		dfn[i]=low[i]=id[i]=in_stk[i]=Size[i]=din[i]=fg[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=he[i];j;j=e[j].ne){
			if(e[j].flag==0){
				continue;
			}
			int u=i,v=e[j].to;
			din[v]++;
			if(Size[id[u]]>1){
				fg[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(din[i]!=1){
			return 0;
		}
		if(!fg[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>y>>x;
		add(x,y);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>x;
		if(l==1||l==3){
			cin>>y;
			swap(x,y);
		}
		if(l==1){
			for(int i=he[x];i;i=e[i].ne){
				int v=e[i].to;
				if(v==y){
					e[i].flag=0;
				}
			}
		}
		else if(l==2){
			for(int i=he[x];i;i=e[i].ne){
				e[i].flag=0;
			}
		}
		else if(l==3){
			for(int i=he[x];i;i=e[i].ne){
				int v=e[i].to;
				if(v==y){
					e[i].flag=1;
				}
			}
		}
		else{
			for(int i=he[x];i;i=e[i].ne){
				e[i].flag=1;
			}
		}
		if(can()){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

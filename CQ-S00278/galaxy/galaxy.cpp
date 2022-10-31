#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Q,eid[5005][5005],h[500005],fa[500005],cd[500005];
int K,dfn[500005],low[500005],num,bl[500005],sz[500005],deg[500005];
struct edge{
	int to,nxt;
}e[500005];
vector<int>inc[500005],cnn[500005];
stack<int>S;
bool ban[500005],ins[500005],lnk[5005][5005];
void tarjan(int x){
	dfn[x]=low[x]=++K;
	ins[x]=1;
	S.push(x);
	for(int i=h[x];i;i=e[i].nxt)
	if(!ban[i]){
		int y=e[i].to;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x]){
		num++;
		int y;
		do{
			y=S.top();
			S.pop();
			bl[y]=num;
			sz[num]++;
			ins[y]=0;
		}while(y!=x);
	}
}
int gf(int x){
	if(fa[x]==x)return x;
	return fa[x]=gf(fa[x]);
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		eid[x][y]=i;
		inc[y].push_back(i);
		e[i]=(edge){y,h[x]};
		h[x]=i;
	}
	scanf("%d",&Q);
	while(Q--){
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			ban[eid[x][y]]=1;
		}
		if(op==2){
			for(auto id:inc[x])ban[id]=1;
		}
		if(op==3){
			scanf("%d",&y);
			ban[eid[x][y]]=0;
		}
		if(op==4){
			for(auto id:inc[x])ban[id]=0;
		}
		num=K=0;
		memset(dfn,0,sizeof(dfn));
		memset(sz,0,sizeof(sz));
		memset(cd,0,sizeof(cd));
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=n;i++)
			if(!dfn[i])tarjan(i);
		for(int i=1;i<=num;i++)fa[i]=i;
		for(int x=1;x<=n;x++)
			for(int i=h[x];i;i=e[i].nxt){
				int y=e[i].to;
				if(!ban[i])cd[x]++;
				if(!ban[i]&&bl[x]!=bl[y]&&!lnk[bl[x]][bl[y]]){
					lnk[bl[x]][bl[y]]=1;
					deg[bl[x]]++;
					int fx=gf(bl[x]),fy=gf(bl[y]);
					if(fx!=fy)fa[fx]=fy;
				}
			}
		for(int i=1;i<=num;i++)cnn[fa[i]].push_back(i);
		bool ans=1;
		for(int i=1;i<=n;i++)
			if(cd[i]!=1){
				ans=0;
				break;
			}
		for(int i=1;i<=num;i++)
			if(cnn[i].size()){
				int cnt=0;
				bool fl=1;
				for(auto x:cnn[i]){
					if(sz[x]>1){
						cnt++;
						if(cnt>1)break;
						if(deg[x]){
							fl=0;
							break;
						}
					}
				}
				if(!fl||cnt>1){
					ans=0;
					break;
				}
			}
		puts(ans?"YES":"NO");
		for(int i=1;i<=num;i++)cnn[i].clear();
		for(int x=1;x<=n;x++)
			for(int i=h[x];i;i=e[i].nxt)
				lnk[bl[x]][bl[e[i].to]]=0;
	}
	return 0;
}

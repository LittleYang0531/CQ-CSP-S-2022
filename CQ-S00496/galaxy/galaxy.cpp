#include<bits/stdc++.h>
using namespace std;
vector<int> v[500005];
map<int,int> mp[500005],vis[500005];
int n,m,Q,top=0,sign=0,scc=0;
int LOW[500005],DFN[500005],to[500005],inst[500005],st[500005],sz[500005],be[500005],rd[500005];
void Tarjan(int s) {
	DFN[s]=LOW[s]=++sign;
	inst[s]=1,st[++top]=s;
	for(int i=0;i<v[s].size();i++) {
		int y=v[s][i];
		if(!mp[s][y]) continue;
		if(!DFN[y]) {
			Tarjan(y);
			LOW[s]=min(LOW[s],LOW[y]);
		}else if(inst[y]) LOW[s]=min(LOW[s],DFN[y]);
	}
	if(DFN[s]==LOW[s]) {
		int t;scc++;
		do {
			t=st[top--];
			be[t]=scc;
			sz[scc]++;
			inst[t]=0;
		}while(t!=s);
	}
}
struct o {
	int x,y;
}e[500005];
signed main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int x,y;scanf("%d%d",&x,&y);
		v[x].push_back(y);
		mp[x][y]=1,to[x]++,vis[x][y]=1;
		e[i]={x,y};
	}
	scanf("%d",&Q);
	while(Q--) {
		int op,x,y;scanf("%d%d",&op,&x);
		if(op==1) {
			scanf("%d",&y);
			mp[x][y]=0;
			to[x]--;
		}
		if(op==2) {
			for(int i=1;i<=n;i++) {
				if(vis[i][x]) {
					if(mp[i][x]) to[i]--;
					mp[i][x]=0;
				}
			}
		}
		if(op==3) {
			scanf("%d",&y);
			mp[x][y]=1;
			to[x]++;
		}
		if(op==4) {
			for(int i=1;i<=n;i++) {
				if(vis[i][x]) {
					if(!mp[i][x]) to[i]++;
					mp[i][x]=1;
				}
			}
		}
		sign=0,top=0,scc=0;
		for(int i=1;i<=n;i++) DFN[i]=LOW[i]=inst[i]=sz[i]=be[i]=rd[i]=0;
		for(int i=1;i<=n;i++) {
			if(!DFN[i]) Tarjan(i);
		}
		for(int i=1;i<=m;i++) {
			int x=e[i].x,y=e[i].y;
			if(mp[x][y]) rd[be[x]]++;
		}
		int fg=0;
		for(int i=1;i<=scc;i++) {
			if(rd[i]==0&&sz[i]==1) fg=1;
		}
		for(int i=1;i<=n;i++) {
			if(to[i]>1) {
				fg=1;break;
			}
		}
		if(fg) puts("NO");
		else puts("YES");
	}
	return 0;
}

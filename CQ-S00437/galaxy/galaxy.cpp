#include<bits/stdc++.h>
using namespace std;
int n,m,q,cnt,d[500005];
bool del[500005];
struct node{int x,y;}w[500005];
vector<int>e[500005],f[500005];
map<pair<int,int>,int>id;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&w[i].x,&w[i].y),id[{w[i].x,w[i].y}]=i,e[w[i].y].push_back(i),d[w[i].x]++;
	for(int i=1;i<=n;i++)if(d[i]==1)cnt++;
	scanf("%d",&q);
	while(q--) {
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1) {
			scanf("%d",&y),del[id[{x,y}]]=1,d[x]--;
			if(!d[x])cnt--;
			else if(d[x]==1)cnt++;
		}else if(op==2) {
			for(auto y:e[x]) {
				if(!del[y]) {
					del[y]=1,d[w[y].x]--;
					if(!d[w[y].x])cnt--;
					else if(d[w[y].x]==1)cnt++;
				}
			}
		}else if(op==3) {
			scanf("%d",&y),del[id[{x,y}]]=0,d[x]++;
			if(d[x]==2)cnt--;
			else if(d[x]==1)cnt++;
		}else {
			for(auto y:e[x]) {
				if(del[y]) {
					del[y]=0,d[w[y].x]++;
					if(d[w[y].x]==2)cnt--;
					else if(d[w[y].x]==1)cnt++;
				}
			}
		}
		puts(cnt==n?"YES":"NO");
	}
	return 0;
}

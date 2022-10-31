#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define fi first
#define se second
using namespace std;
const int Maxn=5e5;
vector<int>bel[Maxn+5];
map<int,int>id[Maxn+5];
int s[Maxn+5],cnt[Maxn+5],b[Maxn+5];
int n,m;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tot=0;
	for(ri i=1;i<=m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		bel[y].push_back(i);
		id[x][y]=i;
		s[i]=x;
		++cnt[x];
	}
	for(ri i=1;i<=n;i++)
		if(cnt[i]==1)++tot;
	int q;
	scanf("%d",&q);
	while(q--) {
		int t,u;
		scanf("%d%d",&t,&u);
		if(t==1) {
			int v;
			scanf("%d",&v);
			int x=id[u][v];
			b[x]=1,--cnt[s[x]];
			if(cnt[s[x]]==1)++tot;
			else --tot;
		}
		else if(t==2) {
			for(ri x:bel[u])
				if(!b[x]) {
					b[x]=1,--cnt[s[x]];
					if(cnt[s[x]]==1)++tot;
					else --tot;
				}
		}
		else if(t==3) {
			int v;
			scanf("%d",&v);
			int x=id[u][v];
			b[x]=0,++cnt[s[x]];
			if(cnt[s[x]]==1)++tot;
			else --tot;
		}
		else {
			for(ri x:bel[u])
				if(b[x]) {
					b[x]=0,++cnt[s[x]];
					if(cnt[s[x]]==1)++tot;
					else --tot;
				}
		}
		if(tot==n) {
			putchar('Y'),putchar('E'),putchar('S');
		}
		else {
			putchar('N'),putchar('O');
		}
		putchar('\n');
	}
	return 0;
}


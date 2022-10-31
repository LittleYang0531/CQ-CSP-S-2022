#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define wr(x,ch) write(x),putchar(ch)
using namespace std;
ll read() {
	ll x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
void write(ll x) {
	if(x<0) putchar('-'),x=~(x-1);
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
const int N=1005;
vector<int> G[N],H[N];
bool vis[N],tmp[N];
int n,m,id[N][N],u,v,s[N],q,op;
bool dfs(int p) {
	vis[p]=1;
	if(tmp[p]) return 1;
	for(ull i=0;i<G[p].size();i++) {
		if(H[p][i]&&vis[G[p][i]]==0) {
			if(!dfs(G[p][i])) return 0;
		}
	}
	vis[p]=0;
	tmp[p]=1;
	return 1;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
//	freopen("galaxy3.in","r",stdin);
//	freopen("galaxy3.out","w",stdout);
	n=read(),m=read();
	memset(id,-1,sizeof(id));
	for(int i=1;i<=m;i++) u=read(),v=read(),s[u]++,id[u][v]=G[u].size(),G[u].push_back(v),H[u].push_back(1);
	q=read();
	while(q--) {
		op=read();
		if(op==1) {
			u=read(),v=read();
			if(H[u][id[u][v]]) --s[u],H[u][id[u][v]]=0;
		}else if(op==2) {
			u=read();
			for(int i=1;i<=n;i++) if((~id[i][u])&&H[i][id[i][u]]) --s[i],H[i][id[i][u]]=0;
		}else if(op==3) {
			u=read(),v=read();
			if(!H[u][id[u][v]]) ++s[u],H[u][id[u][v]]=1;
		}else {
			u=read();
			for(int i=1;i<=n;i++) if((~id[i][u])&&!H[i][id[i][u]]) ++s[i],H[i][id[i][u]]=1;
		}
		bool flag=1;
		for(int i=1;i<=n;i++) {
			vis[i]=tmp[i]=0;
			if(s[i]^1) {
				flag=0;
				break;
			}
		}
		if(flag&&dfs(1)) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
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

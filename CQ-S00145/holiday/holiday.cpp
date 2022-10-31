#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define fi(s) freopen(s".in","r",stdin)
#define fo(s) freopen(s".out","w",stdout)
using namespace std;
namespace tomorinao {
char arrs;int read() {
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;}
const int maxn = 2510;
int n,m,K,d[maxn][maxn],w[maxn],ans;vector<int>g[maxn],ve[maxn];
void add(int x,int y) {g[x].push_back(y),g[y].push_back(x);}
void dij(int s) {
	queue<int>q;q.push(s),d[s][s]=1;
	while(!q.empty()) {
		int x=q.front();q.pop();
		if(d[s][x]==K+2) continue;
		for(int y:g[x]) if(!d[s][y]) {
			d[s][y]=d[s][x]+1;
			q.push(y);
		}
	}
}
char arrt;void Main() {
	cerr<<fixed<<setprecision(1)<<(&arrt-&arrs)/1024./1024<<'\n';
	file("holiday");
	n=read(),m=read(),K=read();
	for(int i=2;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) dij(i);
	for(int B=2;B<=n;B++) {
		for(int A=2;A<=n;A++) if(A^B)
			if(d[1][A]&&d[A][B]) ve[B].push_back(A);
		sort(ve[B].begin(),ve[B].end(),[](int x,int y){return w[x]>w[y];});
		// 找到所有可以做 AD 的候选，按照从大到小排列 
	}
	for(int C=2;C<=n;C++) {
		for(int B=2;B<=n;B++) if(B!=C&&d[B][C]) {
			for(int i=0,t=min(5,(int)ve[B].size());i<t;i++)
				for(int j=0,t2=min(5,(int)ve[C].size());j<t2;j++) {
					int A=ve[B][i],D=ve[C][j];
					if(A!=C&&A!=D&&B!=D) ans=max(ans,w[A]+w[B]+w[C]+w[D]);
				}
		}
	}cout<<ans<<'\n';
}}signed main() {tomorinao::Main();}

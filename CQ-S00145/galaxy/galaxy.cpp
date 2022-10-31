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
const int maxn = 5e5+10;
int n,m,X[maxn],Y[maxn],q,d[maxn],ans;vector<int>g[maxn];
int mp[1010][1010];map<int,char>ton[maxn];
char arrt;void Main() {
	cerr<<fixed<<setprecision(1)<<(&arrt-&arrs)/1024./1024<<'\n';
	file("galaxy");
	n=read(),m=read();
	for(int i=1;i<=m;i++) X[i]=read(),Y[i]=read(),g[Y[i]].push_back(X[i]),++d[X[i]];
	for(int i=1;i<=n;i++) ans+=(d[i]==1);
	q=read();
	if(n<=1e3&&m<=1e4&&q<=1e3) {
		for(int i=1;i<=m;i++) mp[X[i]][Y[i]]=1;
		for(int i=1,t,x,y;i<=q;i++) {
			t=read();
			if(t==1) {
				x=read(),y=read();
				mp[x][y]=0;
				--d[x];
				if(d[x]==0) --ans;
				if(d[x]==1) ++ans;
			}
			else if(t==2) {
				x=read();
				for(int y:g[x]) if(mp[y][x]) {
					mp[y][x]=0;
					--d[y];
					if(d[y]==0) --ans;
					if(d[y]==1) ++ans;
				}
			}
			else if(t==3) {
				x=read(),y=read();
				mp[x][y]=1;
				++d[x];
				if(d[x]==2) --ans;
				if(d[x]==1) ++ans;
			} else if(t==4) {
				x=read();
				for(int y:g[x]) if(!mp[y][x]) {
					mp[y][x]=1;
					++d[y];
					if(d[y]==2) --ans;
					if(d[y]==1) ++ans;
				}
			}
			if(ans==n) cout<<"YES\n";
			else cout<<"NO\n";
		}return;
	} else {
		for(int i=1;i<=m;i++) ton[Y[i]][X[i]]=1;
		for(int i=1,t,x,y;i<=q;i++) {
			t=read();
			if(t==1) {
				x=read(),y=read();
				ton[y].erase(x);
				--d[x];
				if(d[x]==0) --ans;
				if(d[x]==1) ++ans;
			}
			else if(t==2) {
				y=read();
				for(auto z:ton[y]) {
					int x=z.first;
					--d[x];
					if(d[x]==0) --ans;
					if(d[x]==1) ++ans;
				}ton[y].clear();
			}
			else if(t==3) {
				x=read(),y=read();
				ton[y][x]=1;
				++d[x];
				if(d[x]==2) --ans;
				if(d[x]==1) ++ans;
			}
			if(ans==n) cout<<"YES\n";
			else cout<<"NO\n";
		}return;
	}
}}signed main() {tomorinao::Main();}

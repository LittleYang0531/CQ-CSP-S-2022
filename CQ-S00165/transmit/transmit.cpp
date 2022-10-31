#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(xx) xx.begin(), xx.end()

using ll = long long;

ifstream __fin("transmit.in");
ofstream __fout("transmit.out");
#define cin __fin
#define cout __fout

struct seginfo {
	int fa;
	ll s[3][3];
} bee[200005][19];

int va[200005];
int k;
int clo;
int beg[200005], en[200005];
vector<int> elist[200005];
void dfs(int i, int f) {
	bee[i][0].fa = f;
	for(int j=0;j<k;j++) for(int j2=0;j2<k;j2++)
		bee[i][0].s[j][j2] = 1e18;
	for(int j=0;j<k;j++) {
		bee[i][0].s[j][0]=va[i];
		if(k==3&&j==1){
			int c = va[i];
			for(int v:elist[i])
				c=min(c,va[v]);
			bee[i][0].s[j][1]=c;
		}
		if(j!=k-1) bee[i][0].s[j][j+1]=0;
	}
	beg[i] = clo++;
	// mer
	for(int l=1; l<19; l++) {
		int ff = bee[i][l-1].fa;
		bee[i][l].fa = bee[ff][l-1].fa;
		for(int j=0;j<k;j++) for(int j2=0;j2<k;j2++)
			bee[i][l].s[j][j2] = 1e18;
		for(int j=0;j<k;j++) for(int m=0; m<k;m++) for(int j2=0;j2<k;j2++)
			bee[i][l].s[j][j2] = min(bee[i][l].s[j][j2], bee[i][l-1].s[j][m]+bee[ff][l-1].s[m][j2]);
	}
	for(int v:elist[i]) if(v!=f) dfs(v,i);
	en[i] = clo;
}

int lca(int u, int v) {
	if(beg[u] <= beg[v] && beg[v] < en[u]) return u;
	for(int i=18;i>=0;i--) {
		int nu = bee[u][i].fa;
		if(!(beg[nu] <= beg[v] && beg[v] < en[nu])) u = nu;
	}
	return bee[u][0].fa;
}

ll st[3], nst[3];
ll st2[3];

ll qry(int u, int v) {
	if(u == v) return va[u];
	if(beg[u] <= beg[v] && beg[v] < en[u]) {
		for(int i=0;i<k;i++) st[i]=va[v];
		v=bee[v][0].fa;
		for(int i=18;i>=0;i--) {
			int nv = bee[v][i].fa;
			if(!(beg[nv] <= beg[u] && beg[u] < en[nv]) || nv == u) {
				for(int j=0;j<k;j++) nst[j]=1e18;
				for(int j=0;j<k;j++)for(int j2=0;j2<k;j2++)
					nst[j2]=min(nst[j2],st[j]+bee[v][i].s[j][j2]);
				for(int j=0;j<k;j++) st[j]=nst[j];
				v = nv;
			}
		}
		ll ans=1e18;
		for(int i=0;i<k;i++) ans=min(ans,st[i]);
		return ans+va[u];
	}
	if(beg[v] <= beg[u] && beg[u] < en[v])
		return qry(v, u);
	int lc = lca(u,v);
	for(int i=0;i<k;i++) st[i] = va[u], st2[i] = va[v];
	u = bee[u][0].fa, v = bee[v][0].fa;
	for(int i=18;i>=0;i--) {
		int nu = bee[u][i].fa;
		if(!(beg[nu] <= beg[lc] && beg[lc] < en[nu]) || nu == lc) {
			for(int j=0;j<k;j++) nst[j]=1e18;
			for(int j=0;j<k;j++)for(int j2=0;j2<k;j2++)
				nst[j2]=min(nst[j2],st[j]+bee[u][i].s[j][j2]);
			for(int j=0;j<k;j++) st[j]=nst[j];
			u = nu;
		}
		int nv = bee[v][i].fa;
		if(!(beg[nv] <= beg[lc] && beg[lc] < en[nv]) || nv == lc) {
			for(int j=0;j<k;j++) nst[j]=1e18;
			for(int j=0;j<k;j++)for(int j2=0;j2<k;j2++)
				nst[j2]=min(nst[j2],st2[j]+bee[v][i].s[j][j2]);
			for(int j=0;j<k;j++) st2[j]=nst[j];
			v = nv;
		}
	}
//	cout<<u<<' '<<v<<' '<<lc<<endl;
	ll ans1 = 1e18, ans2 = 1e18, ans3 = 1e18;
	for(int i=0;i<k;i++) for(int j=0;j<k;j++) {
//		cout<<i<<' '<<j<<' '<<st[i]<<' '<<st2[j]<<endl;
		if((i+1)+(j+1)<=k) ans1=min(ans1,st[i]+st2[j]);
		if(k==3&&i==1&&j==1) ans2=min(ans2,st[i]+st2[j]);
		ans3=min(ans3,st[i]+st2[j]);
	}
	ans3 += va[lc];
	ans2 += bee[lc][0].s[1][1];
//	cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
	return min(ans1,min(ans2,ans3));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int q; cin >> q;
	cin >> k;
	en[0] = 1e9;
	for(int i=1;i<=n;i++)cin>>va[i];
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		elist[u].pb(v);
		elist[v].pb(u);
	}
	dfs(1,0);
	for(int i=0;i<q;i++){
		int u,v;cin>>u>>v;
		cout<<qry(u,v)<<'\n';
	}
	cout.flush();
	return 0;
}

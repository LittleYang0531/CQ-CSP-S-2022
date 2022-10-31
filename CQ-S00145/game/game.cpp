#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define fi(s) freopen(s".in","r",stdin)
#define fo(s) freopen(s".out","w",stdout)
using namespace std;
typedef long long ll;
namespace tomorinao {
char arrs;int read() {
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;}
const int maxn = 1e5+10;
int pw[114],Lg[maxn];
struct info {
	int s[3][maxn],mx[2][maxn][19],mn[2][maxn][19],n,a[maxn];
	void csh() {
		pw[0]=1,Lg[0]=-1;
		for(int i=1;i<=n;i++) {
			Lg[i]=Lg[i>>1]+1;
			a[i]=read();
			mn[0][i][0]=mn[1][i][0]=INT_MAX,mx[1][i][0]=mx[0][i][0]=INT_MIN;
			s[0][i]=s[0][i-1],s[1][i]=s[1][i-1],s[2][i]=s[2][i-1];
			if(a[i]>0) ++s[0][i],mn[0][i][0]=mx[0][i][0]=a[i];
			else if(a[i]<0) ++s[1][i],mn[1][i][0]=mx[1][i][0]=a[i];
			else ++s[2][i];
		}
		for(int w=0;w<2;w++)
			for(int i=1;(pw[i]=pw[i-1]<<1)<=n;i++)
				for(int j=1;pw[i]+j<=n+1;j++)
					mn[w][j][i]=min(mn[w][j][i-1],mn[w][j+pw[i-1]][i-1]),
					mx[w][j][i]=max(mx[w][j][i-1],mx[w][j+pw[i-1]][i-1]);
	}
	int l,r;
	int askmax(int w) {
		int L=Lg[r-l+1];
		return max(mx[w][l][L],mx[w][r-pw[L]+1][L]);
	}
	int askmin(int w) {
		int L=Lg[r-l+1];
		return min(mn[w][l][L],mn[w][r-pw[L]+1][L]);
	}
	int E(int w) {return (s[w][r]-s[w][l-1]?1:0);}
}s1,s2;int q;
char arrt;void Main() {
	cerr<<fixed<<setprecision(1)<<(&arrt-&arrs)/1024./1024<<'\n';
	file("game");
//	file("game4");
	s1.n=read(),s2.n=read(),q=read();
	s1.csh(),s2.csh();
	while(q--) {
		s1.l=read(),s1.r=read(),s2.l=read(),s2.r=read();
		if(s2.E(0)==0) {// min 人全负/0 
			ll c1=min(s1.askmin(0),s1.askmin(1));
			if(s1.E(2)) c1=min(c1,0ll);
			if(c1<0) cout<<c1*(s2.E(2)?0:s2.askmax(1))<<'\n';
			else if(c1==0) cout<<0<<'\n';
			else cout<<c1*(s2.E(1)?s2.askmin(1):0)<<'\n';
		}else
		if(s2.E(1)==0) {// min 人全正/0 
			ll c1=max(s1.askmax(0),s1.askmax(1));
			if(s1.E(2)) c1=max(c1,0ll);
			if(c1>0) cout<<c1*(s2.E(2)?0:s2.askmin(0))<<'\n';
			else if(c1==0) cout<<0<<'\n';
			else cout<<c1*(s2.E(0)?s2.askmax(0):0)<<'\n';
		}else {
			// min 人有负有正，可能有 0 
			if(s1.E(2)) cout<<0<<'\n';
			else if(s1.E(1)==0) cout<<1ll*s1.askmin(0)*s2.askmin(1)<<'\n';
			else if(s1.E(0)==0) cout<<1ll*s1.askmax(1)*s2.askmax(0)<<'\n';
			else cout<<max(1ll*s1.askmin(0)*s2.askmin(1),1ll*s1.askmax(1)*s2.askmax(0))<<'\n';
		}
	}
}}signed main() {tomorinao::Main();}

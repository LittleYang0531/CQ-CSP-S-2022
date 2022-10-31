#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100005;
int n,m,q;
int a[MAXN],b[MAXN];
int minn[MAXN][MAXN];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=q;i++){
		int x,y,l,r;
		scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
		int min_max=-1e18;
		for(int c=x;c<=y;c++){
			int x_min=1e18;
			for(int d=l;d<=r;d++){
				x_min=min(x_min,a[c]*b[d]);
			}
			min_max=max(min_max,x_min);
		}
		printf("%lld\n",min_max);
	}
	return 0;
}

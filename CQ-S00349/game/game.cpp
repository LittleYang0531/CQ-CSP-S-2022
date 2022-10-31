#include<bits/stdc++.h>
#define NM "game"
#define flp(i, n) for(int i=1; i<=n; ++i)
#define flp(i, a, n) for(int i=a; i<=n; ++i)
using namespace std;
const int N=1e4+5;
int a[N], b[N], c[N][N];
int main() {
	freopen(NM".in", "r", stdin);
	freopen(NM".out", "w", stdout);
	int n, m, q;
	cin>>n>>m>>q;
	flp(i, n)
		scanf("%d", a+i);
	flp(i, m)
		scanf("%d", b+i);
	flp(i, n)
		flp(j, m)
			c[i][j]=a[i]*b[j];
	while(q--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(l1==r1) {
			int ans=1e9;
			flp(i, l2, r2)
				ans=min(ans, c[l1][i]);
			cout<<ans<<endl;
		} else if(l2==r2) {
			int ans=-1e9;
			flp(i, l1, r1)
				ans=max(ans, c[i][l2]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
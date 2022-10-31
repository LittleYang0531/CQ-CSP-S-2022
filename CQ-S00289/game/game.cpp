#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int A[1005];
int B[1005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin >> n>> m >> q;
	for (int i =1;i <= n;i++) {
		cin >>A[i];
	}
	for (int i = 1;i <= m;i++) {
		cin >> B[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			a[i][j] = A[i] * B[j];
		}
	}
	for (int i=1;i <= n;i++) {
		int maxn = 0,minn = 0x3f3f3f3f;
		for (int j = 1;j <= m;j++) {
			maxn = max(maxn,a[i][j]),minn = min(minn,a[i][j]);
		}
		B[i] = minn;
		A[i] = maxn - minn;
	}
	
	for (int i = 1;i <= q;i++) {
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 == r1) {
			cout << B[i] <<endl;
			continue;
		}else if (l2 == r2) {
			int man = 0;
			for (int j = l1;j <= r1;j++) {
				man = max(man,a[j][l2]);
			}
			cout << man << endl;
			continue;
		}
		int cha,ans;
		cha = 0x3f3f3f3f;
		ans = cha;
		for (int j = l1;j <= r1;j++) {
			if (cha > A[j] && B[j] < ans) {
				cha = A[j];
				ans = B[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

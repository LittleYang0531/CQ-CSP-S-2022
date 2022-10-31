#include <bits/stdc++.h>
#define ll long long
const ll N = 10005;
using namespace std;
ll n,m,q,x,y,arr[N],brr[N],crr[N][N],minrr[N],l1,r1,l2,r2,minn = 10000000000,maxx = -10000000000,maxi,mini;
int main(){
	freopen("r","game.in",stdin);
	freopen("w","game.out",stdout);
	cin >> n >> m >> q;
	for (int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for (int i = 1;i <= m;i++){
		cin >> brr[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			crr[i][j] = arr[i] * brr[j];
		}
	}
	while (q--){
		cin >> l1 >> r1 >> l2 >> r2;
		for (int i = l1;i <= r1;i++){
			minn = crr[i][l2];
			for (int j = l2;j <= r2;j++){
				if (crr[i][j] < minn){
					minn = crr[i][j];
				}
			}
			minrr[i] = minn;
		}
		maxx = -10000000000;
		for (int i = l1;i <= r1;i++){
			if (minrr[i] > maxx){
				maxx = minrr[i];
				maxi = i;
			}
		}
		x = maxi;
		minn = 10000000000;
		for (int i = l2;i <= r2;i++){
			if (crr[x][i] < minn){
				minn = crr[x][i];
				mini = i;
			}
		}
		y = mini;
		cout << crr[x][y] << endl;
	}
	return 0;
} 

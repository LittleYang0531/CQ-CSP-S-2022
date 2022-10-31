#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100005;

int n, m, q, z[N][N], a[N], b[N], l1, r1, l2, r2, minn = -0x3f3f3f3f, minnn = 0x3f3f3f3f;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d%d", &n, &m, &q);
	
	for(int i = 1; i <= n; i ++ ){
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= m; i ++ ){
		scanf("%d", &b[i]);
		for(int j = 1; j <= n; j ++ ){
			z[i][j] = a[j] * b[i];
		}
	}

	while(q -- ){
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		minn = -0x3f3f3f3f;
		for(int i = l1; i <= r1; i ++ ){
			minnn = 0x3f3f3f3f;
			for(int j = l2; j <= r2; j ++ ){
				minnn = min(z[j][i], minnn);
			}
			minn = max(minn, minnn);
		}
		printf("%d\n", minn);
	}


	return 0;
}


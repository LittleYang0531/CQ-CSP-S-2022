#include<bits/stdc++.h>
using namespace std;
int n,q,k;
bool a[10010][10010];
long long v[100010];
int floyed(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				f[i][j] = min(f[i][j],f[i][k]+f[k][j])
			}
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d%d",x,y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

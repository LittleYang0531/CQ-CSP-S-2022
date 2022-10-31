#include<bits/stdc++.h>
using namespace std;

const int N = 2505;

int mp[N][N],n,m,k,a,b;
long long v[N];

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		mp[a][b]=v[b];mp[b][a]=v[a];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				mp[j][k]=max(mp[j][i]+mp[i][k],mp[j][k]);
			}
		}
	}
	printf("%d",mp[n][n]);
	return 0;
}

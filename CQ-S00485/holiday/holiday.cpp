#include<bits/stdc++.h>
using namespace std;
long long f[305][305];//i到j
int sum[305][305];
long long s[10005],ans=-1;
int n,m,k;
void holiday() {
	for(int o=1; o<=n; o++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				sum[i][j]=min(sum[i][o]+sum[o][j],sum[i][j])+1;//i~j,sum[i][j]次转车可以到
			}
		}
	}
	for(int o=1; o<=n; o++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(sum[i][j]!=-1&&sum[i][j]-1<=k)
					f[i][j]+=s[j];
				ans=max(ans,f[i][j]);
			}
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum[i][j]=-1;
	int x,y;
	for(int i=1; i<=n-1; i++) scanf("%lld",&s[i]);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		sum[x][y]=0;
		sum[y][x]=0;
	}
	holiday();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%lld ",f[i][j]);
		}
		printf("\n");
	}
	printf("%lld",ans);
	return 0;
}


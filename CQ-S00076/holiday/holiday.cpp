#include <bits/stdc++.h>
using namespace std;
int a[2501][2501],i,j,k,n,m,x,y,kl[2501][2501],l,r;
long long v[2501],ans=0;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=2;i<=n;i++) scanf("%lld",&v[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		kl[x][y]=1;
		kl[y][x]=1;
	}
	for(l=1;l<=n;l++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(kl[i][j]==0||a[i][j]>a[i][l]+a[l][j]+1&&kl[i][l]==1&&kl[j][l]==1){
					a[i][j]=a[i][l]+a[j][l]+1;
					a[j][i]=a[i][j];
					kl[i][j]=1;
					kl[j][i]=1; 
				}
	for(i=2;i<=n;i++)
		if(a[1][i]<=k)
			for(j=2;j<=n;j++)
				if(i!=j&&a[j][i]<=k)
				for(l=2;l<=n;l++)
					if(l!=j&&l!=i&&a[l][j]<=k)
					for(r=2;r<=n;r++)
						if(l!=r&&i!=r&&j!=r&&a[l][r]<=k&&a[r][1]<=k&&kl[r][1]==1)
							ans=max(ans,v[i]+v[j]+v[l]+v[r]);
	printf("%lld",ans);
	return 0;
}

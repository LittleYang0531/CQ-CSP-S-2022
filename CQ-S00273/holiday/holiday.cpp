#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int a[2505];
int f[2505][2505];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		f[u][v]=f[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)if(f[i][k]!=0&&f[k][j]!=0){
				if(f[i][j]!=0)f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				else f[i][j]=f[j][i]=f[i][k]+f[k][j];
			}
		}
	}
	for(int a1=2;a1<=n;a1++)if(f[1][a1]-1<=k){
		for(int a2=a1+1;a2<=n;a2++)if(f[a1][a2]-1<=k){
			for(int a3=a2+1;a3<=n;a3++)if(f[a2][a3]-1<=k){
				for(int a4=a3+1;a4<=n;a4++)if(f[a3][a4]-1<=k){
					if(f[a4][1]-1<=k){
						ans=max(ans,a[a1]+a[a2]+a[a3]+a[a4]);
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 

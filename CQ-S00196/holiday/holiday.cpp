#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,a[2505][2505],sum[2505],f[2505][5];
long long s[2505],ans,ans1;
bool b[2505][2505];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),memset(a,0x3f,sizeof(a));
	for(int i=2;i<=n;i++)scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),a[x][y]=1,a[y][x]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int l=1;l<=n;l++)if(j!=l)a[j][l]=min(a[j][l],a[j][i]+a[i][l]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&a[i][j]<=k+1)b[i][j]=1;
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)if(b[i][j]&&b[j][1]){
		if(s[j]>=s[f[i][0]])f[i][2]=f[i][1],f[i][1]=f[i][0],f[i][0]=j,sum[i]++;
		else if(s[j]>=s[f[i][1]])f[i][2]=f[i][1],f[i][1]=j,sum[i]++;
		else if(s[j]>=s[f[i][2]])f[i][2]=j,sum[i]++;
	}
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)for(int l=2;l<=n;l++)if(i!=j&&i!=l&&j!=l&&b[1][i]&&b[i][j]&&b[j][l]){
		if(sum[l]>0&&i!=f[l][0]&&j!=f[l][0])ans=max(ans,s[i]+s[j]+s[l]+s[f[l][0]]);
		else if(sum[l]>1&&i!=f[l][1]&&j!=f[l][1])ans=max(ans,s[i]+s[j]+s[l]+s[f[l][1]]);
		else if(sum[l]>2)ans=max(ans,s[i]+s[j]+s[l]+s[f[l][2]]);
	}
	printf("%lld",ans);
	return 0;
}

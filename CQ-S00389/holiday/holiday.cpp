#include<bits/stdc++.h>
#define ll long long
ll n,m,k,a[100000],dp[1000][1000],ans=-1e9,flag=0;
using namespace std;
int main() {
  freopen("holiday.in","r",stdin);
  freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n-1; i++)	cin>>a[i];
	for(int i=1; i<=m; i++) {
		ll x,y;
		cin>>x>>y;
		dp[x][y]=1;
		dp[y][x]=1;
	}
	for(int i=1; i<=m; i++) {
		ll flag=0,jd=0,sum=0;
		for(int j=1; j<=m; j++) { //1
			if(dp[1][j]==1) {
				for(int o=1; o<=m; o++) //2
					if(dp[j][o]==1) {
						for(int l=1; l<=m; l++) //3
							if(dp[o][l]==1) {
								for(int y=1; y<=m; y++) //4
									if(dp[l][y]==1)
										for(int q=1; q<=m; q++) //5
											if(dp[y][q]==1) {
												{
													if(q==1&&j!=o&&j!=l&&j!=y&&j!=q&&l!=o&&y!=o&&q!=o&&y!=l&&q!=l&&y!=q) {
														sum=a[j-1]+a[o-1]+a[l-1]+a[y-1]+a[q-1];
														cout<<a[j-1]<<" "<<a[o-1]<<" "<<a[l-1]<<" "<<a[y-1]<<" "<<a[q-1]<<" "<<sum<<endl;
													}

												}
											}
							}
					}
			}
		}
		if(sum>ans)
			ans=sum;
	}
	cout<<ans;
	return 0;
}


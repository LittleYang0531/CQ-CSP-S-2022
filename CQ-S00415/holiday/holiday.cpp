#include<bits/stdc++.h>
using namespace std;
long long c=1,h[2505],x,y,n,m,k,a[2505],ans,aans,f[2505][2505],flag[1005],sum[2505];
void dfs(int d,int s) {
	if(s==4) {
		for(int i=1; i<=sum[d]; i++)
			if(f[d][i]==1) {
				if(ans>aans)
					aans=ans;
				break;
			}
		return;
	} else {
		for(int i=1; i<=sum[d]; i++) {
			if(flag[f[d][i]]==0) {
				ans+=a[f[d][i]];
				flag[f[d][i]]=1;
				s++;
				dfs(f[d][i],s);
				s--;
				ans-=a[f[d][i]];
				flag[f[d][i]]=0;
			}

			if(k>=1)
				for(int l=1; l<=sum[d]; l++) {
					int dd=f[d][l];
					for(int j=1; j<=sum[dd]; j++)
						if(flag[f[dd][j]]==0) {
							ans+=a[f[dd][j]];
							flag[f[dd][j]]=1;
							s++;
							dfs(f[dd][j],s);
							s--;
							ans-=a[f[dd][j]];
							flag[f[dd][j]]=0;
						}
				}
			if(k>=2)
				for(int l=1; l<=sum[d]; l++) {
					int dd=f[d][l];
					for(int j=1; j<=sum[dd]; j++) {
						int ddd=f[dd][j];
						for(int k=1; k<=sum[ddd]; k++) {
							if(flag[f[ddd][k]]==0) {
								ans+=a[f[ddd][k]];
								flag[f[ddd][k]]=1;
								s++;
								dfs(f[ddd][k],s);
								s--;
								ans-=a[f[ddd][k]];
								flag[f[ddd][k]]=0;
							}
						}
					}
				}
			if(k>=3)
				for(int l=1; l<=sum[d]; l++) {
					int dd=f[d][l];
					for(int j=1; j<=sum[dd]; j++) {
						int ddd=f[dd][j];
						for(int k=1; k<=sum[ddd]; k++) {
							int dddd=f[ddd][k];
							for(int q=1; q<=sum[dddd]; q++) {
								if(flag[f[dddd][q]]==0) {
									ans+=a[f[dddd][q]];
									flag[f[dddd][q]]=1;
									s++;
									dfs(f[dddd][q],s);
									s--;
									ans-=a[f[dddd][q]];
									flag[f[dddd][q]]=0;
								}
							}
						}
					}
				}
			if(k>=4)
				for(int l=1; l<=sum[d]; l++) {
					int dd=f[d][l];
					for(int j=1; j<=sum[dd]; j++) {
						int ddd=f[dd][j];
						for(int k=1; k<=sum[ddd]; k++) {
							int dddd=f[ddd][k];
							for(int q=1; q<=sum[dddd]; q++) {
								int ddddd=f[ddddd][q];
								for(int w=1; w<=sum[ddddd]; w++) {
									if(flag[f[ddddd][w]]==0) {
										ans+=a[f[ddddd][w]];
										flag[f[ddddd][w]]=1;
										s++;
										dfs(f[ddddd][w],s);
										s--;
										ans-=a[f[ddddd][w]];
										flag[f[ddddd][w]]=0;
									}
								}
							}
						}
					}

				}
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=m; i++) {
		cin>>x>>y;
		sum[x]++;
		sum[y]++;
		f[x][sum[x]]=y;
		f[y][sum[y]]=x;
	}
	flag[1]=1;
	dfs(1,0);
	cout<<aans;
	return 0;
}

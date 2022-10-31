#include<bits/stdc++.h>
using namespace std;
int G[2501][2501],n,m,s,ans,cnt,temp[2501];
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>s;
	temp[1]=0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=-1;
	for(int i=2; i<=n; i++)
		cin>>temp[i];
	for(int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		G[x][y]=G[y][x]=0;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(G[k][i]==-1&&G[k][j]!=-1&&G[j][i]!=-1)
					G[k][i]=G[k][j]+G[j][i]+1;
				else if(G[k][i]!=-1&&G[k][j]+G[j][i]+1<G[k][i]&&G[k][j]!=-1&&G[j][i]!=-1)
					G[k][i]=G[k][j]+G[j][i]+1;
	for(int i=1; i<=n; i++) {
		int a=0,b=0,c=0;
		bool flag=false;
		cnt=0;
		if(G[1][i]<=s&&G[1][i]!=-1&&i!=1) {
			cnt+=temp[i];
			a=i;
		} else
			continue;
		for(int j=1; j<=n; j++) {
			if(i!=j&&G[i][j]<=s&&G[i][j]!=-1&&j!=a&&j!=1) {
				cnt+=temp[j];
				b=j;
			} else
				continue;
			for(int k=2; k<=n; k++) {
				if(k!=j&&G[j][k]<=s&&G[j][k]!=-1&&k!=b&&k!=a&&k!=1) {
					cnt+=temp[k];
					c=k;
				} else
					continue;
				for(int x=2; x<=n; x++) {
					if(k!=x&&G[k][x]<=s&&G[k][x]!=-1&&x!=a&&x!=b&&x!=c&&x!=1) {
						cnt+=temp[x];
						ans=max(cnt,ans);
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

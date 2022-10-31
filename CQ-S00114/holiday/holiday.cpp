#include<bits/stdc++.h>
using namespace std;
namespace hyS_namespace{
	int sc[2503],a[2503][2503];
	int main(){
		int n,m,k,ans=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=21474836;
		for(int i=2;i<=n;i++)
			cin>>sc[i];
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		for(int i=2;i<=n;i++){
			if(a[1][i]>k+1)
				continue;
			for(int j=2;j<=n;j++){
				if(a[i][j]>k+1||i==j)
					continue;
				for(int l=2;l<=n;l++){
					if(a[j][l]>k+1||i==l||j==l)
						continue;
					for(int o=2;o<=n;o++){
						if(a[l][o]>k+1||a[o][1]>k+1||o==i||o==j||o==l)
							continue;
						ans=max(ans,sc[i]+sc[j]+sc[l]+sc[o]);
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
}
int main(){
	freopen("holiday.in","rb",stdin);
	freopen("holiday.out","wb",stdout);
	hyS_namespace::main();
	return 0;
}


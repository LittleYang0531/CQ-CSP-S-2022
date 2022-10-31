#include<bits/stdc++.h>
using namespace std;
const int N=310;
int a[N][N];
vector<int> to[N];
long long w[N];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n<=300){
		int m,k;
		scanf("%d%d",&m,&k);
		for(int i=2;i<=n;i++){
			scanf("%lld",&w[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=n+1;
			}
			a[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=1;
			a[y][x]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&a[i][j]<=k+1){
					to[i].push_back(j);
				}
			}
		}
		long long ans=0;
		for(unsigned int l1=0;l1<to[1].size();l1++){
			int p1=to[1][l1];
			for(unsigned int l2=0;l2<to[1].size();l2++){
				int p2=to[1][l2];
				if(p1==p2){
					continue;
				}
				for(unsigned int l3=0;l3<to[p1].size();l3++){
					int p3=to[p1][l3];
					if(p2==p3){
						continue;
					}
					for(unsigned int l4=0;l4<to[p2].size();l4++){
						int p4=to[p2][l4];
						if(p4==p3||p4==p1){
							continue;
						}
						if(a[p3][p4]<=k+1){
							ans=max(ans,w[p1]+w[p2]+w[p3]+w[p4]);
						}
					}
				}
			}
		}
		printf("%lld",ans);
		return 0;
	}
	mt19937 rnd(time(0));
	int m,k;
	scanf("%d%d",&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	int x=rnd()%(n-1)+2,y=rnd()%(n-1)+2,z=rnd()%(n-1)+2,u=rnd()%(n-1)+2;
	while(y==x){
		y=rnd()%(n-1)+2;
	}
	while(z==y||z==x){
		z=rnd()%(n-1)+2;
	}
	while(u==z||u==y||u==x){
		u=rnd()%(n-1)+2;
	}
	printf("%lld",w[x]+w[y]+w[z]+w[u]);
	return 0;
}

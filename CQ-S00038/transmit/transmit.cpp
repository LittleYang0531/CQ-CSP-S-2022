#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
int G[MAXN][MAXN],map1[MAXN][MAXN],n,k,q;
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		for(int j=0; j<n; j++)
			G[i][j]=a;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j)
				map1[i][j]=0;
			else
				map1[i][j]=-1;
	for(int i=1; i<n; i++) {
		int x,y;
		cin>>x>>y;
		map1[x][y]=map1[y][x]=1;
	}
	for(int x=0; x<n; x++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(G[x][j]+G[j][i]<G[x][i]) {
					G[x][i]=G[x][j]+G[j][i];
					map1[x][i]++;
				}
	while(q--) {
		int s,t;
		cin>>s>>t;
		if(map1[s][t]<=k)
			cout<<G[s][t]<<endl;
	}
	return 0;
}

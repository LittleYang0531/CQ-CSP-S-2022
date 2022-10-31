#include<bits/stdc++.h>
using namespace std;
int a[2505],b[2505][2505],n,m,k,s=0;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		b[x][y]=1;
		b[y][x]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
		    for(int k=2;k<=n;k++){
		    	for(int l=2;l<=n;l++){
		    		if(i!=j&&j!=k&&k!=l&&i!=k&&j!=l&&i!=l&&b[i][j]==1&&b[j][k]==1&&b[k][l]==1)s=max(s,a[i]+a[j]+a[k]+a[l]);
				}
			}
	    }
	}
	cout<<s;
	return 0;
}
/*
8 8 1 
9 7 1 8 2 3 6 
1 2 
2 3 
3 4 
4 5 
5 6 
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100001],b[100001],c[10001][10001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);	
	cin >>n >>m >>q;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=1;i<=m;i++) cin >>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	for(register int i=1;i<=q;i++){
		int ans=-1e9,l1,r1,l2,r2;
		scanf("%ld%ld%ld%ld",&l1,&r1,&l2,&r2);
		for(register int j=l1;j<=r1;j++){
			int sum=1e9;
			for(register int k=l2;k<=r2;k++)
				sum=min(sum,c[j][k]);
			ans=max(sum,ans);	
		}
		printf("%ld\n",ans);
	}
	return 0;
}
/*
3 2 2 
0 1 -2 
-3 4 
1 3 1 2 
2 3 2 2 

6 4 5 
3 -1 -2 1 2 0 
1 2 -1 -3 
1 6 1 4 
1 5 1 4 
1 4 1 2 
2 6 3 4 
2 5 2 3 
*/

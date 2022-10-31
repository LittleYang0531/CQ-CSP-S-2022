#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN],b[MAXN];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	while(q--){
		int l,r,l2,r2,maxx=-1e9;
		scanf("%d%d%d%d",&l,&r,&l2,&r2);
		for(int i=l;i<=r;i++){
			int mni=1e9;
			for(int j=l2;j<=r2;j++)mni=min(mni,a[i]*b[j]);
			maxx=max(maxx,mni);
		}
		printf("%d\n",maxx);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2



*/

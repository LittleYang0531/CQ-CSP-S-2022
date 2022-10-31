#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;
const int maxn = 100005;
int n,m,q,l1,l2,r1,r2;
int a[maxn],b[maxn];
long long c[1005][1005],tmp[maxn];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)	scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)	c[i][j]	= a[i] * b[j];
	}
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++){
			tmp[i] = c[i][l2];
			for(int j=l2+1;j<=r2;j++)
				tmp[i] = min(tmp[i],c[i][j]);
		}
		sort(tmp+l1,tmp+r1+1,cmp);
		printf("%lld\n",tmp[l1]);
	}
}

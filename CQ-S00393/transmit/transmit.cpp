#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;
int n,m,k;
int cost[maxn];
int from[maxn],to[maxn];

int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i ++) {
		scanf("%d",&cost[i]);
	}
	for(int i = 1;i <= n - 1;i ++) {
		scanf("%d%d",&from[i],&to[i]);
	}
	for(int i = 1;i <= m;i ++) {
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",cost[x] + cost[y] + cost[y / x]);
	}
	return 0;
}

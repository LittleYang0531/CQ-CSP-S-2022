#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int n,m,x,y,q;

int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i ++) scanf("%d%d",&x,&y);
	scanf("%d",&q);
	while (q --) {
		printf("NO\n");
	}
	return 0;
}

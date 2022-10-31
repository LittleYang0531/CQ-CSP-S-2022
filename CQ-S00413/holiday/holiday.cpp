#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

const int N = 25e2 + 10,M = 1e4 + 10;
long long val[N];
int n,m,k;
long long ans;

int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 2; i <= n; i ++) scanf("%lld",&val[i]);
	sort(val + 2,val + n + 1);
	ans += val[n] + val[n - 1] + val[n - 2] + val[n - 3];
	printf("%lld",ans);
	return 0;
}

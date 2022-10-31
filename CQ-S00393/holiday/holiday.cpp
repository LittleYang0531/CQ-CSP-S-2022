#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int n,m,k;
long long point[maxn];

struct Node {
	int x,id;
	bool friend operator < (Node a,Node b) {
		return a.x < b.x;
	}
} a[maxn];

int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	point[1] = 0;
	for(int i = 2;i <= n;i ++) {
		scanf("%lld",&point[i]);
	}
	for(int i = 1;i <= m;i ++) {
		int f,t;
		scanf("%d%d",&f,&t);
		a[f].x ++;
		a[f].id = f;
	}
	sort(a + 1,a + 1 + n);
	long long answer = 0;
//	for(int i = n;i >= 1;i --) {
//		printf("a[%d].x = %d,a[%d].id = %d\n",i,a[i].x,i,a[i].id);
//	}
	for(int i = n;i >= n - 3;i --) {
		answer += point[a[i].id];
	}
	printf("%lld",answer);
	return 0;
}

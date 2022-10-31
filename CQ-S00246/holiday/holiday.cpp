#include <bits/stdc++.h>
using namespace std;
int n, m, k, s1, s2;
bool graph[2505][2505];
unsigned long long ans;
struct node{
	int order;
	long long score;
}point[2505];
bool cmp(node x1, node x2){
	return x1.score > x2.score;
}
int main(){
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(register int i=1;i<=n-1;++i){
		scanf("%lld", &point[i].score);
		point[i].order = i;
	}
	for(register int i=1;i<=m;++i){
		scanf("%d%d", &s1, &s2);
		graph[s1][s2] = graph[s2][s1] = true;
	}
	sort(point+1, point+1+n, cmp);
	for(register int i=1;i<=4;++i) ans += point[i].score; 
	printf("%lld", ans);
	return 0;
}

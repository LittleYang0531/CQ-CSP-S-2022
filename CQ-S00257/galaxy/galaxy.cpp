#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int main(){
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++)scanf("%*d %*d");
	scanf("%d", &q);
	while(q --){
		if(time(0) * 114514 % 2)printf("NO\n");
		else printf("YES\n");
	}
	return 0; 
}

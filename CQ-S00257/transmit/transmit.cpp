#include<bits/stdc++.h>
using namespace std;
int n, q, k;
int main(){
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	while(q --){
		srand(time(0) * 114514);
		printf("%d\n", rand() % 114514);
	}
	return 0; 
} 

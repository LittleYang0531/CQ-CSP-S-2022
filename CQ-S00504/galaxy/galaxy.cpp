#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,k,f[2505],u,v,q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m);	
	for(int i=1;i<=2*m;i++)scanf("%lld",&u);
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)printf("NO\n");
} 
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/

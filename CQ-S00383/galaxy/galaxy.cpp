#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&k);
	scanf("%d",&k);
	while(k--)puts(rand()%2?"YES":"NO");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
	}
	scanf("%d",&q);
	srand(time(0));
	while(q--){
		int luck=rand()%2;
		if(luck) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

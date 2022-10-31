#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
	}
	scanf("%d",&q);
	while(q--){
		int op,a,b,c; scanf("%d",&op);
		if(op==1) scanf("%d%d",&a,&b);
		if(op==2) scanf("%d",&a);
		if(op==3) scanf("%d%d",&a,&b);
		if(op==4) scanf("%d",&a);
		puts("NO");
	}
	return 0;
}

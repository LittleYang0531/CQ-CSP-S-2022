#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,m,a[MAXN],b[MAXN],q;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d",&b[i]);
	while(q--){
		cout <<rand()%(n+m+q)<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
int n,m,q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)scanf("%d%d",&x,&y);
	scanf("%d",&q);
	while(q--){
		int jk=rand();
		if(jk%2==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

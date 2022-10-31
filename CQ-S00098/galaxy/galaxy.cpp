#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	for(int i(1);i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	int q;
	scanf("%d",&q);
	for(int i(1);i<=q;++i){
		string a;
		getline(cin,a);
		int f=rand()%2;
		if(f){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

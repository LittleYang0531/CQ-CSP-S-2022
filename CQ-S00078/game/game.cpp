#include<bits/stdc++.h>
using namespace std;
long long a[10010],b[10010],ans_1,ans_2,num[10010][10010];
int n,m,q;
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			num[i][j] = a[i] * b[j];
		}
	}
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ans_1 = LLONG_MIN,ans_2 = LLONG_MAX;
		for(int i = l1;i<=r1;i++){
			for(int j = l2;j<=r2;j++){
				ans_2 = min(ans_2,num[i][j]);
			}
			ans_1 = max(ans_1,ans_2);
			ans_2 = LLONG_MAX;
		}
		printf("%lld\n",ans_1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

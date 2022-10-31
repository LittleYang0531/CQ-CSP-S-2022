#include<cstdio>
using namespace std;
long long n,m,q,arr[10005][10005],a[10005],b[10005],x1,x2,y1,y2,mi[10005],mx;
long long min(long long a,long long b){
	return a < b ? a : b;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&q);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			arr[i][j] = a[i]*b[j];
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		mx = x1;
		for(int j = x1;j <= y1;j++){
			mi[j] = 1000000000000000005;
			for(int k = x2;k <= y2;k++){
				mi[j] = min(mi[j],arr[j][k]);
			}
			if(mi[mx] < mi[j])mx = j;
		}
		printf("%lld\n",mi[mx]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

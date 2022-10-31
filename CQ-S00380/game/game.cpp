#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128
int n,m,q;
int a[1005],b[1005];
i128 c[1005][1005];
const i128 zero=48;
//啊嘿嘿嘿，懒得写高精度，int128完全够了
//完全看机子速度了啊喂 
//估计60pts 
void print(i128 N){
	string S="";
	if(N<0)putchar('-'),N=-N;
	if(N==0){
		putchar('0');
		putchar('\n');
		return;
	}
	while(N){
		int x=N%10+zero;
		S+=char(x);
		N/=10;
	}
	for(int i=S.length()-1;i>=0;i--){
		putchar(S[i]);
	}
	putchar('\n');
}
signed main(){
	#ifndef LOCAL
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
	for(int i=1;i<=q;i++){
		int l1,l2,r1,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		int posL,posQ;
		i128 MaxInMin=-1e20,MinInMax=1e20;
		for(int j=l1;j<=r1;j++){
			i128 tt=1e20;
			for(int k=l2;k<=r2;k++){
				tt=min(tt,c[j][k]);
			}
			if(tt>MaxInMin){
				posL=j;
				MaxInMin=tt;
			}
		}
		for(int j=l2;j<=r2;j++){
			if(c[posL][j]<MinInMax){
				posQ=j;
				MinInMax=c[posL][j];
			}
		}
		print(c[posL][posQ]);
	}
	return 0;
}

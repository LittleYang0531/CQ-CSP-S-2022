#include<bits/stdc++.h>
#define fma qqwqq
#define fma2 wqeq
#define fmi2 safdn
#define fmi dfjsak
using namespace std;
int n,m,a[100001],b[100001],q;
int fma[100001][20],fmi[100001][20],fmi2[100001][20],fma2[100001][20];
void ST(){
	for(int i=1;i<=n;++i)fma[i][0]=fmi2[i][0]=a[i];
	for(int i=1;i<=m;++i)fmi[i][0]=fma2[i][0]=b[i];
	for(int j=1;j<=log2(n);++j){
		for(int i=1;i+(1<<j)+1<=n;++i){
			fma[i][j]=max(fma[i][j-1],fma[i+(1<<j-1)][j-1]);
//			fmi2[i][j]=min(fmi2[i][j-1],fmi2[i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;j<=log2(m);++j){
		for(int i=1;i+(1<<j)+1<=m;++i){
			fmi[i][j]=min(fmi[i][j-1],fmi[i+(1<<j-1)][j-1]);
//			fma2[i][j]=max(fma2[i][j-1],fma2[i+(1<<j-2)][j-1]);
		}
	}
}
void ST2(){
	for(int j=1;j<=log2(n);++j){
		for(int i=1;i+(1<<j)+1<=n;++i){
//			fma[i][j]=max(fma[i][j-1],fma[i+(1<<j-1)][j-1]);
			fmi2[i][j]=min(fmi2[i][j-1],fmi2[i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;j<=log2(m);++j){
		for(int i=1;i+(1<<j)+1<=m;++i){
//			fmi[i][j]=min(fmi[i][j-1],fmi[i+(1<<j-1)][j-1]);
			fma2[i][j]=max(fma2[i][j-1],fma2[i+(1<<j-1)][j-1]);
		}
	}
}
int ask1(int l,int r){
	if(l>r)swap(l,r);
	int m=log2(r-l+1);
	return max(fma[l][m],fma[r-(1<<m)+1][m]);
}
int ask2(int l,int r){
	if(l>r)swap(l,r);
	int m=log2(r-l+1);
	return min(fmi[l][m],fmi[r-(1<<m)+1][m]);
}
int ask3(int l,int r){//A中最小 
	if(l>r)swap(l,r);
	int m=log2(r-l+1);
	return min(fmi2[l][m],fmi2[r-(1<<m)+1][m]);
}
int ask4(int l,int r){//B中最大 
	if(l>r)swap(l,r);
	int m=log2(r-l+1);
	return max(fma2[l][m],fma2[r-(1<<m)+1][m]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int flag1=1,flag2=1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]<0)flag1=0;
	}
	for(int i=1;i<=m;++i){
		scanf("%d",b+i);
		if(b[i]<0)flag1=0;
	}
	if(flag1){
		ST();
		while(q--){
			int l1,l2,r1,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			printf("%lld\n",ask1(l1,r1)*1ll*ask2(l2,r2));
		}
		return 0;
	}
	ST();
	ST2();
	while(q--){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[l1]<0){
				printf("%lld\n",a[l1]*1ll*ask4(l2,r2));
			}
			if(a[l1]==0){
				printf("0\n");
			}
			if(a[l1]>0){
				printf("%lld\n",a[l1]*1ll*ask2(l2,r2));
			}
		}
		else{
			if(b[l2]<0){
				printf("%lld\n",b[l2]*1ll*ask3(l1,r1));
			}
			if(b[l2]==0){
				printf("0\n");
			}
			if(b[l2]>0){
				printf("%lld\n",b[l2]*1ll*ask1(l1,r1));
			}
		}
	}
	return 0;
}
/*
10 10 3
4 1 -5 22 -1 42 -17 8 6 -13
-4 5 10 2 -7 -16 32 1 8 10
1 4 5 5
2 5 2 2
3 3 6 7

35
210
-160
*/

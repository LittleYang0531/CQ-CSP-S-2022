#include<bits/stdc++.h>
#define N 100005
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,q,a[N],b[N],flag=1,st1[N][19],st2[N][19],bin[30];
int getmax(int l,int r){
	int k=log2(r-l+1);
	return max(st1[l][k],st1[r-bin[k]+1][k]);
}
int getmin(int l,int r){
	int k=log2(r-l+1);
	return min(st2[l][k],st2[r-bin[k]+1][k]);
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	bin[0]=1;
	for(int i=1;i<=19;i++)bin[i]=bin[i-1]<<1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		st1[i][0]=a[i];
		if(a[i]<0)flag=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		st2[i][0]=b[i];
		if(b[i]<0)flag=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=19&&i+bin[j-1]-1<n;j++){
			st1[i][j]=max(st1[i][j-1],st1[i+bin[j-1]-1][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=19&&i+bin[j-1]-1<m;j++){
			st2[i][j]=max(st2[i][j-1],st2[i+bin[j-1]-1][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1){
			int mn=INF;
			for(int j=l2;j<=r2;j++){
				if(a[l1]*b[j]<mn){
					mn=a[l1]*b[j];
				}
			}
			printf("%lld\n",mn);
		}else if(l2==r2){
			int mx=-INF;
			for(int j=l1;j<=r1;j++){
				if(a[j]*b[l2]>mx){
					mx=a[j]*b[l2];
				}
			}
			printf("%lld\n",mx);
		}else if(flag==1){
			printf("%lld\n",getmax(l1,r1)*getmin(l2,r2));
		}else{
			printf("0\n");
		}
	}
	return 0;
}

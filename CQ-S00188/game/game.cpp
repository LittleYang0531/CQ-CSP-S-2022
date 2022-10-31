#include<bits/stdc++.h>
using namespace std;
int n,m,q,ls[1005][3],rs[1005][3],ns[1005],ms[1005],a1,a2;
int mina[605][605][605],minas,maxns;
int Max(int a,int b){
	return a>b?a:b;
}
int Min(int a,int b){
	return a<b?a:b;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int j = 1;j <= n;j++)
		scanf("%d",&ns[j]);
	for(int j = 1;j <= m;j++)
		scanf("%d",&ms[j]);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			mina[i][j][j] = ns[i]*ms[j];
	for(int i = 1;i <= q;i++)
		scanf("%d%d%d%d",&ls[i][1],&rs[i][1],&ls[i][2],&rs[i][2]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			for(int k = j+1;k <= m;k++)
				mina[i][j][k] = Min(ns[i]*ms[k],mina[i][j][k-1]);
	}
	for(int i = 1;i <= q;i++){
		minas = mina[ls[i][1]][ls[i][2]][rs[i][2]];
		for(int j = ls[i][1]+1;j <= rs[i][1];j++){
			minas = Max(minas,mina[j][ls[i][2]][rs[i][2]]);
		}	
	}
	for(int i = 1;i <= q;i++){
		minas = mina[ls[i][1]][ls[i][2]][rs[i][2]];
		a1 = ls[i][1];
		a2 = ls[i][2];
		for(int j = ls[i][1]+1;j <= rs[i][1];j++){
			if(mina[j][ls[i][2]][rs[i][2]] > minas){
				minas = mina[j][ls[i][2]][rs[i][2]];
				a1 = j;
			}
		}
		maxns = ms[ls[i][2]]*ns[a1];
		for(int j = ls[i][2]+1;j <= rs[i][2];j++){
			if(ms[j]*ns[a1] < maxns){
				maxns = ms[j]*ns[a1];
				a2 = j;
			}
		}
		printf("%d\n",ns[a1]*ms[a2]);	
	}
	return 0;
} 

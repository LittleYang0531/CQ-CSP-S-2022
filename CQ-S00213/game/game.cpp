#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxNM=100000;
int n,m,q;
int a[MaxNM+10],b[MaxNM+10];
void Read(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
}
/*
小L的目标:最小值最大
小Q的目标:最大值最小
*/
int c[1000+1][1000+1];
//int minA[1000+1];
//int maxB[1000+1];
void Solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
//cout<<c[i][j]<<' ';
		}
//cout<<'\n';
	}
//	for(int i=1;i<=n;i++){
//		minA[i]=LLONG_MAX;
//		for(int j=1;j<=m;j++){
//			minA[i]=min(minA[i],c[i][j]);
//		}
//	}
//	for(int j=1;j<=m;j++){
//		maxB[j]=LLONG_MIN;
//		for(int i=1;i<=n;i++){
//			maxB[j]=max(maxB[j],c[i][j]);
//		}
//	}
	for(int que=1;que<=q;que++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		int mmax=LLONG_MIN,mmin=LLONG_MAX;
		int ch1=0,ch2=0;
		for(int i=l1;i<=r1;i++){
			int minA=LLONG_MAX;
			for(int j=l2;j<=r2;j++)minA=min(minA,c[i][j]);
			if(minA>mmax){
				mmax=minA;
				ch1=i;
			}
		}
		for(int i=l2;i<=r2;i++){
			int maxB=LLONG_MIN;
			for(int j=l1;j<=r1;j++)maxB=max(maxB,c[j][i]);
			if(maxB<mmin){
				mmin=maxB;
				ch2=i;
			}
		}
		cout<<c[ch1][ch2]<<'\n';
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	int T;
//	cin>>T;
//	while(T--){
		Read();
		Solve();
//	}
	return 0;
}


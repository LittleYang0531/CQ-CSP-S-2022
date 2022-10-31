#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int N,M,Q;
int a[MAXN],b[MAXN];
int azf(int l,int r) {
	int s=0;
	for(int i=l; i<=r; i++) {if(a[i]>0&&s%10==0) s+=1;if(a[i]<0&&(s/10)%10==0) s+=10;if(a[i]==0&&s/100==0) s+=100;}
	int ans=0;
	ans=(s/100)*4+(s%10)+((s/10)%10)*2;
	return ans;
}
int bzf(int l,int r) {
	int s=0;
	for(int i=l; i<=r; i++) {if(b[i]>0&&s%10==0) s+=1;if(b[i]<0&&(s/10)%10==0) s+=10;if(b[i]==0&&s/100==0) s+=100;}
	int ans=0;
	ans=(s/100)*4+(s%10)+((s/10)%10)*2;
	return ans;
}
int pd(int x,int y) {
	if(x==4||y==4) return 0;
	if(x==1) {if(y==1) return 1;else if(y==4||y==5) return 0;else return 2;}
	if(x==2) {if(y==2) return 1;else if(y==4||y==6) return 0;else return 2;}
	if(x==3) {if(y==1||y==2) return 1;else if(y==3||y==7) return 2;else return 0;}
	if(x==5) {if(y==1) return 1;else return 0;}
	if(x==6) {if(y==2) return 1;else return 0;}
	if(x==7) {if(y==1||y==2) return 1;else return 0;}}
void dx(int l1,int r1,int l2,int r2) {
	int mx=0,mi=1e9;
	for(int i=l1; i<=r1; i++)mx=max(mx,abs(a[i]));
	for(int i=l2; i<=r2; i++)mi=min(mi,abs(b[i]));

	cout<<mx*mi<<endl;
}
void dx1(int l1,int r1,int l2,int r2) {
	int mx=0,mi=1e9;
	for(int i=l1; i<=r1; i++)mi=min(mx,abs(a[i]));
	for(int i=l2; i<=r2; i++)mx=max(mi,abs(b[i]));

	cout<<(0-mi*mx)<<endl;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>N>>M>>Q;
	for(int i=1; i<=N; i++) cin>>a[i];
	for(int j=1; j<=M; j++) cin>>b[j];
	int l1,l2,r1,r2;
	for(int i=1; i<=Q; i++) {
		cin>>l1>>r1>>l2>>r2;
		int xa,xb,ya,yb;
		xa=azf(l1,r1);
		xb=bzf(l2,r2);
		int t=pd(xa,xb);
		if(t==0) cout<<0<<endl;
		else if(t==1) dx(l1,r1,l2,r2);
		else dx1(l1,r1,l2,r2);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2


6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/


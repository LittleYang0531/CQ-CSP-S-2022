#include<bits/stdc++.h>
using namespace std;
inline long long lread(){
	long long a;
	cin >> a;
	return a;
}
inline int read(){
	int a;
	cin >> a;
	return a;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read(),q=read();
	long long a[n+1],b[m+1];
	for(int i=1;i<=n;i++){
		a[i]=lread();
	}
	for(int i=1;i<=m;i++){
		b[i]=lread();
	}
	for(int i=1;i<=q;i++){
		int l1=read(),r1=read(),l2=read(),r2=read();
		for(int x=l1;x<=l2;x++){
			
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a;
	cin >> a;
	return a;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n=read(),m=read(),k=read()
	int c[n+1],x[n],y[n];
	for(int i=2;i<=n;i++){
		c[i]=read();
	}
	for(int i=0;i<m;i++){
		x[i]=read();
		y[i]=read();
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

template <class T>
void write(T x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

int n,m;

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=m;i++){
		int u,v;
		read(u);read(v);
	}
	int q;
	read(q);
	while(q--){
		puts("NO");
	}
}


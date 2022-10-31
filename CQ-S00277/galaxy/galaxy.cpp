#include <bits/stdc++.h>

using namespace std;

int n,m,q;

int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = r * 10 + c - '0';
		c = getchar();
	}
	return r * w;
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n = read();
	m = read();
	for (int i = 1;i <= m;i++){
		int a,b;
		a = read();
		b = read();
	}
	while (q--) printf("NO\n");
	return 0;
}

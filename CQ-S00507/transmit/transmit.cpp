#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, k, a[200010], b, c;

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++ ){
		scanf("%d", &a[i]);
	}
	n -- ;
	while(n -- ){
		scanf("%d%d", &b, &c);
	}
	while(m -- ){
		scanf("%d%d", &b, &c);
		cout << a[b] + a[c] << endl;
	}
	return 0;
}


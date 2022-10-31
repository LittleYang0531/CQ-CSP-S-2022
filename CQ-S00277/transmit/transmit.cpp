#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 4e5 + 10,INF = 1e18 + 10;
int n,q,k,idx,x,y,ans;
int ne[N],e[N],h[N],arr[N];

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

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u,int fa,int res,int w){
	if (u == x) w += arr[u];
	if (u == y) w += arr[u]; 
	if (res >= k) return;
	if (u == y){
		ans = min(ans,w);
		return;
	}
	for (int i = h[u];~i;i = ne[i]){
		int j = e[i];
		if (j != fa){
			dfs(j,u,res + 1,w);
			dfs(j,u,0,w + arr[u]);
		}
	}
}

void dfs1(int u,int fa,int w){
	if (u == y){
		ans = min(ans,w);
		return;
	}
	for (int i = h[u];~i;i = ne[i]){
		int j = e[i];
		if (j != fa){
			dfs1(j,u,w + arr[j]);
		}
	}
}

signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(h,-1,sizeof(h));
	n = read();
	q = read();
	k = read();
	for (int i = 1;i <= n;i++) arr[i] = read();
	for (int i = 1;i < n;i++){
		int a,b;
		a = read();
		b = read();
		add(a,b);
		add(b,a);
	}
	while (q--){
		x = read();
		y = read();
		ans = INF;
		if (k == 1) dfs1(x,-1,0),printf("%lld\n",ans + arr[x]);
		else{
			dfs(x,-1,0,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

/*
4 2 1
1 2 3 4
1 2
1 3
4 2
1 3
4 3
*/

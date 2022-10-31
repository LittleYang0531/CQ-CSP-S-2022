#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int qwe=2*1e5+4;
struct node{
	int to,net;
}e[qwe<<1];int h[qwe],cnt;
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].net=h[x];
	h[x]=cnt;
}
int n,q,k,a[qwe];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int x,y;
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",a[x]+a[y]);
	}
	return 0;
}

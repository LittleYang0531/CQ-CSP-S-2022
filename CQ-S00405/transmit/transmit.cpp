#include<bits/stdc++.h>
#define MAXN 100010
#define R register
using namespace std;
inline int read(){
	int x=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){	if(ch=='-') w=-1;	ch=getchar();	}
	while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+ch-'0'; ch=getchar(); }
	return x*w;
}
int n,m,k,a[MAXN*2],p[MAXN*2],x,y;
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&x,&y),p[x]++,p[y]++;
	while(m--){
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%lld\n",1ll*(p[s]+1)*(p[t]+1));
	}
	return 0;
}

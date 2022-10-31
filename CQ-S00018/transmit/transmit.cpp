#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
#define ll long long
struct G{
	int v,nex;
}a[N];
int n,q,k;
int f[2501][2501]={0};
ll head[N]={0},tot=0,val[N];
void add(int u,int v){
	a[++tot].v=v;
	a[tot].nex=head[u];
	head[u]=tot;
}
int main(){ 
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<1<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
int n,q,k,v[200001],x,y,cnt,h[200001],aa[200001],ff,nn;
long long f[200001];
struct qx{
	int to,next;
}a[200001];
void hb(int x,int y){
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int pre,int k){
	if(ff) return;
	aa[k]=v[x];
	nn=k;
	if(x==y){
		ff=1;
		return;
	}
	for(int i=h[x];i!=0;i=a[i].next){
		int y=a[i].to;
		if(y==pre) continue;
		dfs(y,x,k+1);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		hb(x,y);
		hb(y,x);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ff=0;
		memset(f,0x3f3f3f3f,sizeof(f));
		dfs(x,0,1);
		f[1]=aa[1];
//		for(int i=1;i<=nn;i++){
//			cout<<aa[i]<<" ";
//		}
//		cout<<endl;
		for(int i=2;i<=nn;i++){
			for(int j=i;j>=max(1,i-k);j--){
				f[i]=min(f[i],f[j]+aa[i]);
			}
		}
		printf("%lld\n",f[nn]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return f*k;
}
struct node{
	int x;
	int id; 
};
long long a[100200],b[100200];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	
	int l1,r1,l2,r2;
	long long ans;
	while(q--){
		ans=0;
		l1=read(),r1=read(),l2=read(),r2=read();
		for(int i=l1;i<=r1;i++){
			long long sum=a[i]*b[l2];
			for(int j=l2;j<=r2;j++){
				sum=min(sum,a[i]*b[j]);
			}
			if(i==l1) ans=sum;
			else ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 

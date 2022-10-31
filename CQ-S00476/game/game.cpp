#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(__int128 x){
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
int n,m,q,lg[1001];
long long a[1010],b[1010],st[1001][1001][12];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=2;i<=m;i++) lg[i]=lg[i/2]+1;
	for(int w=1;w<=n;w++){
		for(int i=1;i<=m;i++) st[w][i][0]=a[w]*b[i];
		for(int k=1;k<=lg[m];k++){
			for(int i=1;i+(1<<(k-1))<=m;i++){
				st[w][i][k]=min(st[w][i][k-1],st[w][i+(1<<(k-1))][k-1]);
			}
		}
	}
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		__int128 ans=-1e19;
		for(int i=l1;i<=r1;i++){
			int k=lg[r2-l2+1];
			ans=max(ans,(__int128)min(st[i][l2][k],st[i][r2-(1<<k)+1][k]));
		}
		if(ans<0){
			putchar('-');
			ans=-ans;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

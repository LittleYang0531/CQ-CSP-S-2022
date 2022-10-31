#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void read(long long &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1ll)+(x<<3ll)+(c^48ll);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
inline void write(long long x){
	if(x<0ll){
		putchar('-');
		x=-x;
	}
	if(x>9ll) write(x/10ll);
	putchar(x%10ll+48);
}
long long a[100005],b[100005];
int lg[1005];
long long MIN[1005][1005][13];
int ljj[100005];
long long TAD[100005][19],PYB[100005][19];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(b[i]);
	if(n>1000 || m>1000){
		for(int i=1;i<=n;i++){
			TAD[i][0]=a[i];
		}
		for(int i=1;i<=m;i++){
			PYB[i][0]=b[i];
		}
		for(int k=1;k<=17;k++){
			for(int i=1;i<=n;i++){
				if(i+(1<<k)-1<=n){
					TAD[i][k]=max(TAD[i][k-1],TAD[i+(1<<(k-1))][k-1]);
				}
			}
			for(int i=1;i<=m;i++){
				if(i+(1<<k)-1<=m){
					PYB[i][k]=min(PYB[i][k-1],PYB[i+(1<<(k-1))][k-1]);
				}
			}
		}
		for(int i=2;i<=max(n,m);i++) ljj[i]=ljj[i>>1]+1; 
		while(q--){
			int l1,l2,r1,r2;
			read(l1),read(r1),read(l2),read(r2);
			int k1=ljj[r1-l1+1],k2=ljj[r2-l2+1];
			int sum1=1<<k1,sum2=1<<k2;
			write(max(TAD[l1][k1],TAD[r1-sum1+1][k1])*min(PYB[l2][k2],PYB[r2-sum2+1][k2]));
			putchar('\n');
		}
		return 0;
	}
	lg[1]=0;
	for(int i=2;i<=m;i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			MIN[i][j][0]=a[i]*b[j];
		}
		for(int k=1;k<=10;k++){
			for(int j=1;j<=m;j++){
				if(j+(1<<k)-1<=m){
					MIN[i][j][k]=min(MIN[i][j][k-1],MIN[i][j+(1<<(k-1))][k-1]);
				}
			}
		}
	}
	while(q--){
		int l1,l2,r1,r2;
		read(l1),read(r1),read(l2),read(r2);
		long long ans=0xcfcfcfcfcfcfcfcf;
		for(int i=l1;i<=r1;i++){
			int sum=(1<<lg[r2-l2+1]);
			int k=lg[r2-l2+1];
			ans=max(ans,min(MIN[i][l2][k],MIN[i][r2-sum+1][k]));
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,q,l1,r1,l2,r2,flag=1;
ll a[N],b[N],st1[N][40],st2[N][40],s1[N][40],s2[N][40];//min max

int rd(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}

void init(){
	for(int i=1;i<=n;i++) st1[i][0]=s1[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st1[i][j]=min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			s1[i][j]=max(s1[i][j-1],s1[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++) st2[i][0]=s2[i][0]=b[i];
	for(int j=1;(1<<j)<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
			s2[i][j]=max(s2[i][j-1],s2[i+(1<<(j-1))][j-1]);
		}
	}
}

ll RMQm1(int x,int y){
	int p=(int)log2((double)y-x+1);
	return min(st1[x][p],st1[y-(1<<p)+1][p]);
}

ll RMQm2(int x,int y){
	int p=(int)log2((double)y-x+1);
	return min(st2[x][p],st2[y-(1<<p)+1][p]);
}

ll RMQx1(int x,int y){
	int p=(int)log2((double)y-x+1);
	return max(s1[x][p],s1[y-(1<<p)+1][p]);
}

ll RMQx2(int x,int y){
	int p=(int)log2((double)y-x+1);
	return max(s2[x][p],s2[y-(1<<p)+1][p]);
}

void solve(){
	for(int i=1;i<=q;i++){
		l1=rd();r1=rd();l2=rd();r2=rd();
		if(l1==r1){
			if(a[l1]==0) printf("0\n");
			else{
				if(a[l1]<0) printf("%lld\n",a[l1]*RMQx2(l2,r2));
				else printf("%lld\n",a[l1]*RMQm2(l2,r2));
			}
		}else{
			if(l2==r2){
				if(b[l2]==0) printf("0\n");
				else{
					if(b[l2]<0) printf("%lld\n",b[l2]*RMQm1(l1,r1));
					else printf("%lld\n",b[l2]*RMQx1(l1,r1));
				}
			}
		}
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=rd();m=rd();q=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(a[i]<=0) flag=0;
	}
	for(int i=1;i<=m;i++){
		b[i]=rd();
		if(b[i]<=0) flag=0;
	} 
	init();
	if(flag){
		for(int i=1;i<=q;i++){
			l1=rd();r1=rd();l2=rd();r2=rd();
			printf("%lld\n",RMQm1(l1,r1)*RMQm2(l2,r2));
		}
		return 0;
	}
	solve();
	return 0;
}

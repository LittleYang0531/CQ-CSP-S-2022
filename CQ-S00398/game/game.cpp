#include<bits/stdc++.h>
using namespace std;
const int MAXN=100110;
const long long INF=1e14;
char c;
inline long long read(){
	long long ans=0;
	bool f=0;
	while('0'>c||c>'9'){
		f=(c=='-');
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*(f?-1:1);
}
int lg[MAXN];
long long st[MAXN][30][10];
void _bld(int k,int n){
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[j][i][k]=max(st[j][i-1][k],st[j+(1<<(i-1))][i-1][k]);
}
long long _ask(int k,int l,int  r){
	return max(st[l][lg[r-l+1]][k],st[r-(1<<(lg[r-l+1]))+1][lg[r-l+1]][k]);
}
int main(){
	cin.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=2;i<=max(n,m);i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		long long a=read();
		st[i][0][0]=a;//最大值 
		st[i][0][1]=(a>=0?-a:-INF);//最小正数值 
		st[i][0][2]=-a;//小值
		st[i][0][3]=(a<=0?a:-INF);//最大负数值 
	}
	for(int i=1;i<=m;i++){
		long long a=read();
		st[i][0][4]=a;
		st[i][0][5]=(a>=0?-a:-INF);
		st[i][0][6]=-a;
		st[i][0][7]=(a<=0?a:-INF);
	}
	for(int i=0;i<4;i++)_bld(i,n);
	for(int i=4;i<8;i++)_bld(i,m);	
	int l1,l2,r1,r2;
	for(int i=0;i<q;i++){
		l1=read(),r1=read(),l2=read(),r2=read();
		long long a,b;
		if(-_ask(6,l2,r2)>0)a=_ask(0,l1,r1);
		else if(_ask(4,l2,r2)<0)a=-_ask(2,l1,r1);
		else if(-_ask(1,l1,r1)>_ask(3,l1,r1)){
			a=-_ask(1,l1,r1);
		}else if(-_ask(1,l1,r1)<_ask(3,l1,r1)){
			a=_ask(3,l1,r1);
		}else if(-_ask(5,l2,r2)<_ask(7,l2,r2)){
			a=_ask(3,l1,r1);
		}else{
			a=-_ask(1,l1,r1);
		}
		if(a>0)
			b=-_ask(6,l2,r2);
		else
			b=_ask(4,l2,r2);
		cout<<a*b<<endl;
	}
	return 0;
}


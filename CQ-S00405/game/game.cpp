#include<bits/stdc++.h>
#define MAXN 100010
#define R register
using namespace std;
int lg[MAXN],st1[MAXN][18],st2[MAXN][18],st3[MAXN][18],st4[MAXN][18],st5[MAXN][18],st6[MAXN][18];
int n,m,q,a[MAXN],b[MAXN];
inline int read(){
	int x=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){	if(ch=='-') w=-1;	ch=getchar();	}
	while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+ch-'0'; ch=getchar(); }
	return x*w;
}
inline void init(){
	for(int i=2;i<=100000;i++) lg[i]=lg[(i>>1)]+1;
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		 st1[j][i]=max(st1[j+(1<<i-1)-1][i-1],st1[j+1][i-1]);
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		 st2[j][i]=min(st2[j+(1<<i-1)-1][i-1],st2[j+1][i-1]);
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
		 st3[j][i]=max(st3[j+(1<<i-1)-1][i-1],st3[j+1][i-1]);
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
		 st4[j][i]=min(st4[j+(1<<i-1)-1][i-1],st4[j+1][i-1]);
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		 st5[j][i]=max(st5[j+(1<<i-1)-1][i-1],st5[j+1][i-1]);
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		 st6[j][i]=min(st6[j+(1<<i-1)-1][i-1],st6[j+1][i-1]);
}
int Q1(int x,int y){
	int s=lg[y-x+1];
	return max(st1[y-(1<<s)+1][s],st1[x][s]);
}
int Q2(int x,int y){
	int s=lg[y-x+1];
	return min(st2[y-(1<<s)+1][s],st2[x][s]);
}
int Q3(int x,int y){
	int s=lg[y-x+1];
	return max(st3[y-(1<<s)+1][s],st3[x][s]);
}
int Q4(int x,int y){
	int s=lg[y-x+1];
	return min(st4[y-(1<<s)+1][s],st4[x][s]);
}
int Q5(int x,int y){
	int s=lg[y-x+1];
	return max(st5[y-(1<<s)+1][s],st5[x][s]);
}
int Q6(int x,int y){
	int s=lg[y-x+1];
	return min(st6[y-(1<<s)+1][s],st6[x][s]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),st1[i][0]=a[i],st2[i][0]=a[i],st5[i][0]=(a[i]==0),st6[i][0]=abs(a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),st3[i][0]=b[i],st4[i][0]=b[i];
	init();
	long long ans=0;
	int q1,q2,q3,q4,q5,q6;
	for(int i=1,x,y,l,r;i<=q;i++) {
		scanf("%d%d%d%d",&x,&y,&l,&r);
		q1=Q1(x,y),q2=Q2(x,y),q3=Q3(l,r),q4=Q4(l,r),q5=Q5(x,y),q6=Q6(l,r);
		if(q4<0){
			if(q3<=0){
				ans=1ll*q2*q3;
			}else{
				if(q5){
					ans=0;
				}else{
					ans=1ll*q6*q3;
					ans=(ans>0?0-ans:ans);
				}
			}
		}else{
			ans=q1*q4;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/

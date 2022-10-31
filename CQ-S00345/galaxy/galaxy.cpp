#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=5e5+9;
//char buf[(1<<21)+1],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m;
struct edge{
	int pre,to;
}e[N];int last[N],cnt;
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
struct node{int op,x,y;}Q[N];
mt19937 R(147744151);
int op[N],sum[N][2],now[N][2];
int all[2],ts[2],q;
int ans[N];
void work(){
	ts[0]=ts[1]=0;all[0]=all[1]=0;
	rep(i,n)ts[op[i]=R()&1]++;
	rep(x,n){
		sum[x][0]=sum[x][1]=0;
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;
			sum[x][op[to]]++;
		}
		now[x][0]=sum[x][0];
		now[x][1]=sum[x][1];
		all[0]+=sum[x][0];
		all[1]+=sum[x][1];
	}
	int x,y;
	rep(k,q){
		x=Q[k].x,y=Q[k].y;
		switch(Q[k].op){
			case 1:{
				now[y][op[x]]--;
				all[op[x]]--;
				break;
			}
			case 2:{
				all[0]-=now[x][0];
				all[1]-=now[x][1];
				now[x][0]=now[x][1]=0;
				break;
			}
			case 3:{
				now[y][op[x]]++;
				all[op[x]]++;
				break;
			}
			case 4:{
				all[0]+=sum[x][0]-now[x][0];
				all[1]+=sum[x][1]-now[x][1];
				now[x][0]=sum[x][0];
				now[x][1]=sum[x][1];
				break;
			}
		}
		if(all[0]!=ts[0]||all[1]!=ts[1])ans[k]=0;
	}
}
int main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc galaxy.out galaxy4.ans");return 0;
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	rep(i,m){
		int x=read(),y=read();
		add(y,x);
	}q=read();
	rep(i,q){ans[i]=1;
		Q[i].op=read();
		Q[i].x=read();
		if(Q[i].op&1)Q[i].y=read();
	}
	rep(i,30)work();
	rep(i,q)puts(ans[i]?"YES":"NO");
	return 0;
}



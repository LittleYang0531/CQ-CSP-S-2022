#include<bits/stdc++.h>
using namespace std;
int m,n,q;
int a[100001],b[100001];
int fa[100001][21],fb[100001][21];
int read(){
	int w=0,f=1;
	char c=getchar();
	while(!isalnum(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isalnum(c)){
		w*=10;
		w+=c-'0';
		c=getchar();
	}
	return w*f;
}
int fmax(int l,int r){
	int k=log2(r-l+1);
	return max(fa[l][k-1],fa[l+(1<<k)-1][k-1]);
}
int fmin(int l,int r){
	int k=log2(r-l+1);
	return min(fb[l][k-1],fb[l+(1<<k)-1][k-1]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	m=read();
	q=read();
	memset(fb,0xfffffff,sizeof(fb));
	for(int i=1;i<=n;i++){
		a[i]=read();
		fa[i][0]=a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		fb[i][0]=b[i];
	}
	//cout<<endl;
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<j)-1][j-1]);
		}
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			fb[i][j]=min(fb[i][j-1],fb[i+(1<<j)-1][j-1]);		
		}
	}
	while(q--){
		int l1,r1,l2,r2;
		int x,y;
		l1=read();
		r1=read();
		l2=read();
		r2=read();
		if(l1==r1){
			x=a[l1];
			y=fmin(l2,r2);
		}else if(l2==r2){
			x=fmax(l1,r1);
			y=b[l2];
		}else{
			x=fmax(l1,r1);
			y=fmin(l2,r2);
		}
		int ans=x*y;
		//cout<<x<<" "<<y<<endl;
		printf("%d",ans);
		putchar('\n');
	}
	return 0;
}
/*
6 7 2
-1 -3 1 5 2 4
-5 2 3 6 1 4 2 
4 4 2 5
5 5 4 6

5
2
*/


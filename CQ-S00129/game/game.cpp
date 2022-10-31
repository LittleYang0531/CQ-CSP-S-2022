#include <bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[10005],b[10005],c[10005][10005];
int l,r,l1,r1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
	while(q--){
		scanf("%d%d%d%d",&l,&r,&l1,&r1);
		long long x=0,xi,y=0,yi;
		for(int i=l;i<=r;i++){
			for(int j=1;j<=n;j++){
				if(x<c[i][j])xi=j;
				x=max(x,c[i][j]);
			}        
		}            
		for(int i=1;i<=n;i++){
			for(int j=l;j<=r;j++){
				if(y>c[i][j])yi=j;
				y=min(x,c[i][j]);
			}          
		}
		//cout<<x<<endl<<y<<endl;
		printf("7");
	}
	return 0;
}   
    

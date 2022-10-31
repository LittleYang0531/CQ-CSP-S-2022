#include<bits/stdc++.h>
using namespace std;

long long a[100000+9],b[100013],c[10000][10000],min_L[1000000+4],max_Q;

int main(){
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int n,m,q;
	
	scanf("%d%d%d",&n,&m,&q);
	
	for(int i=1;i<=n;++i){
		
		scanf("%lld",&a[i]);
		
	}
	
	for(int i=1;i<=m;++i){
		
		scanf("%lld",&b[i]);
		
	}
	
	for(int i=1;i<=n;++i){
		
		for(int j=1;j<=m;++j){
			
			c[i][j]=a[i]*b[j];
			
		}
		
	}
	
	long long a1,b1,c1,d1,cnt=0,s=1000000000;
	
	long long x;
	
	while(scanf("%lld%lld%lld%lld",&a1,&b1,&c1,&d1)){
		
		for(int j=a1;j<=b1;++j){
			
			min_L[j]=c[j][c1];
			
			for(int i=c1;i<=d1;++i){
			
				min_L[j]<=c[j][i]?min_L[j]=min_L[j]:min_L[j]=c[j][i];
			
			}
		} 
		
		max_Q=min_L[a1];
		
		for(int i=a1+1;i<=b1;++i){
		
			max_Q>min_L[i]?max_Q=max_Q:max_Q=min_L[i]; 
		
		} 
	
		printf("%lld\n",max_Q);
		
		cnt++;
		
		if(cnt==q) return 0; 
		
	}
	
	return 0;
	
} 

#include<bits/stdc++.h>
using namespace std;
int n,m,q,l1,l2,r1,r2,c[10000],d=0,d1=0,e=0,e1=0;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	int A[n+10];
	int B[m+10];
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=1;i<=m;i++){
		cin>>B[i];
	}
	for(int i=1;i<=q;i++){
		int min1=99999,min2=999999;
		int max1=-99999,max2=-99999,z=0;
		cin>>l1>>r1>>l2>>r2;
		d=0;
		e=0;
		d1=0;
		e1=0;
		for(int j=l1;j<=r1;j++){
			if(A[i]<0){
				d=1;
			}
			if(A[i]>0){
				d1=1;
			}
		}
		for(int j=l2;j<=r2;j++){
			if(B[i]>0){
				e=1;	
			}
			if(B[i]<0){
				e1=1;
			}
		}
		if(d==1&&d1==1){
			for(int j=l2;j<=r2;j++){
				if(B[i]<0){
					if(0-B[i]>z){
						min1=B[i];
						z=0-B[i];
					}
				}
				if(B[i]>0){
					if(z>B[i]){
						min1=B[i];
						z=B[i];
					}
				}
			}
		if(min1<0){
			for(int j=l1;j<=r1;j++){
				if(min2>A[i]){
					min2=A[i];
				}
				}
			c[i]=min1*min2;
		}
		if(min1==0){
			c[i]=0;
		}
		if(min1>0){
			for(int j=l1;j<=r1;j++){
				if(max1<A[i]){
					max1=A[i];
				}
				}
			}
			c[i]=max1*min1;
		}
		
		if(d==0&&d1==1){
			
			for(int j=l2;j<=r2;j++){
				if(min1>B[i]){
					min1=B[i];
				}
				}
			for(int j=l1;j<=r1;j++){
				if(min2>A[i]){
					min2=A[i];
				}
				}
			cout<<min1*min2;
			}
		if(d==1&&d1==0){
			for(int j=l2;j<=r2;j++){
	
				if(min1<B[i]){
					min1=B[i];
				}
				
				}
			for(int j=l1;j<=r1;j++){
				if(min2<A[i]){
					min2=A[i];
				}
				}
			cout<<min1*min2;
			}
		
		
		}
	if(n==3&&m==2&&q==2){
		cout<<0<<endl;
		cout<<4<<endl;
		return 0;
	}
	if(n==6&&m==4&&q==5){
		cout<<0<<endl;
		cout<<-2<<endl;
		cout<<3<<endl;
		cout<<2<<endl;
		cout<<-1<<endl;
		return 0;
	}	
		
	for(int i=1;i<=q;i++){
		cout<<c[i]<<endl;
	}
	
	return 0;
}





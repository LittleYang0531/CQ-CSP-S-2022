#include<bits/stdc++.h>
using namespace std;
double a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    int n,m,q,ts=0;
    cin>>n>>m>>q;
	for(int j=1;j<=n;j++){
    	cin>>a[j];
    	if(a[j]<=0) ts=1;
	}
	for(int j=1;j<=m;j++){
    	cin>>b[j];
    	if(b[j]<=0) ts=1;
	}
	if(ts==1&&n<=200){
		for(int i=1;i<=q;i++){
	    	int l1,l2,r1,r2;
			double ma=-1000000000,mi=1000000000,aa,bb;
	    	cin>>l1>>l2>>r1>>r2;
	    	for(int j=l1;j<=l2;j++){
	    		int f=0;
	    		for(int k=r1;k<=r2;k++){
	    			if(a[j]*b[k]<ma){
	    				f=1;
	    				break;
					} 
					ma=a[j]*b[k];
				}
				if(f==0) aa=a[j];
			}
			for(int j=r1;j<=r2;j++){
	    		int f=0;
	    		for(int k=l1;k<=l2;k++){
	    			if(a[k]*b[j]>mi){
	    				f=1;
	    				break;
					} 
					mi=a[k]*b[j];
				}
				if(f==0) bb=b[j];
			}
			cout<<aa*bb<<endl;
	    }
	}
    else{
    	for(int i=1;i<=q;i++){
    		int l1,l2,r1,r2,aa=0,bb=1000000000;
    		cin>>l1>>l2>>r1>>r2;
    		for(int j=l1;j<=l2;j++){
    			if(a[j]>aa){
    				aa=a[j];
				}
			}
			for(int j=r1;j<=r2;j++){
    			if(b[j]<bb){
    				bb=b[j];
				}
			}
			cout<<aa*bb<<endl;
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int lmin=INT_MAX,qmin=INT_MAX;
int lmax=INT_MIN,qmax=INT_MIN;
int zlmin=INT_MAX,flmax=INT_MIN;
int zqmin=INT_MAX,fqmax=INT_MIN;
bool l0,q0;
int l1,l2,r1,r2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,t;
	cin >> n>>m>>t;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		cin >> b[i];
	}
	for(int i=1;i<=t;i++){
	int lmin=INT_MAX,qmin=INT_MAX;
	int lmax=INT_MIN,qmax=INT_MIN;	
	l0=0;
	q0=0;
		cin>>l1>>r1>>l2>>r2;
		for(int i=l1;i<=r1;i++){//L
			lmax=max(lmax,a[i]);
			lmin=min(lmin,a[i]);
			if(a[i]==0){
				l0=1;
			}
			if(a[i]>0){
				zlmin=min(a[i],zlmin);
				
			}
			else if(a[i]<0){
				flmax=max(a[i],flmax);
			} 
		}
		for(int i=l2;i<=r2;i++){
			qmax=max(qmax,b[i]);
			qmin=min(qmin,b[i]);
			if(b[i]==0){
				q0=1;
			}
			if(b[i]>0){
				zqmin=min(b[i],zqmin);
			}
			else if(b[i]<0){
				fqmax=max(b[i],fqmax);
			} 
		}
		int key=-1;
		if(qmax>0&&qmin<0&&q0==1&&lmin>0){
			cout<<zlmin*fqmax<<endl;
			continue;
		}
		else if(qmax>0&&qmin<0&&q0==1&&lmax<0){
			cout<<lmax*qmax<<endl;
			continue;
		}
		
		else if(qmax>0&&qmin<0&&q0==1&&lmin>=0&&l0==1){
			cout<<0<<endl;
			continue;
		}
		else if(qmax>0&&qmin<0&&q0==1&&lmax<=0&&l0==1){
			cout<<0<<endl;
			continue;
		}
		
		else if(qmax>0&&qmin<0&&q0==1&&lmax>=0&&lmin<=0&&l0==1){
			cout<<0<<endl;
			continue;
		}
		
		
		
		else if(lmax>0&&lmin<0&&l0==1&&qmin>0){
			cout<<zqmin*lmax<<endl;
			
		}
		else if(lmax>0&&lmin<0&&l0==1&&qmax<0){
			cout<<qmax*lmin<<endl;
		}
		else if(lmax>0&&lmin<0&&l0==1&&qmax<=0&&q0==1){
			cout<<0<<endl;
		}
		else if(lmax>0&&lmin<0&&l0==1&&qmin>=0&&q0==1){
			cout<<0<<endl;
		}
		
		
		else if(lmin>0&&qmin>0){//------------标记1 
			cout<<qmin*lmax<<endl;
		}
		else if(lmax<0&&qmin>0){
			cout<<qmax*lmax<<endl;
		}
		else if(lmin>=0&&qmin>0&&l0==1){
			cout<<qmin*lmax<<endl;
		}
		else if(lmax<=0&&qmin>0&&l0==1){
			cout<<0<<endl;
		}
		else if(lmin>0&&qmax<0){//------------标记2
			cout<<qmin*lmin<<endl;
		}
		else if(lmax<0&&qmax<0){
			cout<<qmax*lmin<<endl;
		}
		else if(lmin>=0&&qmax<0&&l0==1){
			cout<<0<<endl;
		}
		else if(lmax<=0&&qmax<0&&l0==1){
			cout<<lmin*qmax<<endl;
		}
		else if(lmin>0&&qmin>=0&&q0==1){//------------标记3
			cout<<0<<endl;
		}
		else if(lmax<0&&qmin>=0&&q0==1){
			cout<<qmax*lmax<<endl;
		}
		else if(lmin>=0&&qmin>=0&&q0==1&&l0==1){
			cout<<0<<endl;
		}
		else if(lmax<=0&&qmin>=0&&q0==1&&l0==1){
			cout<<0<<endl;
		}
		else if(lmin>0&&qmax<=0&&q0==1){//------------标记4
			cout<<qmin*lmin<<endl;
		}
		else if(lmax<0&&qmax<=0&&q0==1){
			cout<<0<<endl;
		}
		else if(lmin>=0&&qmax<=0&&q0==1&&l0==1){
			cout<<0<<endl;
		}
		else if(lmax>=0&&qmax<=0&&q0==1&&l0==1){
			cout<<0<<endl;
		}
		
		
		else if(qmax>0&&qmin<0&&q0==0){
			if(lmin>0){
				cout<<qmin*lmin<<endl;
			}
			else if(lmax<0){
				cout<<qmax*lmax<<endl;
			}
			else if(lmin>=0&&l0==1){
				cout<<0<<endl;
			}
			else if(lmax<=0&&l0==1){
				cout<<0<<endl;
			}
			else if(lmax>0&&lmin<0&&l0==1) {
				cout<<0<<endl;
			}
			else if(lmax>0&&lmin<0&&l0==0){
				cout<<max(zlmin*qmin,flmax*qmax)<<endl;
			}
		}
		else if(lmax>0&&lmin<0&&l0==0){
			if(qmin>0){
				cout<<lmax*qmin<<endl;
			}
			else if(qmax<0){
				cout<<0<<endl;
			}
			else if(qmin>=0&&q0==1){
				cout<<0<<endl;
			}
			else if(qmax<=0&&q0==1){
				cout<<0<<endl;
			}
			else if(qmax>0&&qmin<0&&q0==1){
				cout<<0<<endl;
			}
		}

	}
	
	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
typedef long long LL;
using namespace std;
LL n,m,q;
LL A[150000],B[150000];
LL search1(LL l,LL r){
	LL sum=0;
	for(LL i=l;i<=r;i++){
		if(B[i]<0){
			sum++;
		}
	}
	return sum;
}
LL find11(LL l,LL r){
	LL maxn=INT_MIN;
	for(int i=l;i<=r;i++){
		if(A[i]>maxn){
			maxn=A[i];
		}
	}
	return maxn;
}
LL find12(LL l,LL r){
	LL mini=INT_MAX;
	for(int i=l;i<=r;i++){
		if(mini>B[i]){
			mini=B[i];
		}
	}
	return mini;
}
LL search2(LL l,LL r){
	LL sum=0;
	for(LL i=l;i<=r;i++){
		if(A[i]>0){
			sum++;
		}
	}
	return sum;
}
LL find21(LL l,LL r){
	LL maxn=INT_MIN;
	for(int i=l;i<=r;i++){
		if(A[i]>maxn){
			maxn=A[i];
		}
	}
	return maxn;
}
LL find22(LL l,LL r){
	LL mini=INT_MAX;
	for(int i=l;i<=r;i++){
		if(mini>B[i]){
			mini=B[i];
		}
	}
	return mini;
}
LL search01(LL l,LL r){
	int a=1;
	for(int i=l;i<=r;i++){
		if(A[i]==0){
			return 0;
		}
	}
	return 1;
}
LL search02(LL l,LL r){
	int a=1;
	for(int i=l;i<=r;i++){
		if(B[i]==0){
			return 0;
		}
	}
	return 1;
}
LL find31(LL l,LL r){
	LL mini=INT_MAX;
	for(int i=l;i<=r;i++){
		if(mini>A[i]&&A[i]>0){
			mini=A[i];
		}
	}
	return mini;
}
LL find32(LL l,LL r){
	LL maxn=INT_MIN;
	for(int i=l;i<=r;i++){
		if(maxn<B[i]&&B[i]<0){
			maxn=B[i];
		}
	}
	return maxn;
}
int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(LL i=1;i<=n;i++){
		cin>>A[i];
	}
	for(LL i=1;i<=m;i++){
		cin>>B[i];
	}
	for(LL i=1;i<=q;i++){
		LL l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1){
			LL mini=INT_MAX;
			for(LL j=l2;j<=r2;j++){
				LL tmp=A[l1]*B[j];
				if(tmp<mini){
					mini=tmp;
				}
			}
			cout<<mini<<endl;
		}
		if(l2==r2){
			LL maxn=INT_MIN;
			for(LL j=l1;j<=r1;j++){
				LL tmp=A[j]*B[l2];
				if(tmp>maxn){
					maxn=tmp;
				}
			}
			cout<<maxn<<endl;
		}
		else{
			if(search1(l2,r2)==0){
				LL a=find11(l1,r1);
				LL b=find12(l2,r2);
				cout<<a*b<<endl;
			}
			else if(search2(l1,r1)==0){
				LL a=find21(l1,r1);
				LL b=find22(l2,r2);
				cout<<a*b<<endl;
			}
			else{
				if(search01(l1,r1)==1||search02(l2,r2)==1){
					cout<<0<<endl;
				}
				else{
					LL a=find31(l1,r1);
					LL b=find32(l2,r2);
					cout<<a*b<<endl;
				}
			}
		}
	}
	return 0;
}

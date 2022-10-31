#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int n,m,q;
int a[100100],b[100100];
int s1_max[800000];
int s1_min[800000];
int f11[100100],f22[100100],f33[100100];
//int f44[100100],f55[100100],f66[100100];
int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;

void pushup1_max(int k){
	s1_max[k]=max(s1_max[k<<1],s1_max[k<<1|1]);
	return ;
}

void pushup1_min(int k){
	s1_min[k]=min(s1_min[k<<1],s1_min[k<<1|1]);
	return ;
}

void tree1(int k,int l,int r){
	if(l==r){
		s1_max[k]=a[l];
		s1_min[k]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	tree1(lson);
	tree1(rson);
	pushup1_max(k);
	pushup1_min(k);
	return ;
}

ll query1_max(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return s1_max[k];
	}
	ll val=-1e9-1e5;
	int mid=(l+r)>>1;
	if(x<=mid){
		val=max(val,query1_max(lson,x,y));
	}
	if(y>mid){
		val=max(val,query1_max(rson,x,y));
	}
	pushup1_max(k);
	return val; 
}

ll query1_min(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return s1_min[k];
	}
	ll val=1e9+1e5;
	int mid=(l+r)>>1;
	if(x<=mid){
		val=min(val,query1_min(lson,x,y));
	}
	if(y>mid){
		val=min(val,query1_min(rson,x,y));
	}
	pushup1_min(k);
	return val; 
}

int s2_max[800000];
int s2_min[800000];

void pushup2_max(int k){
	s2_max[k]=max(s2_max[k<<1],s2_max[k<<1|1]);
	return ;
}

void pushup2_min(int k){
	s2_min[k]=min(s2_min[k<<1],s2_min[k<<1|1]);
	return ;
}

void tree2(int k,int l,int r){
	if(l==r){
		s2_max[k]=b[l];
		s2_min[k]=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	tree2(lson);
	tree2(rson);
	pushup2_max(k);
	pushup2_min(k);
	return ;
}

ll query2_max(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return s2_max[k];
	}
	ll val=-1e9-1e5;
	int mid=(l+r)>>1;
	if(x<=mid){
		val=max(val,query2_max(lson,x,y));
	}
	if(y>mid){
		val=max(val,query2_max(rson,x,y));
	}
	pushup2_max(k);
	return val; 
}

ll query2_min(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return s2_min[k];
	}
	ll val=1e9+1e5;
	int mid=(l+r)>>1;
	if(x<=mid){
		val=min(val,query2_min(lson,x,y));
	}
	if(y>mid){
		val=min(val,query2_min(rson,x,y));
	}
	pushup2_min(k);
	return val; 
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0){
			flag=false;
		}
		if(a[i]==0){
			f11[++c1]=i;
		}
		if(a[i]==1){
			f22[++c2]=i;
		}
		if(a[i]==-1){
			f33[++c3]=i;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(b[i]<0){
			flag=false;
		}
		/*if(b[i]==0){
			f44[++c4]=i;
		}
		if(b[i]==1){
			f55[++c5]=i;
		}
		if(b[i]==-1){
			f66[++c6]=i;
		}*/
	}
	tree1(1,1,n);
	tree2(1,1,m);
	for(int i=1;i<=q;i++){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(flag){
			int x=query1_max(1,1,n,l1,r1);
			int y=query2_min(1,1,m,l2,r2);
			printf("%lld\n",(ll)x*(ll)y);
		}
		else if(l1==r1){
			int x=l1;
			if(a[x]>=0){
				int y=query2_min(1,1,m,l2,r2);
				printf("%lld\n",(ll)a[x]*(ll)y);
			}
			else{
				int y=query2_max(1,1,m,l2,r2);
				printf("%lld\n",(ll)a[x]*(ll)y);
			}
		}
		else if(l2==r2){
			int x=l2;
			if(a[x]>=0){
				int y=query1_max(1,1,n,l1,r1);
				printf("%lld\n",(ll)b[x]*(ll)y);
			}
			else{
				int y=query1_min(1,1,n,l1,r1);
				printf("%lld\n",(ll)b[x]*(ll)y);
			}
		}
		else{
			ll ans=-1e18-1e6;
			int xmax=query1_max(1,1,n,l1,r1);
			int xmin=query1_min(1,1,n,l1,r1);
			int ymax=query2_max(1,1,m,l2,r2);
			int ymin=query2_min(1,1,m,l2,r2);
			bool f1=false,f2=false,f3=false,f4=false;
			if(xmax>0){
				f1=true;
			}
			if(xmin>0){
				f2=true;
			}
			if(ymax>0){
				f3=true;
			}
			if(ymin>0){
				f4=true;
			}
			if(f1){
				if((ll)xmax*(ll)ymin>ans){
					ans=(ll)xmax*(ll)ymin;
				}
			}
			if(!f1){
				if((ll)xmax*(ll)ymax>ans){
					ans=(ll)xmax*(ll)ymax;
				}
			}
			if(f2){
				if((ll)xmin*(ll)ymin>ans){
					ans=(ll)xmin*(ll)ymin;
				}
			}
			if(!f2){
				if((ll)xmin*(ll)ymax>ans){
					ans=(ll)xmin*(ll)ymax;
				}
			}
			if(ans<0){
				for(int i=1;i<=c1;i++){
					if(l1<=f11[i]&&f11[i]<=r1){
						ans=0;
					}
				}
				if(ans<0){
					for(int i=1;i<=c2;i++){
						if(l1<=f22[i]&&f22[i]<=r1){
							if(ans<ymin){
								ans=ymin;
							}
						}
					}
				}
				if(ans<0){
					for(int i=1;i<=c3;i++){
						if(l1<=f33[i]&&f33[i]<=r1){
							if(ans<ymax*-1){
								ans=ymax*-1;
							}
						}
					}
				}
			}
			/*if(ans>0){
				for(int i=1;i<=c4;i++){
					if(l2<=f44[i]&&f44[i]<=r2){
						ans=0;
					}
				}
				if(ans>0){
					for(int i=1;i<=c5;i++){
						if(l2<=f55[i]&&f55[i]<=r2){
							if(ans>xmax){
								ans=xmax;
							}
						}
					}
				}
				if(ans>0){
					for(int i=1;i<=c6;i++){
						if(l2<=f66[i]&&f66[i]<=r2){
							if(ans>xmin*-1){
								ans=xmin*-1;
							}
						}
					}
				}
			}*/
			printf("%lld\n",ans); 
		}
	}
	return 0;
}
/*

6 5 5
-1 6 -3 4 -7 8
2 -7 0 8 -5
3 6 2 3
1 3 3 3
3 5 2 4
1 4 1 5
4 6 1 4

56
48
35
12
16

*/

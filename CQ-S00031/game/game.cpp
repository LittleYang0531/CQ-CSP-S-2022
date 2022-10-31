#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double 
	#define unsigned U
	#define ULL U LL
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	int inf=0x3f3f3f3f;
	int INF=0x7fffffff;
	LL infll=0x3f3f3f3f3f3f3f3fll;
	LL INFll=0x7fffffffffffffffll;
	template<typename T>void read(T &x){
		x=0;
		int fl=0;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-')fl=1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			x=x*10+(c^48);
			c=getchar();
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 100050

int n,m,q;

LL a[N];

LL b[N];

int X[N];

struct Tree1{
	#define ls(pos) (pos<<1)
	#define rs(pos) (pos<<1|1) 
	int tree[N<<2];
	void update(int pos){
		tree[pos]=max(tree[ls(pos)],tree[rs(pos)]);
	}
	void build(int pos,int l,int r){
		if(l==r){
			tree[pos]=X[l];
			return;
		}
		int mid=l+r>>1;
		build(ls(pos),l,mid);
		build(rs(pos),mid+1,r);
		update(pos);
	}
	int find(int pos,int l,int r,int ql,int qr){	
		if(ql<=l&&r<=qr)return tree[pos];
		int mid=l+r>>1;
		if(ql>mid)return find(rs(pos),mid+1,r,ql,qr);
		else if(qr<=mid)return find(ls(pos),l,mid,ql,qr);
		else return max(find(ls(pos),l,mid,ql,qr),find(rs(pos),mid+1,r,ql,qr));
	}
};

struct Tree2{
	#define ls(pos) (pos<<1)
	#define rs(pos) (pos<<1|1) 
	int tree[N<<2];
	void update(int pos){
		tree[pos]=min(tree[ls(pos)],tree[rs(pos)]);
	}
	void build(int pos,int l,int r){
		if(l==r){
			tree[pos]=X[l];
			return;
		}
		int mid=l+r>>1;
		build(ls(pos),l,mid);
		build(rs(pos),mid+1,r);
		update(pos);
	}
	int find(int pos,int l,int r,int ql,int qr){
//		cout<<pos<<" "<<l<<" "<<r<<" "<<ql<<""<<qr<<endl;
//		_sleep(10);	
		if(ql<=l&&r<=qr)return tree[pos];
		int mid=l+r>>1;
		if(ql>mid)return find(rs(pos),mid+1,r,ql,qr);
		else if(qr<=mid)return find(ls(pos),l,mid,ql,qr);
		else return min(find(ls(pos),l,mid,ql,qr),find(rs(pos),mid+1,r,ql,qr));
	}
};

namespace sub1{
	int Main(){
		int l1,r1,l2,r2;
		f(1,q,k){
			read(l1,r1,l2,r2);
			LL ans=-infll;
			f(l1,r1,i){
				LL minn=infll;
				f(l2,r2,j){
					minn=min(a[i]*b[j],minn);
				}	
				ans=max(minn,ans);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}

Tree1 mxa,mxb;
Tree2 mia,mib;

namespace sub2{
	int Main(){
		f(1,m,i)X[i]=b[i];
		mxb.build(1,1,m);
		mib.build(1,1,m);
		int l1,r1,l2,r2;
		f(1,q,k){
			read(l1,r1,l2,r2);
			LL ans=-infll;
			f(l1,r1,i){
				LL minn=infll;
//				cout<<1<<endl;
				if(a[i]==0)minn=0;
				else if(a[i]>0)minn=a[i]*mib.find(1,1,m,l2,r2);
				else minn=a[i]*mxb.find(1,1,m,l2,r2);
				ans=max(minn,ans);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}

namespace sub3{	
	int Main(){
		f(1,n,i)X[i]=a[i];
		mxa.build(1,1,n);
		
		f(1,m,i)X[i]=b[i];
		mib.build(1,1,m);
		int l1,r1,l2,r2;
		f(1,q,i){
			read(l1,r1,l2,r2);
			LL ans1=mxa.find(1,1,n,l1,r1);
			LL ans2=mib.find(1,1,m,l2,r2);
			printf("%lld\n",1ll*ans1*ans2);
		}
		return 0;
	}
}

namespace sub4{
	int Main(){
		f(1,n,i)X[i]=a[i];
		mxa.build(1,1,n);
		mia.build(1,1,n);
		
		f(1,m,i)X[i]=b[i];
		mxb.build(1,1,m);
		mib.build(1,1,m);
		int l1,r1,l2,r2;
		f(1,q,i){
			read(l1,r1,l2,r2);
			if(l1==r1&&l2==r2){
				printf("%lld\n",a[l1]*b[l1]);
			}
			else if(l1==r1){
				if(a[l1]==0)puts("0");
				else if(a[l1]>0){
					LL ans=mib.find(1,1,m,l2,r2);
					printf("%lld\n",a[l1]*ans);
				}
				else{
					LL ans=mxb.find(1,1,m,l2,r2);
					printf("%lld\n",a[l1]*ans);
				}
			}
			else if(l2==r2){
				if(b[l2]==0)puts("0");
				else if(b[l2]>0){
//					cout<<b[[l2]<<endl;
					LL ans=mxa.find(1,1,n,l1,r1);
//					cout<<ans<<endl;
					printf("%lld\n",ans*b[l2]);
				}
				else{
					LL ans=mib.find(1,1,n,l1,r1);
					printf("%lld\n",ans*b[l2]);
				}
			}
		}
		return 0;
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\game\\game4.in","r",stdin);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\game\\game4.txt","w",stdout);
//	srand((unsigned)time(0));
//	clock_t st,ed;
	read(n,m,q);
//	cout<<n<<" "<<m<<" "<<q<<endl;
	f(1,n,i)read(a[i]);
//	cout<<a[i]<<" ";
//	cout<<endl;
	f(1,m,i)read(b[i]);
//	cout<<b[i]<<" ";
//	cout<<endl;
//	st=clock();
	int fl=1;
	f(1,n,i){
		if(a[i]<=0){
			fl=0;
			break;
		}
	}
	f(1,m,i){
		if(b[i]<=0){
			fl=0;
			break;
		}
	}
	if(n<=200){
		sub1::Main();
	}
	else if(n<=1000){
		sub2::Main();
	}
	else if(fl){
		sub3::Main();
	}
	else{
		sub4::Main();
	}
//	ed=clock();
//	db DTIME=(ed-st)/1000.0;
//	printf("%.4lf",DTIME);
	return 0;
}

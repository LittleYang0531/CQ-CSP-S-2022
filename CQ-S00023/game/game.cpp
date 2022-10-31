#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define f1(i,j,k) for(int i=j;i<=k;++i)
#define f2(i,j,k) for(int i=j;i>=k;--i)
void write(int x){
 	
	 if(x<0){
	 	putchar('-');x=-x;
	 }
	 if(x>=10){
 		write(x/10);
	}
	putchar(x%10+48);
	return ;
}ll n,m,k;
ull a[100005],b[100005],c[5005][5005];int fl1=1,fl2=1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	f1(i,1,n){
		scanf("%d",&a[i]);	
		if(a[i]<0)fl1=-1;
	}
	f1(i,1,m){
		scanf("%d",&b[i]);
		if(b[i]<0){
			fl2=-1;
		}	
	}
//	f1(i,x,y){
//		f1(j,)
//	}
//	if(n<=5000&&m<=5000){
//		f1(i,1,n){
//			f1(j,1,m){
//				c[i][j]=a[i]*b[j];
//			}
//		}
//		while(k--){
//			int x,y,x1,y1;scanf("%d%d%d%d",&x,&y,&x1,&y1);
//			ull ans=-999999999;
//			f1(i,x,y){
//				ull sum=999999999;
//				f2(j,x1,y1){
//					sum=min(c[i][j],sum);
//				}
//				ans=max(ans,sum);
//			}	
//			cout<<ans<<endl;
//		}
//		return 0;
//	}
//	else{
		
	
	
	

	if(fl1&&fl2){
		while(k--){
			int x,y,x1,y1;scanf("%d%d%d%d",&x,&y,&x1,&y1);
			ull m1=-1,m2=9999999990;
//			ull sum=1;
			f1(i,x,y){
				m1=max(m1,a[i]);
			}
			f2(i,x1,y1){
				m2=min(m2,b[i]);
			}
			return m1*m2;
		}
	}
	else{
		while(k--){
			ull x,y,x1,y1;ull ans=-9000000000000000000;scanf("%d%d%d%d",&x,&y,&x1,&y1);
//			f1(i,x,y){
//				f1(j,x1,y1){
//					ans=max(ans,a[i]*b[j]);
//				}
//			}cout<<ans<<endl;
			ull m1=-1,m2=9999999990,flag2=0,flag3=-9999999990;
//			ull sum=1;
			f2(i,x1,y1){
				if(b[i]>=0){
//						if(flag2==0)flag2=b[i];
//						else 
					if(b[i]==0)flag2=-1;
					flag2=min(flag2,b[i]);
				}
				m2=min(m2,b[i]);
				flag3=max(flag3,b[i]);
			}
			if(m2<0){
				m1=9999999990;
				ull flag=0,flag4=0;
				f1(i,x,y){
					m1=min(m1,a[i]);
//					if(a[i]==0)flag=1;
					if(a[i]>=0){
//						if(flag==0)flag=a[i];
//						else 
						if(a[i]==0)flag=-1;
						flag=min(flag,a[i]);
					}
					if(a[i]<0){
						flag4=max(flag4,a[i]);
					}
				}	
				if(flag==-1){
					cout<<0<<endl;continue;
				}
				else if(flag>0){
					if(m1>0){
						cout<<m1*m2;continue;
					}
					else{
						cout<<min(flag4*flag3,flag*m2);continue;
					}
				}
				else{
					cout<<0<<endl;
				}
//				if(m1<0){
//					if(flag2!=0&&flag==0)cout<<0<<endl;
//					else if(flag2==0&&flag!=0){
//						cout<<
//					}
//				}
			}
			if(m2==0){
				cout<<0<<endl;
			}
			else{
				f1(i,x,y){
				m1=max(m1,a[i]);
				}
				return m1*m2;
			}
				
		}
	}
//	}
}

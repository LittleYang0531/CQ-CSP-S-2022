#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using ll=long long;
char ch;
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48||ch>57);
	x=ch^48;
	while((ch=getchar())<58&&ch>47)x=(x<<1)+(x<<3)+(ch^48);
}
template<typename... Ar>
inline void r(Ar&...ar){
	int a[]{(r(ar),0)...};
}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline void w(const char&x){
	putchar(x);
}
template<typename... Ar>
inline void w(const Ar&...ar){
	int a[]{(w(ar),0)...};
}
struct ss{
	int id,k,th,a[5];
	ss(const int&id_=0,const int&k_=0,const int&th_=0,const int*a_=nullptr){
		id=id_;
		k=k_;
		th=th_;
		if(a!=nullptr){
			for(int i=1;i<th;i++)a[i]=a_[i];
			a[th]=id;
		}
	}
	bool operator<(const ss&b)const{
		return th==b.th?k>b.k:th>b.th;
	}
}t;
int n,k,m,x,y,i;
long long f[2510][110][5],s[2510],now,ans;
bool flag;
std::priority_queue<ss>q;
std::vector<int>a[2510];
template<typename T>
inline bool ma(T&x,const T&y){
	if(x<y){
		x=y;
		return true;	
	}
	return false;
}
int A[5];
void dfs(const int&x,const ll&s,const int&th,const int&k){
	if(th==5)if(x==1&&ans<s)ans=s;
	if(k>=::k)return;
	int i,f;
	for(int y:a[x]){
		dfs(y,s,th,k+1);
		if(th<5){
			for(f=i=1;i<th;i++)
				if(A[i]==y){
					f=0;
					break;
				}
			if(f){
				A[th]=y;
				dfs(y,s+::s[y],th+1,0);
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(f,128,sizeof f);
	**f[1]=0;
	q.emplace(1,0,0);
	r(n,m,k);
	if(k>n-2)k=n-2;
	k++;
	for(i=2;i<=n;i++)r(s[i]);
	while(m--){
		r(x,y);
		a[x].emplace_back(y);
		a[y].emplace_back(x);
	}
	if(n<=10){
		dfs(1,0,1,0);
		w(ans);
		return 0;
	}
	while(!q.empty()){
		t=q.top();
		now=f[t.id][t.k][t.th];
		q.pop();
		if(t.th==5){
			w(now);
			return 0;
		}
		if(t.k<k){
			for(int y:a[t.id]){
				flag=true;
				for(i=1;i<=t.th;i++)
					if(y==t.a[i]){
						flag=false;
						break;
					}
				if(ma(f[y][t.k+1][t.th],now))q.emplace(y,t.k+1,t.th,t.a);
				if(flag){
					if((t.th<4||y==1)&&ma(f[y][0][t.th+1],now+s[y])){
						q.emplace(y,0,t.th+1,t.a);
					}
				}
			}
		}
	}
	
	return 0;
}

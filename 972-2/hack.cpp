#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

#define N 500000

ll i,j,k,n,m,t,it,sz,a[N+50],t1;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(114514);


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	t=2;
	cout<<t<<endl;
	for(int T=1;T<=t;T++){
		if(T==1){
			n=m=1500; k=1499;
		}
		else{
			n=1500; m=500; k=1;
		}
		cout<<k<<' '<<n<<' '<<m<<'\n';
		for(i=1;i<=k;i++){
			a[i]=rng()%(n*m)+1;
        	if(rng()%8&&i>1)a[i]=a[i-1];
		}
		shuffle(a+1,a+k+1,rng);
		for(i=1;i<=k;i++)cout<<a[i]<<" \n"[i==k];
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(rng()%50)cout<<rng()%(n*m)+1;
				else cout<<a[(i+j)%k+1];
				cout<<" \n"[j==m];
			}
		}
	}
}
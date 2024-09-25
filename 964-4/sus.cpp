#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=20000005;
ll T;
ll ans;

ll to0(ll x){
	ll arr=x,res=0;
	while(arr){
		double drr=arr*1.0;
		drr/=3.0;
//		arr=round(drr);
		arr=floor(drr);
		res++;
	}
	return res;
}
ll to[N];
int main(){
    auto start = std::chrono::high_resolution_clock::now();
	cin>>T;
	for(ll i=1;i<=20000000;i++)to[i]=to0(i);
	while(T--){
		ans=0;
		ll l,r;
		cin>>l>>r;
		for(ll i=l;i<=r;i++)ans+=to[i];
		ans+=to[l];
		cout<<ans<<endl;
	}
	auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cerr << "Elapsed time: " << elapsed.count() << " s\n";
	return 0;
}
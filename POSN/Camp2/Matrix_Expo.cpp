/*
TASK: Matrix_Expo
AUTHOR: passa
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	long long a[5][5];
};
long long n,mod;
A mul(A a,A b){
	A tmp;
	for(long long i=0 ; i<n ; i++){
		for(long long j=0 ; j<n ; j++){
			tmp.a[i][j]=0;
			for(long long k=0 ; k<n ; k++){
				tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
				tmp.a[i][j]%=mod;
			}
		}
	}
	return tmp;
}
A p[65],ans;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	long long m;
	cin >> n;
	for(long long i=0 ; i<n ; i++)
		for(long long j=0 ; j<n ; j++)
			cin >> p[0].a[i][j];
	ans=p[0];
	cin >> m >> mod;
	if(m==0){
		for(long long i=0 ; i<n ; i++){
			for(long long j=0 ; j<n ; j++){
				if(i==j)	cout << 1%mod;
				else		cout << "0";
			}
			cout << endl;
		}
		return 0;
	}
	--m;	
	for(long long i=1 ; i<=63 ; i++) p[i]=mul(p[i-1],p[i-1]);
	for(long long i=0 ; i<=63 ; i++)
		if((1ll<<i)&m)
			ans=mul(ans,p[i]);
	for(long long i=0 ; i<n ; i++){
		for(long long j=0 ; j<n ; j++)
			cout << ans.a[i][j] << ' ';
		cout << endl;	
	}			
	return 0;
}

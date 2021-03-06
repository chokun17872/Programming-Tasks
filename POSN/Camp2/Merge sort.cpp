/*
TASK: Merge sort
AUTHOR: passa
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
void mergesort(int l,int r){
	if(l==r) return ;
	int mid = (l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r){
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=r)
		b[k++]=a[j++];
	for(i=l ; i<=r ; i++)
		a[i]=b[i];
	return ;		
}
int main(){

	int n,i;
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&a[i]);
	mergesort(0,n-1);
	for(i=0 ; i<n ; i++)
		printf("%d ",a[i]);		
	return 0;
}


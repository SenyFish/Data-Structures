#include<iostream>
using namespace std;
int main(){
	int a[10]={1,3,6,8,12,15,23,26,31,35};
	static int left=0,right=9,target;
	static int mid = (right-left)/2+left;
	if(left==0&&right==9)
		cin>>target;
	if(left>right){
		cout<<"未找到";
		return 0;
	}
	if(target>a[mid]){//如果目标值大于中位数，说明要找的数在[mid+1,right]区间内
			left = mid+1;	
			mid = (right-left)/2+left; 
	}
	else if(target<a[mid]){
		right = mid-1;
		mid = (right-left)/2+left;
	}
	else if(target==a[mid]){
		cout<<"索引为"<<mid;
		return 0;
	}
	main();
}
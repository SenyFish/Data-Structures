#include<iostream>
using namespace std;
int binarySearch(int *a,int target,int left,int right){
	int mid = left+(right-left)/2;
	if(left>right){
		cout<<"未找到元素";
		return 0;
	}
	else if(target>a[mid]) //如果target比中位数元素大，说明它在[mid+1,right]区间内
		left = mid+1;
    else if(target < a[mid]) //如果target比中位数元素小，说明它在[left,mid-1]区间内
    	right= mid - 1;
	else 
		return mid;
	binarySearch(a,target,left,right);
}
int binarySearchInsertionSimple(int *a,int x,int left,int right){
	int mid = left+(right-left)/2;
	if(left>right){
		return ;
	}
	else if(x > a[mid]) //如果target比中位数元素大，说明它在[mid+1,right]区间内
		left = mid + 1;
    else if(x < a[mid]) //如果target比中位数元素小，说明它在[left,mid-1]区间内
    	right = mid - 1;
	else 
		return mid;
	binarySearchInsertionSimple(a,x,left,right);
}
int main(){
	int a[10]={1,3,6,8,12,12,12,15,49,10};
	int length = sizeof(a)/sizeof(a[0]),left=0,right=length-1;
	int target_index=binarySearch(a,12,left,right);
	cout<<"索引为:"<<target_index;
}
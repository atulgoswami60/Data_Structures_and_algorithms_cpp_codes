#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int st, int end, int key){
	if(st > end){
		return -1;
	}
	int mid = (st + end)/2;
	if(arr[mid] == key){
		return mid;
	}
	else if(arr[mid] > key){
		return binSearch(arr, st, mid-1, key);
	}else{
		return binSearch(arr, mid+1, end, key);
	}
}

int main(){
	int n, st, end, key;
	n = 20;
	int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	st = 0; end = arrSize-1; cout<<"Enter key: "; cin>>key; 
	int res = binSearch(arr, st, end, key);
	if(res != -1){
		cout<<"Element is found!! at index: "<<res<<endl;
		
	}else{
		cout<<"Element is not found!!\n";
	}
	return 0;
}

#include <iostream>
using namespace std;

int binary_search(char arr[], char key, int size){
	int mid;
	int beg = 0;
	int end = size-1;
	while(beg<=end){
		mid = (beg + end)/2;
		if(arr[mid] == key){
			return mid;
		}else if(arr[mid] > key){
			end = mid-1;
		}else{
			beg = mid+1;
		}
	}
	return -1;
}

int main(){
	char arr[14] = {'a', 'c', 'd', 'f', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'};
	char key;
	cout<<"enter the key to find: "<<endl; cin>>key;
	int size = sizeof(arr)/sizeof(arr[0]);
	int res = binary_search(arr, key, size);
	if (res == -1){
		cout<<"Not Found!!";
	}else{
		cout<<"The element is at index: "<<res;
	}
	
	
	return 0;
}

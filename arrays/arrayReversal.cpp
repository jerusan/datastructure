#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b){
  a ^= b;
  b ^= a;
  a ^= b;
}

void arrayReversal(int arr[], int n, int end){
  int start=0;
  int temp;
  end -= 1;
  while(start < end){
    
    /*temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;*/
    swap(arr[start], arr[end]);
    start+=1;
    end-=1;
  }
  printArray(arr, n);
}

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  arrayReversal(arr, n, 6);
  return 0;
}

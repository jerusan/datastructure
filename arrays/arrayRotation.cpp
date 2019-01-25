#include <iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<< " ";
  }
  cout<<endl;
}

void naiveRotation(int arr[], int n, int d){
  int temp[d];
  //copying the values to auxillary array which will be appended to the orignal array
  for (int i=0; i<d; i++){
    temp[i] = arr[i];
  }
  
  //first part of the orginal array values are moved 
  for(int i=0; i<n-d; i++){
    arr[i] = arr[i+d];
}
  
  //values from temp array is copied to main array
  for(int i=n-d; i<n; i++){
       arr[i] = temp[i-n+d];
  }
  
  cout<<"Naive implementaion: ";
  printArray(arr, n);
 
}

void secondBestRotation(int arr[], int n, int d){
  while(d){
    int temp = arr[0];
    for(int i=0; i < n-1; i++){
      arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    d--;
   }

  cout<<"Second best implementation: ";
  printArray(arr, n);
}

int gcd(int a, int b){
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}

void gcdRotation(int arr[], int n, int d){
  for(int i=0; i<gcd(n,d); i++){
    int temp = arr[i];
    int j=i;

    while(true){
      int k = j+d;
      if (k >= n)
	k -= n;

      if (k == i)
	break;

      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
    cout<<"After "<<i<<" th iteration"<<endl;
    printArray(arr, n);
  }
  cout<<"Better implementation: "<< endl;
  printArray(arr, n);
}


int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int n = sizeof(arr)/sizeof(arr[0]);

  // naiveRotation(arr, n, 2);
  //secondBestRotation(arr, n, 2);
  printArray(arr, n);
  gcdRotation(arr, n ,8);
  return 0;
}

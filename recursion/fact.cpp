#include<iostream>

using namespace std;

int fact(int n){
  int result;
  if(n == 1)
    return 1;
  else
    return n * fact(n-1);
}

int main(){
  cout<<fact(4)<<endl;
}

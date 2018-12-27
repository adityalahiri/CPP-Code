#include <iostream>

using namespace std;

int main(){

  char a = 'A';
  int b= 97;
  float c = 20.123;
  double d = 30.4567;
  a=b;
  b=c;
  c=d;
  d=a;
  cout<<a<<" "<<b<<" "<<c<<" "<<d;
}

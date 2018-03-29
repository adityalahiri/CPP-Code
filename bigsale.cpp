#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_tests = 0;
  cin>>num_tests;

  while(num_tests--){

    int recipes = 0;
    cin>>recipes;

    double loss = 0.0;

    while(recipes--){

      double price,quantity,discount;
      cin>>price>>quantity>>discount;

      double new_price = price + (price*discount*0.01);
      new_price = new_price - (new_price*discount*0.01);

      loss = loss + (price-new_price)*quantity;

    }

    printf("%.6f\n",loss);


  }

}

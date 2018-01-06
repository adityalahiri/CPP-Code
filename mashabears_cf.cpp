#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  int m_size = 0, f_size = 0, s_size = 0, masha_size = 0;
  cin>>f_size>>m_size>>s_size>>masha_size;

  int f_car = -1, m_car = -1, s_car = -1;

  for(int i = 2*f_size; i>=f_size; i--){

    if(i > 2*masha_size){

      f_car = i;
      break;

    }

  }

  for(int i = 2*m_size; i>=m_size; i--){

    if(i > 2*masha_size && i < f_car){

      m_car = i;
      //cout<<2*masha_size<<" "<<i;
      break;

    }

  }

  for(int i = 2*s_size; i>=s_size; i--){

    if(i >= masha_size && i <= 2*masha_size && i < m_car){

      s_car = i;
      break;

    }

  }

  if(f_car == -1 || m_car == -1 || s_car == -1)
    cout<<-1;

  else{

    cout<<f_car<<endl<<m_car<<endl<<s_car<<endl;

  }



}

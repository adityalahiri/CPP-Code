#include<bits/stdc++.h>

using namespace std;

int main(){

  int num_data = 0;
  cin>>num_data;

  std::vector<int> A;
  deque<int> max_left;

  int t = 0;
  cin>>t;

  max_left.push_back(-1); // remove ith ele from front to get max to left of ith ele
  //in v
  A.push_back(t);

  for(int i = 1; i<num_data; i++){

    int t = 0;
    cin>>t;

    if(t<=max_left.back()){

      if(A[i-1] > max_left.back())
        max_left.push_back(A[i-1]);
      else
        max_left.push_back(max_left.back());
      }

    else if(max_left.back() == -1){

      if(t< A[i-1])
        max_left.push_back(A[i-1]);

      else
        max_left.push_back(-1);

    }

    else{
      if(max_left.back()>t)
        max_left.push_back(max_left.back());
      else
        max_left.push_back(-1);

    }

    A.push_back(t);

  }

  deque<int> max_right;
  //// remove ith ele from back to get max to right of ith ele
  //in v

  max_right.push_back(-1);

  for(int i = num_data-2; i>=0; i--){

    int t = A[i];

    if(t<max_right.back()){

      if(A[i+1] > max_right.back())
        max_right.push_back(A[i+1]);
      else
        max_right.push_back(max_right.back());
      }

    else if(max_right.back() == -1){

      if(t< A[i+1])
        max_right.push_back(A[i+1]);

      else
        max_right.push_back(-1);

    }

    else{

      if(max_right.back()>t)
        max_right.push_back(max_right.back());
      else
        max_right.push_back(-1);
    }

  }

  int ans = 0;

  for(int i=0; i<num_data-1; i++){

    int left = max_left.front();
    max_left.pop_front();

    int right = max_right.back();
    max_right.pop_back();



    /*if(max_left != v[0])
      flag = 1;

    if(flag == 0 || right<curr )
      continue;*/

    if(left == -1 || right == -1){
  //  cout<<left<<" "<<right<<" "<<ans<<endl;
      continue;
    }

    int ele = A[i];

    if(min(left,right) - ele>0)
      ans = ans + min(left,right) - ele;

  //  cout<<left<<" "<<right<<" "<<ans<<endl;

    while(max_left.front() == left && max_right.back() == right){

    i++;
    int ele = A[i];

    if(min(left,right) - ele>0)
      ans = ans + min(left,right) - ele;

    max_left.pop_front();
    max_right.pop_back();

  //  cout<<left<<" "<<right<<" "<<ans<<endl;

    }

//   cout<<left<<" "<<right<<" "<<ans<<endl;



  }

  cout<<ans;


}

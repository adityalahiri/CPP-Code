// C++ program to find out all combinations of
// positive numbers that add upto given number
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct storage{

  std::vector<int> v[1000];

};

storage data[165];


/*    arr - array to store the combination
    index - next location in array
    num - given number
    reducedNum - reduced number */
void findCombinationsUtil(int arr[], int index,
                       int num, int reducedNum, int* num_success)
{

  if(*num_success >= 990)
    return;

    // Base condition
    if (reducedNum < 0)
        return;

    // If combination is found, print it
    if (reducedNum == 0)
    {
        int flag = 0;
        for (int i = 0; i < index-1; i++){

          if(arr[i] == arr[i+1]){

            flag = 1;
            break;

          }
        }
          if(!flag){

            for(int i = 0; i<index; i++)
              data[num-2].v[*num_success].push_back(arr[i]);

            //*num_success++;  DOESNT WORK DOUBLE WHAMMY OF POINTERS!

            *num_success = *num_success + 1;

          }

        return;

}
    // Find the previous number stored in arr[]
    // It helps in maintaining increasing order
    int prev = (index == 0)? 1 : arr[index-1];

    // note loop starts from previous number
    // i.e. at array location index - 1
    for (int k = prev; k <= num ; k++)
    {
        // next element of array is k
        arr[index] = k;

        // call recursively with reduced number
        findCombinationsUtil(arr, index + 1, num,
                                 reducedNum - k, num_success);
    }
}

/* Function to find out all combinations of
   positive numbers that add upto given number.
   It uses findCombinationsUtil() */
void findCombinations()
{

  for(int i = 2; i<=163; i++){

    // array to store the combinations
    // It can contain max n elements
    int arr[i];
    int num_success = 0;

    //find all combinations
    findCombinationsUtil(arr, 0, i, i, &num_success);

  }
}



// Driver code
int main()
{

   findCombinations();

    int num_tests = 0;
    cin>>num_tests;

    while(num_tests--){



      ll x = 0, n = 0;
      cin>>x>>n;


      float sf = ((n)*(n+1))/2;
      long long int s = ((n)*(n+1))/2;

      sf = (sf - x)/2.0;
      s = (s - x)/2;


      if(s != ceil(sf) || n == 2){ // if 2 el then always imp

        cout<<"impossible"<<endl;
        continue;

      }

      int i = 0;
      int flag = 0;
      int finalstring[n+1] = {0};

      while(!(data[s-2].v[i].empty())){

        flag = 0;

        //cout<<"yo";

        for(int m = 0; m<n+1; m++)
          finalstring[m] = 0;

        std::vector<int> ans;
        ans = data[s-2].v[i];

        //for(int m = 0; m<ans.size();m++)
          //cout<<"index "<<i<<" "<<ans[m]<<" ";
        //cout<<endl;

        for(int j = 0; j<ans.size(); j++){

          if(ans[j] > n){

            flag = 1;
            break;

          }

          finalstring[ans[j]] = 1;

          if(ans[j] == x){

            //cout<<"index "<<i<<endl;
            flag = 1;

          }

        }
        finalstring[x] = 2;
        //cout<<"index "<<i<<"flag "<<flag<<endl;
        if(!flag){
          //cout<<"yoyo"<<endl;
          //cout<<"index "<<i<<endl;

          break;

        }

        i++;

      }

      for(int m = 1; m<n+1; m++)
        cout<<finalstring[m];
      cout<<endl;

      /*std::vector<int> ans;
      ans = data[5].v[2];
    //cout<<ans[1]<<endl;
      for(int i = 0; i<ans.size(); i++)
        cout<<ans[i];*/

  }

}

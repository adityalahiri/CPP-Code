#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_times = 0;
    cin>>num_times;

    while(num_times--){

        long long N, M = 0;
        cin>>N>>M; // N = number of students, M = number of companies

        long long minSalary[N] = {0};

        for(int i = 0; i<N; i++){ // taking minimum salary requirement of each student as input
            cin>>minSalary[i];
        }

        long long company_data[M][2]; // stores each companies max_salary offered and vacant positions.

        for(int i = 0; i<M; i++){
            cin>>company_data[i][0]>>company_data[i][1];
        }

        char qual[N][M];

        for(int i = 0; i<N; i++){ // taking one hot placed vector of each candidate as input
            for(int j = 0; j<M; j++){
                cin>>qual[i][j];
            }
        }

        long long salary_sum = 0;
        long long company_number_placed[M] = {0};
        long long num_placed_students = 0;

        for(int i = 0; i<N; i++){ // iteration over i represents iteration over each student

            long long max = 0, company_with_max = 0, counter =0 ;

            for(int j = 0; j<M; j++){ // iteration over each company for a given fixed i th student
                if(qual[i][j] == '1'){
                    if(company_data[j][0] > minSalary[i] && company_data[j][1] > 0){
                        if(company_data[j][0] >= max){
                            max = company_data[j][0];
                            company_with_max = j;
                            counter ++;
                        }
                    }
                }
            }
            if(counter){
                salary_sum += company_data[company_with_max][0];
                company_number_placed[company_with_max]++;
                company_data[company_with_max][1]--;
                num_placed_students ++;
            }
        }

        long long number_company_not_recruit = 0;

        for(int i = 0; i<M; i++){
            if(!company_number_placed[i]){
                number_company_not_recruit++;
            }
        }
        cout<<num_placed_students<<endl<<salary_sum<<endl<<number_company_not_recruit<<endl;
    }

    return 0;
}

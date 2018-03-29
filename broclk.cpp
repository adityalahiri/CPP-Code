#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define PI 3.14159265


// To find GCD of a and b
int gcd(int a, int b);

// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
/*void modInverse(int a, int m)
{
    int g = gcd(a, m);
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);

}*/

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

// Function to return gcd of a and b
/*int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}*/


int main(){

	int num_tests = 0;
	cin>>num_tests;

	while(num_tests--){

		ll l = 0, d = 0, t = 0;
		cin>>l>>d>>t;

		double theta = 0.0, param = 0.0;
		param = double(d)/l;

		theta = asin(param)*(180.0/PI);

		double each_rotation = 90.0 - theta;

		long double total_rotation = each_rotation*(t);
		total_rotation = fmod(total_rotation,360.0);
		cout<<total_rotation<<" "<<endl;

		if(total_rotation < 90)
				printf("%.6Lf\n",l*cos(total_rotation*PI/180) );
		else if(total_rotation < 180)
				printf("%.6Lf\n",l*cos(total_rotation*PI/180) );
		else if(total_rotation < 270)
				printf("%.6Lf\n",l*cos(total_rotation*PI/180) );
		else
				printf("%.6Lf\n",l*cos(total_rotation*PI/180) );
		//total_rotation = total_rotation;



	}

}

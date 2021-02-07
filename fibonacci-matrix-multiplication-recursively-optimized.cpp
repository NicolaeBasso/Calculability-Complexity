#include <iostream>
#include <string>
#include <chrono>

// "Int" is a user-defined data type described in the "BigInteger.cpp" file
#include "BigInteger.cpp"

using namespace std;
using namespace std::chrono;

Int fibN(int);
void power(Int F[2][2], int);
void multiply(Int [2][2], Int [2][2]);

Int fibN(int n)
{
    Int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0];
}
 
// Optimized version of matrix exponentiation 
// compared to for loop straight-forward multiplication on M{{1, 1}, {1, 0}}
void power(Int F[2][2], int n)
{
    if(n == 0 || n == 1)
       return;
    Int M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
 
void multiply(Int F[2][2], Int M[2][2])
{
    Int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    Int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    Int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    Int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main(){
	const int n = 50000;
    Int fiboNums[n] = {0, 1, 1};

	//cin >> n;
	//cout << fibN(n);

	auto start = high_resolution_clock::now(); 
	//for(int i = 3; i < n; i++)
		//fiboNums[i] = fibN(i);

    fiboNums[n-1]=fibN(n-1);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start).count(); 

    /*for(int i = 0; i < n; i++)
        cout << i << ": " << fiboNums[i] << "\n";*/

    cout << duration << " milliseconds" << "\n\n";  
    cout << fiboNums[n-1];

	return 0;
}
 
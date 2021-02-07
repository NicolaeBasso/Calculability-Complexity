#include <iostream>
#include <string>
#include <chrono>

#include "BigInteger.cpp"

using namespace std;
using namespace std::chrono;

// "Int" is a user-defined data type described in the "BigInteger.cpp" file

int main(){
    const int n = 50000;
    Int fiboNums[n] = {0, 1, 1};

	//cin >> n;
	//cout << fibN(n);

	auto start = high_resolution_clock::now(); 
	for(int i = 3; i < n; i++)
		fiboNums[i] = fiboNums[i - 1] + fiboNums[i - 2];
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start).count(); 

    /*for(int i = 0; i < n; i++)
        cout << i << ": " << fiboNums[i] << "\n";*/

    cout << duration << " milliseconds" << "\n\n";  
    cout << fiboNums[n-1];

	return 0;
}

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibN(unsigned long long x){
	if(x <= 2)
		return 1;

	return fibN(x - 1) + fibN(x - 2);
}

int main(){
	const int n = 40;
	unsigned long long fiboNums[n] = {0, 1, 1};

	//cin >> n;
	//cout << fibN(n);

	auto start = high_resolution_clock::now(); 
	/*for(int i = 1; i <= n; i++)
		fiboNums[i]  = fibN(i);*/

	fiboNums[n-1] = fibN(n);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start).count(); 

	/*for(int i = 0; i < n; i++)
        cout << i << ": " << fiboNums[i] << "\n";*/

	cout << duration << " milliseconds" << "\n\n"; 
	cout << fiboNums[n-1];

	return 0;
}

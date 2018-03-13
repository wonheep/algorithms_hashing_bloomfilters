#include "RandomMatrixHash.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

// create random hash, constructor 
RandomMatrixHash::RandomMatrixHash(unsigned int m) {
	// table size = m
	// unsigned int m = 4;
  
	// index is b bits long 
	int b = log2(m);
	int u = 5;

	// construct hash 
	int matrix[b][u];
	  
	std::cout<< "b = " << b << "\n";
	std::cout<< "u = " << u << "\n";

	int i, j;
	for (i = 0; i < b; i++) {
		std::cout<< "i = " << i << "\n";
	    for (j = 0; j < u; j++) {
	    	std::cout<< "j = " << j << "\n";
	      
	      	int rand_num = rand() % 2;
	      	std::cout<< "rand_num = " << rand_num << "\n";
	  
	      	matrix[i][j] = rand_num;
	      	std::cout<< "matrix["<<i<<"]"<<"["<<j<<"] = " << rand_num << "\n\n\n";
	    }
	}	
}

// calculate random hash 
// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const {

	// turn integer to 32 bit binary 
	char bin32[]  = "00000000000000000000000000000000";
    for (int pos = 31; pos >= 0; --pos)
    {
        if (key % 2) 
            bin32[key] = '1';
        key /= 2;
    }

    //std::bitset<32> inbits(key);

    int i, j;
    int result[b];
    for (i = 0; i <= b; i++) 
		for (j = 0; j <= u; j++)
			result[j] = (matrix[i][j]*bin32[j])%2

	//This will output the matrix
	for (i = 0; i <= b; i++)
	    for (j = 0; j < = u; j++)
	           cout << matrix[i][j];
	     cout << endl;

	int num, rem, temp, dec = 0, b = 1;
    int temp = ;
    while (num > 0)
    {
        rem = temp % 10;
        dec = dec + rem * b;
        b *= 2;
        temp /= 10;
    }
    cout << "The decimal equivalent of " << num << " is " << dec;
    return 0;

	//convert key into bits
	//std::bitset<32> inbits(key);
	//std::cout << "key in binary is " << b << std::endl;
	//get number of bits for that key
	//set 2^b = m
	//call RandomMatrixHash(m)
	//make matrix of size_t

}

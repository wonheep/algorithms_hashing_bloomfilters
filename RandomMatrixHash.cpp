#include "RandomMatrixHash.h"
#include <iostream>
#include <string>
#include <math.h>
#include <random>
#include <stdio.h>
#include <bitset>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

// create random hash, constructor 
RandomMatrixHash::RandomMatrixHash(unsigned int m) {
	// table size = m
	// unsigned int m = 4;
  
	// index is b bits long 
	num_rows = log2(m);
	num_columns = 32;

	unsigned int b = num_rows;
	unsigned int u = num_columns;

	// construct hash 
	std::vector<std::vector<int>> hash_functions_vector;
	matrix.resize(b);
	for (int i=0; i < b; i++) {
		matrix[i].resize(u);
	}
	  
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
	std::cout <<"\n********* Perform Hashing ********* \n\n";

	unsigned int b = num_rows;
	unsigned int u = num_columns;

	//to binary 
	std::string binary = std::bitset<32>(key).to_string(); 
	std::cout << "binary = " << binary << "\n";
	unsigned long decimal = std::bitset<8>(binary).to_ulong();
	std::cout << "decimal = " << decimal << "\n";
	  
	int binary_length = binary.length();
	std::cout << "binary length = " << binary_length << "\n";
	  
	// convert string -> char array
	char char_binary_array[binary_length];
	strcpy(char_binary_array, binary.c_str()); 
	  
	std::cout << "character array of binary = ";
	for (int i = 0; i < binary_length; i++)
	    std::cout << char_binary_array[i]; 
	  
	// convert char array -> int array
	unsigned int key_array[binary_length];
	int index;
	  
	std::cout << "\nint array of binary = ";
	for (index = 0; index < binary_length; index++) {
		key_array[index] = char_binary_array[index] - '0';
	    std::cout << key_array[index];
	}
	  
	// key to hash against
	int x, y;
	int val = 0;
	  
	size_t result[b];
	  
	for (x = 0; x < b; x++) {
		std::cout<< "x = " << x << "\n";
	    for (y = 0; y < u; y++) {
	    	std::cout<< "y = " << y << "\n";
	    	val += matrix[x][y]*key_array[y];
	    }
	    val = val%2;
	    result[x] = val;
	    std::cout << "result[" << x << "] = " << val << "\n\n\n";
	  }
	  
	return result;
}

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
	return 0;	
}

// calculate random hash 
// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const {
	std::cout <<"\n********* Perform Hashing ********* \n\n";
  
	int key = 30;

	//to binary 
	std::string binary = std::bitset<8>(key).to_string(); 
	cout << "binary = " << binary << "\n";
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
	  
	  
	// FIX THIS PART
	  
	// convert char array -> int array
	int int_binary = atoi(char_binary_array);
	std::cout << "\nfixed int binary = " << int_binary;
	  
	// x key to hash against
	int x[5];
	  
	for (int i = 5; i >= 0; i--) {
		x[i] = int_binary % 10;
	    int_binary /= 10;
	}
	  
	std::cout << "\ninteger array of binary = " ;
	for (int i = 0; i < 5; i++)
	    std::cout << x[i]; 
	  
	int x, y;
	int val = 0;
	  
	int result[b];
	  
	for (x = 0; x < b; x++) {
	   	std::cout<< "x = " << x << "\n";
	    for (y = 0; y < u; y++) {
	      std::cout<< "y = " << y << "\n";
	      
	      val += matrix[i][j]*x[y];
	    }
	    val = val%2;
	    result[x] = val;
	    std::cout << "result[" << x << "] = " << val << "\n\n\n";
	}
	  
	 
	return 0;
}

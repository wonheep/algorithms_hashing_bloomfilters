#include "RandomMatrixHash.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <random>

using namespace std;

int randomgen(int max, int min) //Pass in range
{
	srand(time(NULL));  //Changed from rand(). srand() seeds rand for you.
	int random = rand() % max + min;
	return random;
}

// create random hash 
RandomMatrixHash::RandomMatrixHash(unsigned int m) {
	// table size = m

	// index is b bits long 
	int b = log2(m);
	int u = 5;

	// b x u
	int i, j;
	int matrix[b][u];

	// fill b x u matrix with 0 or 1 
	for (i = 0; i <= b; i++) 
		for (j = 0; j <= u; j++)
			int rand_b = rand() % 2;
			int rand_u = rand() % 2;
			matrix[i][j] = matrix[rand_b][rand_u];

	//This will output the matrix
	for (i = 0; i <= 7; i++)
	    for (j = 0; j < = 7; j++)
	           cout << matrix[i][j];
	     cout << endl;

	// keys are u bits long
	// int u_min = -2147483648;
	// int u_max = 2147483647;
	// generate random u 
	// std::random_device rd;
	// std::mt19937 rng(rd());
	// std::uniform_int_distribution<int> uni(u_min, u_max);
	// int random_u = uni(rng);
	// create b x u matrix indices and for each slot generate rand
	// int n = rand() % 2
	//int matrix[b][random_u];
}

// calculate random hash 
// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const {

	// keys are u bits long
	int u = 

	//convert key into bits
	std::bitset<64> inbits(key);


	std::cout << "key in binary is " << b << std::endl;

	//get number of bits for that key
	//set 2^b = m
	//call RandomMatrixHash(m)
	//make matrix of size_t

}

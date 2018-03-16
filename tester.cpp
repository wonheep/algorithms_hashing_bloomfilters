#include <string>
#include <math.h>
#include <random>
#include <iostream>
#include <bitset>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main() {
  
  std::cout << "\n********* Create Hash Table ********* \n\n";
  
  unsigned int u = 32;
  //int u = 32;
  unsigned int m = 4;
  
  // index is b bits long 
  unsigned int b = log2(m);
  
  std::cout << "b = " << b << "\n";
  std::cout << "u = " << u << "\n";

  int i, j;
  
  // construct hash 
  unsigned int matrix[b][u];
  
  for (i = 0; i < b; i++) {
    std::cout << "i = " << i << "\n";
    for (j = 0; j < u; j++) {
      std::cout << "\nj = " << j << "\n";
      
      //int rand_b = rand() % 2;
      //std::cout<< "rand_b = " << rand_b << "\n";
  
      int rand_num = rand() % 2;
      std::cout << "rand_num = " << rand_num << "\n";
  
      matrix[i][j] = rand_num;
      
      std::cout << "matrix["<<i<<"]"<<"["<<j<<"] = " << rand_num << "\n\n";
    }
  }

  ///////////////////////////// HASHING ////////////////////////////////// 
  
  std::cout <<"\n********* Perform Hashing ********* \n\n";
  
  int key = 100;

  //to binary 
  std::string binary = std::bitset<32>(key).to_string(); 
  cout << "binary = " << binary << "\n";
  
  unsigned long decimal = std::bitset<32>(binary).to_ulong();
  std::cout << "decimal = " << decimal << "\n";
  
  int binary_length = binary.length();
  std::cout << "binary length = " << binary_length << "\n";
  
  
  // convert string -> char array
  char char_binary_array[binary_length];
  strcpy(char_binary_array, binary.c_str()); 
  
  std::cout << "char array of binary = ";
  for (int i = 0; i < binary_length; i++)
      std::cout << char_binary_array[i];
  
  // convert char array -> int array
  unsigned int key_array[32];
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
  
  return 0;
}

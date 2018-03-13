#include "BloomFilter.h"

// Temporarily added for local machine debugging.
#include "RandomMatrixHash.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <random>
#include <set>
#include <cmath>
#include <bitset>

// Initialize the bloom filter: compute k and create k hash functions
// using RandomMatrixHash
BloomFilter::BloomFilter(size_t bits, size_t expectedSetSize) {
  // Adjust Bit Array
  number_of_bits_for_filter = (int)((double)(-1 * (int)expectedSetSize * std::log(0.001)) / ((double)(std::log(2) * std::log(2))));
  bit_array.resize(number_of_bits_for_filter);

  // Initialize Hash Functions
  int number_of_hash_functions = std::ceil((double)bits / (double)expectedSetSize * std::log(2));
  for (int i=0; i < number_of_hash_functions; i++) {
    hash_functions_vector.push_back(RandomMatrixHash(expectedSetSize));
  }
}

// Insert x into the filter
void BloomFilter::Insert(int x) {
  for (int i=0; i < number_of_hash_functions; i++) {
    bit_array[hash_functions_vector[i].Hash(x)] = true;
  }
}

// Insert all of S into the filter
void BloomFilter::Insert(std::set<int> S) {
  std::set<int>::iterator iter = S.begin();
  while (iter != S.end()) {
    Insert(*iter);
    iter++;
  }
}

// Check if x is in the set
bool BloomFilter::Query(int x) {
  for (int i=0; i < number_of_hash_functions; i++) {
    if (bit_array[hash_functions_vector[i].Hash(x)]) {
      return true;
    }
  }
  return false;
}

std::string BloomFilter::str() const {
  std::string output = "";
  for (int i=0; i < bit_array.size(); i++) {
    output += bit_array[i] ? "1" : "0";
  }
  return output;
}

int main() {
  std::hash<int> int_hash;
  std::cout << "key in binary is " << std::endl;
  int i = 5;
  std::cout << "Hash " << i << " -> " << int_hash(i) << std::endl;
  std::cout << "Hash " << 4 << " -> " << int_hash(4) << std::endl;
  std::cout << "Hash " << 10 << " -> " << int_hash(10) << std::endl;

  std::cout << (int)((double)(-1 * 10 * std::log(0.001)) / ((double)(std::log(2) * std::log(2)))) << std::endl;

  // Bloom Filter
  BloomFilter bloomFilter = BloomFilter(1, 10);
  std::cout << bloomFilter.str() << std::endl;

}

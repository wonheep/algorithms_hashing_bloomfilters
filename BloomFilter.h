#include <stddef.h>

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

#ifndef _BLOOM_FILTER_H_
#define _BLOOM_FILTER_H_

class BloomFilter {
 public:
  BloomFilter(size_t bits, size_t expectedSetSize);
  void Insert(int x);
  void Insert(std::set<int> S);
  bool Query(int x);
  std::string str() const; // This may not be necessary. Added for local machine debugging.
  int number_of_hash_functions;
  int number_of_bits_for_filter;
  std::vector<bool> bit_array;
 private:
  std::vector<RandomMatrixHash> hash_functions_vector;
};  // BloomFilter

#endif  // _BLOOM_FILTER_H_
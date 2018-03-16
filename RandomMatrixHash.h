#ifndef _RANDOM_MATRIX_HASH_H_
#define _RANDOM_MATRIX_HASH_H_

#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <random>
#include <set>

class RandomMatrixHash {
    public:
        RandomMatrixHash(unsigned int m);
        size_t Hash(int key) const;
 	    unsigned int num_rows;
 	    unsigned int num_columns;
 	    std::vector<std::vector<int>> matrix;

}; // RandomMatrixHash

#endif  // _RANDOM_MATRIX_HASH_H_
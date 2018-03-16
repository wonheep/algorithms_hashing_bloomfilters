#include "RandomMatrixHash.h"
#include "gtest/gtest.h"
#include <set>
#include <complex>

using testing::Test;

#define NUM_TEST_CASES 100000
#define TABLE_SLOTS 256
#define ERROR_THRESHOLD .01

// Sanity check for entries in the random matrix.
// Create NUM_TEST_CASES random matrices, 
// then use EXPECT_NEAR(x, y, threshold) where
// threshold = ERROR_THRESHOLD to verify that each entry
// of the matrix is 1 with probability 1/2
TEST(RandomMatrixSanityCheck, EachBitFieldUniformlyGenerated) {
  RandomMatrixHash randomMatrixHash = RandomMatrixHash(NUM_TEST_CASES);

  int row_length = (int)randomMatrixHash.num_rows;
  int column_length = (int)randomMatrixHash.num_columns;

  int total_number_of_ones = 0;
  for( int i=0; i < row_length; i++ ) {
    for( int j=0; i < column_length; j++ ) {
      if (randomMatrixHash.matrix[i][j] == 1) {
        total_number_of_ones++;
      }
    }
  }
  EXPECT_NEAR(total_number_of_ones/(row_length*column_length), 0.5, ERROR_THRESHOLD);
  
}

// Sanity check for distribution of keys in the table.
// Create NUM_TEST_CASES integer keys and, for each slot in the table,
// count the number of times a key hashes to that slot. You can randomly
// generate the integer keys but I used 0, 1, ..., NUM_TEST_CASES.
// Then verify that hashing to each slot in the table is roughly equally
// likely using EXPECT_NEAR(x, y, threshold) where threshold = ERROR_THRESHOLD
TEST(RandomMatrixSanityCheck, SimpleUniformHashingAssumption) {
  RandomMatrixHash randomMatrixHash = RandomMatrixHash(NUM_TEST_CASES);
  std::set<int> keys_set;

  for (int i=0; i < NUM_TEST_CASES; i++) {
    keys_set.insert(randomMatrixHash.Hash(i));
  }

  int total_error = 0;
  double average_expected_number_of_hits = NUM_TEST_CASES / TABLE_SLOTS;
  for (int i=0; i < NUM_TEST_CASES; i++) {
    int number_of_hits = keys_set.count(randomMatrixHash.Hash(i));
    total_error += std::abs(number_of_hits - average_expected_number_of_hits);
  }

  double average_error = total_error / TABLE_SLOTS;
  ASSERT_LE(average_error, ERROR_THRESHOLD);
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
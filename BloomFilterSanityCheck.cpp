#include "BloomFilter.h"
#include "gtest/gtest.h"
#include <random>

using testing::Test;

#define NUM_TEST_CASES 10000000
#define SET_SIZE 10000
#define FILTER_SIZE 8 * SET_SIZE
#define ERROR_THRESHOLD .001
#define FALSE_POSITIVE_RATE_TARGET .0047

// Sanity check for no false negatives.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to both a bloom filter and
// to an STL data structure (I used a vector).
// Then check that every element inserted returns "true"
// when Query is called.
TEST(BloomFilterSanityCheck, NoFalseNegatives) {
  std::set<int> elements;
  for (int i=0; i < SET_SIZE; i++) {
    elements.insert(i);
  }

  BloomFilter bloomFilter = BloomFilter(FILTER_SIZE, SET_SIZE);
  bloomFilter.insert(elements);
  for (int i=0; i < SET_SIZE; i++) {
    ASSERT_EQ(bloomFilter.Query(elements[i]), true);
  }
}

// Sanity check for false positive rate.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to the bloom filter, then
// check NUM_TEST_CASES randomly generated keys
// not in the set of added elements to approximate
// the false positive rate.
TEST(BloomFilterSanityCheck, FalsePositiveRate) {
  std::vector<int> elements;
  for (int i=0; i < SET_SIZE; i++) {
    elements.push_back(i);
  }

  failed = 0;
  for (int i=0; i < NUM_TEST_CASES; i++) {
    if (!bloomFilter.Query(rand() % (NUM_TEST_CASES*NUM_TEST_CASES - SET_SIZE + 2) + SET_SIZE + 1)) {
      failed += 1;
    }
  }  

  ASSERT_LE(failed / NUM_TEST_CASES, ERROR_THRESHOLD);
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
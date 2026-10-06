#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;

// ==================== BASIC BIT OPERATIONS ====================

// Divide by 2 -> right shift
// Multiply by 2 -> left shift
// x % 2^k -> x & (2^k - 1), for x >= 0

int set_bit(int n, int i) {
  return n | (1 << i);
}

int clear_bit(int n, int i) {
  return n & ~(1 << i);
}

int flip_bit(int n, int i) {
  return n ^ (1 << i);
}

int check_bit(unsigned int n, int i) {
  return (n >> i) & 1;
}

bool is_even(int n) {
  return !(n & 1);
}

bool is_power_of_2(unsigned int n) {
  return n && !(n & (n - 1));
}

bool is_divisible_by_power_of_2(unsigned int n, int k) {
  return (n & ((1u << k) - 1)) == 0;
}

// ==================== LOWEST / HIGHEST SET BIT ====================

// Lowest set bit:
// n & -n
unsigned int lowest_set_bit(unsigned int n) {
  return n & -n;
}

// Remove the lowest set bit:
// n & (n - 1)
unsigned int remove_lowest_set_bit(unsigned int n) {
  return n & (n - 1);
}

// Set all bits at and below the highest set bit:
// n | (n - 1)
unsigned int fill_below_highest_bit(unsigned int n) {
  return n | (n - 1);
}

// ==================== COUNTING SET BITS ====================

// Brian Kernighan: O(number of set bits)
int count_set_bits(unsigned int n) {
  int count = 0;
  while (n) {
    n &= n - 1;
    count++;
  }
  return count;
}

// Built-in:
// __builtin_popcount(x)   -> int
// __builtin_popcountll(x) -> long long

// ==================== COUNT SET BITS IN [0, n] ====================

// Total number of set bits in binary representations of 0..n.
// For n >= 0.
// Uses the decomposition by highest set bit.
long long count_set_bits_upto_n(unsigned int n) {
  long long count = 0;

  while (n) {
    int x = 31 - __builtin_clz(n);  // x = floor(log2(n))

    // Number of 1s contributed by the highest bit among 0..2^x-1.
    count += 1LL * x * (1LL << (x - 1));

    // Highest bit contributes once for each number from 2^x to n.
    count += n - (1u << x) + 1;

    n -= 1u << x;
  }

  return count;
}

// ==================== Gray Code =====================
// gray(i) = i ^ (i >> 1);
// rev_gray(gray(i)) = i

int gray (int n) {
  	return n ^ (n >> 1);
}
int rev_gray (int g) {
  	int n = 0;
  	for (; g; g >>= 1) n ^= g;
  	return n;
}

// ==================== XOR / SWAP ====================

void swap_num(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}

// XOR toggle trick:
// If x can only be a or b, then:
// x = a ^ b ^ x

// ==================== FUNDAMENTAL IDENTITIES ====================

// a + b = (a ^ b) + 2(a & b)
// a + b = (a | b) + (a & b)

// a | b = (a ^ b) + (a & b)
// a ^ b = (a | b) ^ (a & b)

// a ^ (a & b) = (a | b) ^ b
// b ^ (a & b) = (a | b) ^ a
// (a & b) ^ (a | b) = a ^ b

// ==================== SET-BIT PARITY ====================

// Let:
// x = popcount(a)
// y = popcount(b)
// z = popcount(a ^ b)
//
// Since every common set bit disappears in XOR:
// z = x + y - 2 * popcount(a & b)
//
// Therefore:
// (x + y) and z have the same parity.
// If x + y is even -> z is even.
// If x + y is odd  -> z is odd.

// ==================== SUBTRACTION IDENTITIES ====================

// From:
// a - b = a + (-b)
// and the identities above:
//
// a - b = (a ^ (a & b)) - ((a | b) ^ a)
// a - b = ((a | b) ^ b) - ((a | b) ^ a)
// a - b = (a ^ (a & b)) - (b ^ (a & b))
// a - b = ((a | b) ^ b) - (b ^ (a & b))

// ==================== USEFUL BUILT-INS ====================

// C++20:
// std::has_single_bit(n)
// std::bit_ceil(n)
// std::bit_floor(n)
// std::rotl(x, k)
// std::rotr(x, k)
// std::countl_zero(x)
// std::countr_zero(x)
// std::countl_one(x)
// std::countr_one(x)

// GCC built-ins:
// __builtin_ffs(x)      -> 1-based index of least significant set bit
// __builtin_clz(x)      -> number of leading zeroes
// __builtin_ctz(x)      -> number of trailing zeroes
// __builtin_parity(x)   -> parity of popcount(x)

// Example:
// __builtin_ffs(0b000100101100) == 3
// __builtin_ctz(0b000100101100) == 2

// ==================== QUICK FACTS ====================
//
// n & (n - 1)      -> removes lowest set bit
// n & -n           -> isolates lowest set bit
// n | (n - 1)      -> sets all bits below the highest set bit
// n ^ (n - 1)      -> sets all bits from the lowest set bit upward
// n & ((1 << k)-1) -> n % 2^k, for n >= 0
// n >> k           -> floor(n / 2^k), for non-negative n
// n << k           -> n * 2^k, if no overflow
//
// a ^ a = 0
// a ^ 0 = a
// a ^ b ^ a = b
// XOR is associative and commutative.
//
// For a power of two n:
// n & (n - 1) = 0
//
// For a nonzero n:
// floor(log2(n)) = index of its highest set bit.

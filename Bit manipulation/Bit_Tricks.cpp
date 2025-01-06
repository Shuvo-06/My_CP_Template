#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;

// divide by 2 -> right shift 
// multiply by 2 -> left shift
// Modulo -> x&((1<<k)-1)

int set_bit(int n, int i) {
  return (n | (1 << i));
}

int clear_bit(int n, int i) {
  return (n & ~(1 << i));
}

int flip_bit(int n, int i) {
  return n ^ (1 << i);
}

// bit_ceil / bit_floor: round up/down to the next power of two
// built-in function - has_single_bit
bool is_power_of_2 (unsigned int n) {
  return (n <= 0) ? false : ((n & (n - 1)) == 0);
}

bool is_even(int n) {
  return (n & 1) != 1;
}

int check_bit(unsigned int n, int i) {
  return ((n >> i) & 1);
}

bool isDivisibleByPowerOf2(int n, int i) {
  return (n & ((1 << i) - 1)) == 0;
}

int count_set_bits (int n) {
  int count = 0;
  while (n){
    n = n & (n - 1);
    count++;
  }
  return count;
}
// only for c++ 20
/*
int count_set_bits_upto_n(int n) {
  int count = 0;
  while (n > 0) {
    int x = bit_width(n) - 1;
    count += x << (x - 1);
    n -= 1 << x;
    count += n + 1;
  }
  return count;
}
*/

int count_set_bits_upto_n(int n) {
  int count = 0;
  while (n > 0) {
    int x = static_cast<int>(std::log2(n));
    count += x * (1 << (x - 1));
    count += n - (1 << x) + 1;
    n -= (1 << x);
  }
  return count;
}
void swap_num(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

/*
**inequality theory
X --> number of set bits in a
Y -->  number of set bits in b
Z --> number of set bits in a ^ b
*/

/*
If (x + y) is even --> z is even
If (x + y) is odd --> z is odd
*/

/*
**the XOR trick
If x can only have two values - a ,b
Toggling --> x=a^b^x
*/

/*
**fundamental properties
A + B = (A ^ B) + 2 * (A & B)
A + B = (A | B) + (A & B)
*/

/*
**number of set bits in X using built-in function (TC-> O(1) )
If x in integer --> __builtin_popcount(x)
If x is long long integer --> __builtin_popcountll(x)
*/

// rotl / rotr: rotate the bits in the number
// countl_zero / countr_zero / countl_one / countr_one: count the leading/trailing zeros/ones  
// __builtin_ffs(int) finds the index of the first (most right) set bit (__builtin_ffs(0b0001'0010'1100) == 3)
// __builtin_clz(unsigned int) the count of leading zeros (__builtin_clz(0b0001'0010'1100) == 23)
// __builtin_ctz(unsigned int) the count of trailing zeros (__builtin_ctz(0b0001'0010'1100) == 2)
// __builtin_parity(x) the parity (even or odd) of the number of ones in the bit representation

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  
  return 0;
}

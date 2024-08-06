** checking even odd:
If (x&1 == 0)  even
else  odd

** checking if num is a power of 2
If (x&(x-1) == 0) yes
else no
Edge case  x=0

** k-th bit techniques
checking  If (n& (1<<k) != 0 ) -> set  else unset
toggling    n^(1<<k)
setting  n|(1<<k)
unsetting  x& ~(1<<k)

**dividing/multiplying/modulo by 2k
Dividing  number>>k
Multiplying  number<<k
Modulo  x&((1<<k)-1)

**swapping two values
x = x ^ y
y = x^y
x = x^y


**inequality theory
X  number of set bits in a
Y   number of set bits in b
Z  number of set bits in a ^ b

If (x + y) is even  z is even
If (x + y) is odd z is odd

**the XOR trick
If x can only have two values a ,b
Toggling  x=a^b^x

**fundamental properties
A+B = (A^B) + 2(A&B)
A+B = (A|B) + (A&B)

**number of set bits in X using built-in function (TC-> O(1) )
If x in integer  __builtin_popcount(x)
If x is long long integer  __builtin_popcountll(x)

//need a lot of work here :(
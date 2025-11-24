# Competitive Programming Equation List (Clean LaTeX Version)

All equations rewritten cleanly using proper LaTeX inline math so they render correctly on GitHub.

---

## Combinatorics — General

1. $$ \sum_{0 \le k \le n} \binom{n-k}{k} = F_{n+1} $$
2. $$ \binom{n}{k} = \binom{n}{n-k} $$
3. $$ \binom{n}{k} + \binom{n}{k+1} = \binom{n+1}{k+1} $$
4. $$ k \binom{n}{k} = n \binom{n-1}{k-1} $$
5. $$ \binom{n}{k} = \frac{n}{k} \binom{n-1}{k-1} $$
6. $$ \sum_{i=0}^n \binom{n}{i} = 2^n $$
7. $$ \sum_{i \ge 0} \binom{n}{2i} = 2^{n-1} $$
8. $$ \sum_{i \ge 0} \binom{n}{2i+1} = 2^{n-1} $$
9. $$ \sum_{i=0}^k (-1)^i \binom{n}{i} = (-1)^k \binom{n-1}{k} $$
10. $$ \sum_{i=0}^k \binom{n+i}{i} = \binom{n+k+1}{k} $$
11. $$ \sum_{r=1}^n r\binom{n}{r} = n 2^{n-1} $$
12. $$ \sum_{r=1}^n r^2 \binom{n}{r} = (n + n^2) 2^{n-2} $$
13. **Vandermonde:** $$ \sum_{k=0}^r \binom{m}{k} \binom{n}{r-k} = \binom{m+n}{r} $$
14. **Hockey-stick identity:** $$ \sum_{i=r}^n \binom{i}{r} = \binom{n+1}{r+1} $$
15. $$ \sum_{i=0}^k \binom{k}{i}^2 = \binom{2k}{k} $$
16. $$ \sum_{k=0}^n \binom{n}{k}\binom{n}{n-k} = \binom{2n}{n} $$
17. $$ \sum_{k=q}^n \binom{n}{k} \binom{k}{q} = 2^{n-q} \binom{n}{q} $$
18. $$ \sum_{i=0}^n k^i \binom{n}{i} = (k+1)^n $$
19. $$ \sum_{i=0}^n \binom{2n}{i} = 2^{2n-1} + \tfrac{1}{2} \binom{2n}{n} $$
20. $$ \sum_{i=1}^n \binom{n}{i} \binom{n-1}{i-1} = \binom{2n-1}{n-1} $$

---

If you want, I will continue cleaning **Number Theory**, **Geometry**, **Algebra**, **Tricks**, or the *entire blog post* in the same format.


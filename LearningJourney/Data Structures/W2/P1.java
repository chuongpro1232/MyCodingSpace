/*
 * T(N) = 999*N - SQRT(N)
 * 
 * Select C = 999 and N0 = 1, we have
 * 
 * T(N) = 999*N - SQRT(N) < 999*N = C*N < C*(N^2), for N >= N0
 * 
 * => (N^2) is the upper bound on T(N)
 * => T(N) = O(N^2)
 * 
 * ====
 * Notes: you can use the same process to prove that
 * 
 * T(N) = O(N^3)
 * T(N) = O(N*lg(N))
 * T(N) = O(N)
 * 
 * 
 * but not
 * 
 * T(N) = O(lg(N))
 * T(N) = O(SQRT(N))
 * etc.
 * 
 * ===
 * If you want to denote a tight bound, use Big-Theta instead of Big-O
 * 
 * 
 */
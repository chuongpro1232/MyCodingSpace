/*
 * 
 * 
 * 
 * 
 * int minProduct(int[] A)
 * N = length(A)
 * minProduct = INFINITY
 * for i from 0 to (N - 2)
 * for j from (i + 1) to (N - 1)
 * if (A[i] * A[j] < minProduct)
 * minProduct = A[i] * A[j]
 * return minProduct
 * 
 * Part 1
 * The number in curly braces on the right of each line is the execution times
 * of the respective statement on the left (for values like N-1, N-2, N+1, N+2,
 * I will just write N to simplify the calculations)
 * 
 * int minProduct(int[] A)
 * N = length(A) {1}
 * minProduct = INFINITY {1}
 * for i from 0 to (N - 2) {N}
 * for j from (i + 1) to (N - 1) {sum(N-i) for i = 0 to N}
 * if (A[i] * A[j] < minProduct) {sum(N-i) for i = 0 to N}
 * minProduct = A[i] * A[j] {sum(N-i) for i = 0 to N}
 * return minProduct {1}
 * 
 * The statement with largest number of execution are the statements in the
 * inner loop:
 * 3 * (sum(N - i)) for i from 0 to N
 * i = 0 => the element is N
 * i = 1 => the element is N - 1
 * ...
 * i = N-1 => the element is 1
 * i = N => the element is 0
 * So, the sum is: 1+ 2 + 3 + ... + (N-1) + N = N*(N+1)/2
 * Keep the most significant element and remove the constants, it is N^2
 * The big-O of above algorithm is O(N^2)
 * 
 * ----------------
 * Part 2
 * Because the array is sorted, we can calculate the min product in constant
 * time
 * 
 * There are three cases
 * 
 * Case #1: all array elements are >= 0
 * minProduct = A[0] * A[1]
 * 
 * Case #2: all array elements are <= 0
 * minProduct = A[N-1] * A[N-2]
 * 
 * Case #3: there are both negative and positive elements
 * minProduct = A[0] * A[N-1]
 * 
 * int fasterMinProduct(int[] A)
 * N = length(A)
 * if (A[0] >= 0) return A[0] * A[1]
 * if (A[N - 1] <= 0) return A[N - 2] * A[N - 1]
 * return A[0] * A[N-1]
 * 
 * 
 * 
 */
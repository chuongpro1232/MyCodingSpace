/*
 * // Approach 1: brute force
 * // Idea: try all possible pairs (A[i] + A[j])
 * 
 * 
 * closest = INFINITY
 * closestI = closestJ = -1
 * for i = 0 to N-2
 * for j = i+1 to N-1
 * if abs(A[i] + A[j]) < closest
 * closest = abs(A[i] + A[j])
 * closestI = i
 * closestJ = j
 * 
 * Complexity analysis:
 * The inner for loop executes at most (N - i - 1) times for each outer
 * iteration
 * i ranges from 0 to N-2
 * => The total execution times of the inner loop: T(N) = (N-1) + (N-2) + ... +
 * (N-(N-2)-1)
 * T(N) = (N-1) + (N-2) + ... + 2 + 1
 * T(N) = N*(N-1)/2
 * Remove the less significant components and multiplicative constants, we have
 * T(N) = O(N^2)
 * 
 * 
 * 
 * // Approach 2: sort then search
 * // Idea: after sorting, maintain two pointers: left and right
 * // initially, left = 0 and right = N-1
 * // calculate sum = A[left] + A[rigth]; there are three possible outcomes
 * // Outcome 1: sum = 0 => this is the closest sum to zero
 * // Outcome 2: sum > 0 => try to decrease the next sum: right--
 * // Outcome 3: sum < 0 => try to increase the next sum: left++
 * // eventually, left == right at which we stop
 * // during this process, always maintain the closet sum to zero
 * // Assumption: complexity of sorting O(N*lg(N))
 * 
 * sort(A)
 * closest = INFINITY
 * left = closestLeft = 0
 * right = closestRight = N-1
 * while left < right
 * if closest > abs(A[left] + A[right])
 * closest = abs(A[left] + A[right])
 * closestLeft = left
 * closestRight = right
 * if A[left] + A[right] == 0
 * break
 * else if A[left] + A[right] > 0
 * right--
 * else
 * left++
 * 
 * Complexity analysis of the while loop:
 * The distance between left and right is N
 * In each iteration, either left is increased or right is decreased by one
 * => the distance between left and right is decreased by one
 * => after at most N iterations, left and right will be equal
 * => complexity O(N)
 * Final complexity: O(N*lg(N)) + O(N) = O(N*lg(N))
 * 
 */
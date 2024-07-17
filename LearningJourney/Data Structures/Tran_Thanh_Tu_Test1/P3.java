/*
 the complexity of the above algorith is O(N^2) as
 for x =0 to n-1 {N+1}
    for y = x +1 to n-1 {N*(N+1)}
        sum up array entries A[x] through A[y] {N^2}
        store the result in B[x][y] {N^2}
    end for
end for
 The big-O of above algorithm is O(N^2)
 */
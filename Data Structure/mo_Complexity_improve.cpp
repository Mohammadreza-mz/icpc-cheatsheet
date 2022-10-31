// Complexity
// Sorting all queries will take O(QlogQ).

// How about the other operations? How many times will the add and remove be called?

// Let's say the block size is S.

// If we only look at all queries having the left index in the same block,
// the queries are sorted by the right index.
// Therefore we will call add(cur_r) and remove(cur_r) only O(N) times for all these queries combined.
// This gives O((N/S)*N) calls for all blocks.

// The value of cur_l can change by at most O(S) during between two queries.
// Therefore we have an additional O(SQ) calls of add(cur_l) and remove(cur_l).

// For S≈√N this gives O((N+Q)√N) operations in total.
// Thus the complexity is O((N+Q)F√N) where O(F) is the complexity of add and remove function.

// Tips for improving runtime
// Block size of precisely √N doesn't always offer the best runtime.
// For example, if √N=750 then it may happen that block size of 700 or 800 may run better.
// More importantly, don't compute the block size at runtime - make it const.
// Division by constants is well optimized by compilers.
// In odd blocks sort the right index in ascending order and in even blocks sort it in descending order.
// This will minimize the movement of right pointer,
// as the normal sorting will move the right pointer from the end back to the beginning at the start of every block.
// With the improved version this resetting is no more necessary.

bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
}
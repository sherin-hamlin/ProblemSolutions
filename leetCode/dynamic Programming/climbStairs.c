/*
File: climbStairs.c
Problem: Climbing Stairs (1 or 2 steps at a time)

Approach Used:
Dynamic Programming (Optimized Space)

- Base Cases:
      n = 1 → 1 way
      n = 2 → 2 ways
- Relation:
      ways(n) = ways(n-1) + ways(n-2)
- Use two variables to store previous two results.
- Iteratively compute up to n.

Time Complexity:
O(n)
- Single loop from 3 to n

Space Complexity:
O(1)
- Only three integer variables used.
*/

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int prev2 = 1;  // ways to reach step 1
    int prev1 = 2;  // ways to reach step 2
    int current;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}
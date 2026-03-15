// Approach: Each operation increases (N-1) elements by 1, so total sum increases by (N-1); if sum(A) % (N-1) != 0 or max(A) > sum/(N-1) then impossible, otherwise operations = sum/(N-1) | Time Complexity: O(N) per test case | Space Complexity: O(N)

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int solve (int N, int* A) {

    long long sum = 0;
    long long max = 0;

    for(int i = 0; i < N; i++)
    {
        sum += A[i];
        if(A[i] > max)
            max = A[i];
    }

    if(N == 1)
    {
        if(A[0] == 0)
            return 0;
        else
            return -1;
    }

    if(sum % (N - 1) != 0)
        return -1;

    long long k = sum / (N - 1);

    if(max > k)
        return -1;

    return k;
}

int main() {
    int T;
    scanf("%d", &T);

    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);

        int *A = (int *)malloc(sizeof(int)*(N));

        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        int out_ = solve(N, A);

        printf("%d\n", out_);

        free(A);
    }
}

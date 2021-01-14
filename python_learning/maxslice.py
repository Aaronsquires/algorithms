def solution(A):
    n = len(A)
    result = 0

    for a in range(n):
        for b in range(a, n):
            sum = 0
            for i in range(a, b + 1):
                sum += A[i]
            result = max(result, sum)
    return result

print(solution([5,-7,3,5,-2,4,1]))
print(solution([-1, -1, 1, -1, 1, 0, 1, -1, -1]))
print(solution([1, 1, -1, -1, -1, -1, -1, 1, 1]))
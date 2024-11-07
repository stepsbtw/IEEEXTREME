def power_of_three(N):
    if N == 1:
        return 0  # 3^0 = 1, so x = 0
    
    count = 0
    while N > 1 and N % 3 == 0:
        N //= 3  # Divide N by 3
        count += 1
    
    # If we have reduced N to 1, we found our x
    if N == 1:
        return count
    else:
        return -1  # N is not a power of 3

# Read input
N = int(input().strip())
# Get the result and print it
result = power_of_three(N)
print(result)

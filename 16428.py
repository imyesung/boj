A, B = map(int, input().split())

q, r = divmod(A, B)

if r < 0:
    if B > 0:
        q -= 1
        r += B
    else:
        q += 1
        r -= B

print(q)
print(r)

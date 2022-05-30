n = input()
ans1 = 0
ans2 = 0

for i in range(1, len(n)):
    if (n[i-1] == '0' and n[i] == '1'): ans1 += 1
for i in range(1, len(n)):
    if (n[i-1] == '1' and n[i] == '0'): ans2 += 1    
    
print(max(ans1, ans2))

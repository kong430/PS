n = input()

a = 0
b = 0

for i in range(0, len(n) // 2):
    a += int(n[i])

for i in range(len(n) // 2, len(n)):
    b += int(n[i])
    
if a == b:
    print("LUCKY")
else:
    print("READY")

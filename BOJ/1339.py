n = int(input())
words = [input() for _ in range(n)]
count = {}
answer = 0

for i, word in enumerate(words):
    for j, char in enumerate(word):
        if char in count:
            count[char] += pow(10, len(word) - j - 1)
        else:
            count[char] = pow(10, len(word) - j - 1)

count = dict(sorted(count.items(), key=lambda x:x[1], reverse=True))

su = 9
for num in count.values():
    answer += num * su
    su -= 1

print(answer)

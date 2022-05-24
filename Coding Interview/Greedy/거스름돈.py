remain = 1260
count = 0

coins = [500, 100, 50, 10]

for coin in coins:
    count += remain // coin
    remain %= coin
    
print(count)

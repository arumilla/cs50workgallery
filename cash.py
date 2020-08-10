import cs50 as cs

coins = 0
cents = 0
owed = 0

while True:
    owed = cs.get_float("Owed: ")
    if owed >= 0:
        break

cents = owed * 100

coins +=int(cents/25)
cents =(cents%25)

coins +=int(cents/10)
cents =(cents%10)

coins +=int(cents/5)
cents =(cents%5)

coins += int(cents/1)

print("Coins:", coins)   
#print(f'Coins:{coins:1.0f}')

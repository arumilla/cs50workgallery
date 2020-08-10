import cs50 as cs

while True:
    height = cs.get_int("Height: ")
    
    if height >= 1 or height <= 8:
        break
i = 1
for i in range(height + 1):
    c = height - i
    p = i
    while c > 0:
        print(" ", end = "")
        c -= 1
        
    while p > 0:
        print("#", end = "")
        p -= 1
    
    print("\n", end = "")

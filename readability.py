import cs50 as cs

def count_words(str):
    c = 1
    for x in range(len(str)):
        if str[x] == " ":
            c += 1
    return c

def count_letters(str):
    c = 0
    for x in range(len(str)):
        if str[x].isalpha():
            c += 1
    return c
    
def count_sentences(str):
    c = 0
    for x in range(len(str)):
        if str[x] == '.' or str[x] == '!' or str[x]== '?':
            c += 1
    return c

def main():
    text = cs.get_string("Text: ")
    
    le = count_letters(text)
    wo = count_words(text)
    se = count_sentences(text)
    
    d = 100/wo
    L = le * d
    S = se * d
    
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    if index < 1:
        print("Before Grade 1")
        
    elif index > 16:
        print("Grade 16+")
    
    else:
        print("Grade:",index)

main()
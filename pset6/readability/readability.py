from cs50 import get_string

def main():
    
    text = get_string("Text: ")
    letters = 0
    sentences = 0
    words = 1
    for i in range(0,len(text)):
        if text[i].isalpha():
            letters += 1
        elif text[i].isspace():
            words += 1
        elif text[i] == '.' or text[i] == '!' or text[i] == '?':
            sentences += 1
    
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    if index >= 16:
        print("Grade 16+")
    elif index < 16 and index >=1:
        print("Grade", index)
    else:
        print("Before Grade 1")
        
main()
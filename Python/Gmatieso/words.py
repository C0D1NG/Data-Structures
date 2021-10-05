"""python program to reverse the words of Given String
step1: split the input
step2: reverse the word
step3: Join the words
step4: Print the output
"""
item = "My name is Geoffrey"
words = item.split()
#creating an empty string where words will be appended 
rev_str1 = []
"""Going through the iteration of each word"""
for i in words:
    """using string slicing operation"""
    rev_str1.append(i[::-1])
#form string or sentence  by joining with a space 
sentence = " ".join(rev_str1)
print(sentence)

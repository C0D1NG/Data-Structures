"""python program to reverse the words of Given String
step1: split the input
step2: reverse the word
step3: Join the words
step4: Print the output
"""
str2 = input("Please Enter any word to be reversed:" + " ")
"""reverse the word and hold it in a variable name item"""
item = str2[::-1]
print("Your reversed word is:" + " "+ item)
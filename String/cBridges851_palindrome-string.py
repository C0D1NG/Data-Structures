# CB 2020-10-02 Palindrome String Checker

# CB 2020-10-02 Take in a string as input
def stringInput():
    originalString = input("Please input a string: ")
    return originalString
    
# CB 2020-10-02 Reverse the string, store it
def reverse(originalString):
    newString = ""

    index = len(originalString) - 1

    for i in range(len(originalString)):
        newString += originalString[index]
        index -= 1

    return newString

# CB 2020-10-03 Take the original and reversed string and compare
def compare(originalString, newString):
    # CB 2020-10-02 If the input string is the same as output, it's a palindrome
    if originalString == newString:
        print (originalString + " is a palindrome")
        return True

    # CB 2020-10-02 Else, it's not a palindrome
    else:
        print (originalString + " is not a palindrome")
        return False
    
# CB 2020-10-03 Call the above functions
originalString = stringInput()
newString = reverse(originalString)
isPalindrome = compare(originalString, newString)

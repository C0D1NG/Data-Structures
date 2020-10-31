import sys

def isPalindrome(str):
 
    
    for i in range(0, len(str)/2): 
        if str[i] != str[len(str)-i-1]:
            return False
    return True

def main():
    user_input = raw_input("Enter a string to see if it's a palindrome: ")

    print(isPalindrome(user_input))

if __name__ == "__main__":
    main()
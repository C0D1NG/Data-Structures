def isPalindrome(s):
    r = ''.join(reversed(list(s)))
    print(s,r)
    return s == r

s = input()
print(isPalindrome(s))
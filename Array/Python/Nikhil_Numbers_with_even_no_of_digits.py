# Given an array nums of integers, return how many of them contain an even number of digits.
# Input: nums = [5671,901,482,1771]
# Output: 5671
# 1771
# 2 

def count_digit(n):
        c=0
        while(n!=0):
            n=n//10
            c=c+1
        return c 
       
def findNumbers(nums):
    count=0
        
    for i in nums:
        digi_count=count_digit(i)
        if(digi_count%2==0):
            print(i)
            count=count+1   
    return count 


nums = [5671,901,482,1771]
print(findNumbers(nums))     
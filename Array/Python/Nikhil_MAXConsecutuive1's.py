def findMaxConsecutiveOnes(nums):
        c=0
        max_count=0
        for i in range(0,len(nums)):
            if nums[i]==1:
                c=c+1
                if(c>max_count):
                    max_count=c
            else:
                c=0
                continue
        return(max_count)  
        

l=[1,0,1,1,1,1]
print(findMaxConsecutiveOnes(l))
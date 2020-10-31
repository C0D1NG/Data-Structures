sum=0
n = int(input("Enter number of elements : ")) 
a = list(map(int,input("\nEnter the numbers : ").strip().split()))[:n] 
max_current=a[0]
max_global=a[0]
for i in range(1,n):
    max_current=max(a[i],a[i]+max_current)
    if(max_current>max_global):
        max_global=max_current
            

print(max_global)

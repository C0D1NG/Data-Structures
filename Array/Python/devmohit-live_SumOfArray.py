def sumOfArray(array)->int:
    summation=0
    for item in array:
        summation+=item
    return summation

if __name__ == "__main__":
    n=int(input("Enter the size of an array: "))
    array=list()
    for _ in range(n):
        array.append(int(input('Enter the number: ')))
    
    print('Array is : ',array)
    print('Sum of elements of array is: ',sumOfArray(array))

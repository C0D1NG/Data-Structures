def gcd(a,b)-> int:
    if (b == 0):
         return a
    return gcd(b, a%b)

if __name__ == "__main__":
    a=int(input('Enter first number : '))
    b=int(input('Enter first number : '))
    print('GCD of {} and {} is {}'.format(a,b,gcd(a,b)))
"""
Everything except 0 and 0.0 will be treated as True
When it comes to sequence types any sequence with at least an item is treated as True
Empty sequence are treated as False
bool() function (Built-in) can be used to check the truthiness of a value e.g bool([]) = False

any(), all()
any() --> takes a collection and returns True if at least one item is True
e.g x = [True, False, True], any(x) = True
e.g y = [False, False, False], any(y) = False

all() --> takes a collection and returns True if all items are True
e.g x = [True, False, True], all(x) = False
e.g y = [True, True, True], all(y) = True

Conditional Statements:
    if, elif, else
    a, b, c = 10, 20, 30
    if a>b and a>c:
        print(f"{a} is the greatest")
    elif b>a and b>c:
        print(f"{b} is the greatest")
    else:
        print(f"{c} is the greatest")

    Single line if else statement
    n = int(input())
    print("Even" if n%2==0 else "Odd")

Number of digits:
    num = 123456
    print(len(str(num))) # 6

    digit_count = 0
    temp = num
    while >0:
        digit_count += 1
        temp = temp//10
    print(digit_count) # 6 

Conversions:
    int to str --> use str()
    str to int --> use int() 

    binary_string to int --> use int(binary_string, 2)
    int to binary_string --> use bin(int)

    octal_string to int --> use int(octal_string, 8)
    int to octal_string --> use oct(int)

    hex_string to int --> use int(hex_string, 16)
    int to hex_string --> use hex(int)

Loops:
    1. while
    2. for

    1. while loop
        --> initialization, condition, update 
    i = 0
    while i<10:
        print(i, end = "\n")
        i+=1
    print("Done")

    2. for loop
        --> works on collections, iterables
        --> syntax --> for <variable> in <collection>:
    string = "Hello, World!"
    for i in string:
        print(i , '-->', ord(i))        print(i, end = "\n")

        Range
            --> range(start, stop, step)
            --> built-in function
            --> range() function is used to generate integers from start to stop
            --> range() function is used to generate integers from start to stop
            --> Default values of start, stop and step are 0, 1 and 1 respectively
            --> range() function always excludes the stop value (end bound)

        for i in range(10): # start = 0, stop = 10, step = 1
            print(i, end = " ") # 0 1 2 3 4 5 6 7 8 9

        for in in range(10,20) # start = 10, stop = 20, step = 1
            print(i, end = " ") # 10 11 12 13 14 15 16 17 18 19

        for i in range(10,20,2): # start = 10, stop = 20, step = 2
            print(i, end = " ") # 10 12 14 16 18

        Generating number in backwards
        for i in range(20,10,-1): # start = 20, stop = 10, step = -1
            print(i, end = " ") # 20 19 18 17 16 15 14 13 12 11

        a,b = map(int, input().split())
        for i in range(a, b+1): # start = a, stop = b+1, step = 1
            print(i, end = " ") # a ... b
    Value base looping:
        names = ["John", "Jane", "Joe", "Jill"]
        for name in names:
            print(name, end = " ")

    Index based looping:
        names = ["John", "Jane", "Joe", "Jill"]
        for i in range(len(names)):
            print(names[i], end = " ")

        for i in range(len(names)-1, -1,-1): #printing int reverse
            print(names[i], end = " ")

    Else for loops:

Different types of imports:
    import module:
        import math
        print(math.sqrt(25)) # 5

    import module as elias_name
        import math as m
        print(m.sqrt(25)) # 5

    from module import *
        from math import *
        print(sqrt(25)) # 5

    from module import member1, member2
        from math import sqrt, gcd, lcm
        print(sqrt(25)) # 5
        print(gcd(1,2,3,4,5)) # 1
        print(lcm(1,2,3,4,5)) # 60

        from math import sqrt as s, gcd as g, lcm as l (This is not suggested)
        print(s(25)) # 5
        print(g(1,2,3,4,5)) # 1
        print(l(1,2,3,4,5)) # 60
        
"""
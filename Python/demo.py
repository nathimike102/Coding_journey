""" input from the user
input() --> built in function which will take input from the user
		--> only reads as a string, type conversion can be applied to change the string to desired type

a = int(input())
b = int(input())
c = a+b

print(a+b, {a,b,c}, [a,b,c]) #by default python uses space as a separator
print(a,b,c,sep=" Nathi ") 
print(a,b,c,sep="\n") # using new line as a separator

print(a,b,c, end=" ") # by default end is newline character
print("Mike")

a,b,c = map(int, input().split()) #for input in the same line
# input	--> for taking as single input string '10 20 30'
# split	--> '10 20 30' --> ['10', '20', 30]
# map	--> converting those strings into integers (int) and assign them to a,b,c respectively
# 7:42:37	--> h, m, s = map(int, input(), split(':'))
print(a+b+c)

a, b = map(int, input().split())
c = a + b

#general way (comma separated way) --> not that efficient
print("The sum of",a,"and",b,"is",c)

#using percentage format
print("Sum of %d and %d is %d"%(a,b,c))

#using .format() method on strings
print("The Sum of {} and {} is {}".format(a,b,c))

#using formatted string (f strings since 3.6), literal string interpolation
print(f"Sum of {a} and {b} is {c}")
"""
a = 12.734567

#using % format
print("%.4f"%(a))

#using .format() method
print("{:.3f}".format(a))

#using f strings
print(f"{a:.2f}")
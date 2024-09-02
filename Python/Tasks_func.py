#TASKS
# def hello():
#     """
#     Prints Hello World
#     >>> hello()
#     Hello World
#     """
#     print("Hello World")

# def alien_hello():
#     """
#     Prints We Aliens Welcome You Humans to Our Planet Mars
#     >>> alien_hello()
#     WE Aliens Welcome You Humans to Our Planet Mars
#     """
#     print("WE Aliens Welcome You Humans to Our Planet Mars")

# def location(name, city, country):
#     """
#     Prints Name from City, Country
#     >>> location('Nkosinathi Sibanda', 'Kakinada', 'India')
#     Nkosinathi Sibanda from Kakinada, India
#     """
#     print(f"{name} from {city}, {country}")

# def multiply_add(num1, num2, num3):
#     """
#     Prints num1 * num2 + num3
#     >>> multiply_add(3, 2, 1)
#     7
#     """
#     print(num1 * num2 + num3)

# def print_numbers(start, stop):
#     """
#     Prints numbers from start to stop inclusive
#     >>> print_numbers(1, 5)
#     1
#     2
#     3
#     4
#     5
#     """
#     for i in range(start, stop+1):
#         print(i)

# def multiplication_table(n, r):
#     """
#     Print the multiplication table of n up to r terms(from 1)
#     >>> multiplication_table(3, 5)
#     3 * 1 = 3
#     3 * 2 = 6
#     3 * 3 = 9
#     3 * 4 = 12
#     3 * 5 = 15
#     """
#     for i in range(1, r+1):
#         print(f"{n} * {i} = {n * i}")

# def print_neat(a, b, c):
#     """
#     Prints all numbers from a to b with difference of c
#     >>> print_neat(1, 20, 3)
#     1
#     4
#     7
#     10
#     13
#     16
#     19
#     """
#     for i in range(a, b+1, c):
#         print(i)

# def grades(percentage):
#     """
#     Print the character grade based on the percentage.
#     >>> grades(100)
#     O
#     >>> grades(90)
#     O
#     >>> grades(80)
#     A
#     >>> grades(70)
#     B
#     >>> grades(60)
#     C
#     >>> grades(50)
#     D
#     >>> grades(35)
#     E
#     >>> grades(20)
#     F
#     """
#     if percentage >= 90:
#         print("O")
#     elif percentage >= 80:
#         print("A")
#     elif percentage >= 70:
#         print("B")
#     elif percentage >= 60:
#         print("C")
#     elif percentage >= 50:
#         print("D")
#     elif percentage >= 35:
#         print("E")
#     else:
#         print("F")

# def uni_print(str, num):
#     """
#     Prints all the characters in the given string whose unicode code point value is less than given number
#     >>> uni_print("Hello World", 100)
#     H --> 72
#       --> 32
#     W --> 87
#     """
#     for i in str:
#         if ord(i) < num:
#             print(i, "-->", ord(i))

# def print_n_times(n, name):
#     """
#     Prints name n times
#     >>> print_n_times(3, "Nathi")
#     Nathi
#     Nathi
#     Nathi
#     """
#     for i in range(n):
#         print(name)

# def report(name, score1, score2, score3, score4, score5):
#     """
#     Calculates the total and percentage of five scores
#     >>> report("Nkosinathi", 57, 67, 77, 87, 97)
#     Report for Nkosinathi
#     Total is: 385 and Percentage is: 77.00%
#     """
#     total = score1 + score2 + score3 + score4 + score5
#     print(f"Report for {name}")
#     print(f"Total is: {total} and Percentage is: {total / 5:.2f}%")

# def sum_of_max_min(str1, str2, str3):
#     """
#     Prints the sum of UNICODE CODE POINT VALUES of the maximum and minimum characters in each string.
#     >>> sum_of_max_min("Hello", "World", "Python")
#     For string Hello: 111 + 72 = 183
#     For string World: 114 + 87 = 201
#     For string Python: 121 + 80 = 201
#     """
#     min_uni1, min_uni2, min_uni3 = ord(min(str1)), ord(min(str2)), ord(min(str3))
#     max_uni1, max_uni2, max_uni3 = ord(max(str1)), ord(max(str2)), ord(max(str3))

#     print(f"For string {str1}: {max_uni1} + {min_uni1} = {max_uni1 + min_uni1}")
#     print(f"For string {str2}: {max_uni2} + {min_uni2} = {max_uni2 + min_uni2}")
#     print(f"For string {str3}: {max_uni3} + {min_uni3} = {max_uni3 + min_uni3}")


# def factor_of(num1, num2):
#     """
#     Prints YES if num2 is a factor of num1, otherwise prints NO
#     >>> factor_of(10, 5)
#     YES
#     >>> factor_of(10, 6)
#     NO
#     """
#     print("YES") if num1 % num2 == 0 else print("NO")  

# def sum_of(num1, num2, num3):
#     """
#     Returns the sum of num1, num2 and num3
#     >>> sum_of(11, 22, 33)
#     66
#     """
#     return num1 + num2 + num3

# def simple_interest(p, r, t):
#     """
#     Returns the simple interest
#     >>> simple_interest(100, 10, 2)
#     20.0
#     """
#     return (p * r * t) / 100

# def factor_of_r(n, i):
#     """
#     Returns true if i is a factor of n
#     >>> factor_of_r(10, 5)
#     True
#     >>> factor_of_r(10, 3)
#     False
#     """
#     return n % i == 0


# def simple_cal(a, b, choice):
#     """
#     Returns the result of a simple arithmetic operation
#     >>> simple_cal(10, 5, 1)
#     15
#     >>> simple_cal(10, 5, 2)
#     5
#     >>> simple_cal(10, 15, 2)
#     5
#     >>> simple_cal(10, 5, 3)
#     50
#     """
#     if choice == 1:
#         return a + b
#     elif choice == 2:
#         return abs(a - b)
#     elif choice == 3:
#         return a * b

# def factors(n):
#     """
#     Returns all the factors of n
#     >>> factors(10)
#     4
#     >>> factors(600)
#     24
#     """
#     count = 0
#     for i in range(1, n+1):
#         if n % i == 0:
#             count+=1
#     return count
    
# def proper_factor_sum(n):
#     """
#     Returns the proper factor sum of n
#     >>> proper_factor_sum(10)
#     18
#     >>> proper_factor_sum(600)
#     1860
#     """
#     factor_sum = 0
#     for i in range(1, n+1):
#         if n % i == 0:
#             factor_sum+=i
#     return factor_sum

# def is_prime(n):
#     """
#     Returns true if n is prime, otherwise false
#     >>> is_prime(31)
#     True
#     >>> is_prime(10)
#     False
#     """
#     if n < 2 :
#         return False
#     if n == 2 or n == 3:
#         return True
#     if n % 2 == 0 or n % 3 == 0:
#         return False
#     for i in range(5, int(n**0.5) + 1, 6):
#         if n % i == 0 or n % (i + 2) == 0:
#             return False
#     return True

# SET 1:

# question 1:
def is_eight(n):
    return sum(int(i) for i in str(n)) == 8
eight_list = [i for i in range(250, 351) if is_eight(i)]
print(eight_list)

# question 2:
def is_prime(n):
    return len([i for i in range(1, n+1) if n%i==0])==2
prime_list = [i for i in range (1, 51) if is_prime(i)]

# question 3:
def is_palindrome(n):
    return str(n) == str(n)[::-1]
prime_palindrome_list = [i for i in range(1, 1001) if is_prime(i) and is_palindrome(i)]
print(prime_palindrome_list)

# question 4:
def factor_sum(n):
    return sum(i for i in range(1, n) if n%i==0) > n
greater_factor = [i for i in range(1, 101) if factor_sum(i)];
print(greater_factor)

# SET 2:

nums = [14, 9, 13, 17, 26, 32, 43]

# question 1:
even_nums = [nums[i] for i in range(len(nums)) if nums[i]%2==0]
print(even_nums)

# question 2:
greater_half = [nums[i] for i in range(len(nums)) if nums[i] > max(nums)/2]
print(greater_half)

# question 3:
greater_avg = [nums[i] for i in range(len(nums)) if nums[i] < sum(nums)/len(nums)]
print(greater_avg)

# SET 3

cities = ['berlin', 'tokyo', 'palermo', 'nairobi', 'denver', 'rio', 'lisbon', 'stockholm', 'bogota', 'helsinki']

# question 1:
len5 = [city for city in cities if len(city) <= 5]
print(len5)

# question 2: 
def max_char(city):
    return max()
max_r = [city for city in cities if max_char(city) == 'r']
print(max_r)
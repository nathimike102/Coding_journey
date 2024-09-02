"""
Slicing in Lists / strings:
    slicing is a process of getting sub-lists / sub-strings from a list or a string
    slicing operation always return a new list or a new string
    slicing is donne using indexes
    list_names[start_index: stop_index: step_size]
    stop_index is always excluded
    defaults: start_index = 0, stop_index = len(list_name), step_size = 1

    #    0   1   2   3   4   5   6   7   8   9
    x = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    #   -10 -9  -8  -7  -6  -5  -4  -3  -2  -1

    slice1 = x[1::]
    print(slice1) # [20, 30, 40, 50, 60, 70, 80, 90, 100], start_index = 1, stop_index = len(list_name), step_size = 1

    slice2 = x[::]
    print(slice2) # [10, 20, 30, 40, 50, 60, 70, 80, 90, 100], start_index = 0, stop_index = len(list_name), step_size = 1

    slice3 = x[:3]
    print(slice3) # [10, 20, 30], start_index = 0, stop_index = 3, step_size = 1

    slice4 = x[1:3]
    print(slice4) # [20, 30], start_index = 1, stop_index = 3, step_size = 1

    slice5 = x[::2]
    print(slice5) # [10, 30, 50, 70, 90], start_index = 0, stop_index = len(list_name), step_size = 2

    slice6 = x[-4:-1]
    print(slice6) # [50, 60, 70], start_index = -4, stop_index = -1, step_size = 1

    slice7 = x[-1:-4:-1]
    print(slice7) # [100, 90, 80], start_index = -1, stop_index = -4, step_size = -1


Comprehensions:
    ####
        import random
        ages = []
        for i in range(10):
            ages.append(random.randint(1,100));
        print(ages)

        child, adult, old = [], [], []
        for age in ages:
            if age <= 15:
                child.append(age)
            elif age >= 50:
                old.append(age)
            else:
                adult.append(age)

        print(child, adult, old, sep="\n")

    ####
        numbers = [10, 20, 30, 40, 50]
        squares = [num ** 2 for num in numbers]
        print(squares) # [100, 400, 900, 1600, 2500]

        names = ['walter', 'jesse', 'skylerr', 'saul']
        lengths = [len(name) for name in names]
        print(lengths) # [6, 5, 7, 4]

        new_names = [each_name for each_name in names if 'r' in each_name]
        print(new_names) # ['walter', 'skylerr']

    ####
        from math import sqrt
        names = ['walter', 'jesse', 'skylerr', 'saul']
        new_names = [each_name for each_name in names if each_name[0] == 's']
        print(new_names) # ['skylerr', 'saul']

        x = [9, 16, 25, 36]
        new_list = [sqrt(num) for num in x]
        print(new_list) # [3.0, 4.0, 5.0, 6.0]

        def cube(x):
            return x**3

        nums = [10,20,30]
        new_ = [cube(i) for i in nums]
        print(new_) # [1000, 8000, 27000]

    ####
        y = [chr(i) for i in range(97,123)]
        print(y)

        n = int(input("Enter a number: "))
        factors = [i for i in range(1, n+1) if n%i==0]
        print(factors)

    ####
        def is_prime(n):
            return len([i for i in range (1, n+1) if n%i == 0]) == 2

        primes = [i for i in range(2, 100) if is_prime(i)]
        print(primes)

"""
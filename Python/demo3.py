"""
Functions:
    YOu dont need to mention its return type.

    #void function
    def add_two(a, b):
        print(a+b)

    #function with return value
    def add_two(a, b):
        return a + b

    #TASK
    def location(city, country, continent):
        #Prints city is in country, which is in continent
        #>>> location('Mumbai', 'India', 'Asia')
        #Mumbai is in India, which is in Asia
        #>>> location('Paris', 'France', 'Europe')
        #Paris is in France, which is in Europe
        #>>> location('Berlin', 'Germany', 'Europe')
        #Berlin is in Germany, which is in Europe

        print(f"{city} is in {country}, which is in {continent}")

    #Keyword Arguments
    location(continent = 'Asia', country = 'India', city = 'Mumbai')

    ### No position argument should follow a keyword a argument
    e.g location(country = 'India', city = 'Mumbai','Asia') will give syntax error

    Default values to Parameters:
        def location(city, country, continent = 'Asia'):
            print(f"{city} is in {country}, which is in {continent}")

        location('Mumbai', 'India') # Mumbai is in India, which is in Asia (Function can be called with or without continent since it is default value)
        location('Berlin', 'Germany', 'Europe') # Berlin is in Germany, which is in Europe (Calling function with continent, we can change the default value of continent to Europe)

        num = "123"
        print(int(num)) # 123
        print(int(num, 8)) # 83

    def getInt():
        return int(input("Enter a number: "))

    a=getInt()
    b=getInt()
    print(a+b)


Lists in Python
    Dynamic Arrays
    Mutable
    Can store any data type
    Lists are separated by commas
    my_list = [10, 20, 30, 40]
                0   1   2   3
    using indexes you can access list elements
    x = [10,20,30,40]
    print(type(x)) #<class 'list'>
    len() function gives the number of elements in the list
    print(len(x)) # 4

    Accessing list elements
        0   1   2    3
    x = [10, 20, 30, 40]
        -4  -3  -2   -1

    indexing can be positive, starting from 0 (left to right)
    indexing can be negative, starting from -1 (right to left)
    list_name.methodname()

Methods for Adding more elements to the list:
    append()
    insert()
    extend()

    ##Append:
        used to add one element at a time to an existing list
        list_name.append(element)
        always add the new element at the end of the list

        x = []
        x.append(10) # [10]
        x.append(20) # [10, 20]
        x.append('Hello') # [10, 20, 'Hello']

    for reading inputs separated with multiple lines
        n = int(input("Enter size of the array: "))  
        x = []
        for i in range(n):
            ele = int(input())
            x.append(ele)
        print(x)

        Enter size of the array: 5
        12
        13
        14
        15
        16
        [12, 13, 14, 15, 16]

    for reading inputs in single line
        n = int(input("Enter size of the array: "))
        x = list(map(int, input().split()))
        x = list(map(int, input().split()))[:n] # will read only n elements
        # x = [int(i) for i in input().split()]
        print(x)


    ##Insert:
        insert an element at a given index
        takes two values:
            1. Index
            2. Element
        x = [10, 20]
        x.insert(1,'Hello')
        x.insert(1,30)
        print(x) # [10, 30, 'Hello', 20]

    ##Extend:
        extend takes an iterable and appends every element of iterable to the list
        list_name.extend(iterable)
    marks = [45, 67]
    new_marks = [79, 84, 92]
    marks.extend(new_marks)
    print(marks) # [45, 67, 79, 84, 92]
    
    vowels = []
    vowels.extend('aeiou')
    print(vowels) # ['a', 'e', 'i', 'o', 'u']

Methods for Deleting elements from the list:
    pop()
    remove()
    clear()

    ###pop():
        removes and returns the last element of the list by default
        It's possible to specify the index of the element to be removed
        pop() on an empty list will return an error

        nums = [10, 20, 30, 40, 50]
        nums.pop() # 50
        nums.pop(0) # 10

        # Use list as a stack
        # append() --> Push()
        # pop() --> Pop()

            stack = []
            stack.append(10)
            stack.append(20)
            stack.append(30)
            print(stack) # [10, 20, 30]
            print(stack.pop()) # 30
            recent_element = stack.pop()
            print(recent_element) # 20
            if stack:
                print("Not empty")
            else:
                print("Empty")

    ###remove():
        Element based removal
        Removes the first occurrence of the element from left
        
        nums = [10, 20, 30, 40, 50, 10]
        nums.remove(10)
        print(nums) # [20, 30, 40, 50, 10]
        nums.remove(10)
        print(nums) # [20, 30, 40, 50]
        nums.remove(100) # ValueError: list.remove(x): x not in list

        nums = [10, 20, 30, 40, 50, 10]
        while 10 in nums:
            nums.remove(10)
        print(nums)

    ###clear():
        Deletes all the elements from the list thus by leaving empty list

        nums = [10, 20, 30, 40, 50, 10]
        nums.clear()
        print(nums) # []

In-Place utility operations:
    reverse()
    sort()

    reverse():
        reverses the list in-place
        return type is None

        nums = [10, 20, 30, 40, 50]
        print(f"Before reverse: {nums}") # before reverse: [10, 20, 30, 40, 50]
        nums.reverse() # reverses the list in-place
        print(f"After reversing: {nums}") # After reversing: [50, 40, 30, 20, 10]

    sort():
        sorts the given list in-place in ascending order
        setting reverse = True will sort in descending order

        nums = [5, -2, 4, 67, 4]
        nums.sort()
        print(nums) # [-2, 4, 4, 5, 67] in ascending order
        nums.sort(reverse=True)
        print(nums) # [67, 5, 4, 4, -2] in descending order

        names = ['skylerr', 'walter', 'jesse', 'saul']
        names.sort()
        print(names) # ['jesse', 'saul', 'skylerr', 'walter']
        names.sort(key=len)
        print(names) # ['saul', 'walter', 'jesse', 'skylerr']

        def get_vowel_count(string):
            vowels = 'aeiou'
            count = 0
            for i in string:
                if i in vowels:
                    count += 1
            return count

        names = ['skylerr', 'waaalter', 'jesse', 'siaul']
        names.sort(key=get_vowel_count)
        print(names) # ['skylerr', 'jesse', 'siaul', 'waaalter']

    copy():
        is used to return a shallow copy of the list

        Deep copy vs Shallow copy:
            Deep copy: creates a new object with the same values
            Shallow copy: creates a new object with the same reference

        names = ['skylerr', 'waaalter', 'jesse', 'siaul']
        new_names = names
        new_names.pop()
        print(new_names) # ['skylerr', 'waaalter', 'jesse']
        print(names) # ['skylerr', 'waaalter', 'jesse']
        print(id(names), id(new_names)) # same id

        names = ['skylerr', 'waaalter', 'jesse', 'siaul']
        new_names = names.copy()
        new_names.pop()
        print(new_names) # ['skylerr', 'waaalter', 'jesse']
        print(names) # ['skylerr', 'waaalter', 'jesse', 'siaul']
        print(id(names), id(new_names)) # different id

    index(), count():
        returns the index of the first occurrence of the element
        Raises ValueError if the element is not in the list

        nums = [10, 20, 30, 40, 50, 10]
        print(nums.index(10)) # 0
        print(nums.index(100)) # ValueError: 100 is not in list

        print(nums.count(10)) # 2
        print(nums.count(100)) # 0

"""
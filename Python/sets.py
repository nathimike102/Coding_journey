"""
Tuples
    immutable, cannot be changed

Sets
    Sets are a data structure in Python that store a collection of unique elements.
    They are unordered and mutable, meaning that elements can be added or removed from the set.
    Sets are defined using curly braces {} or the set() constructor.
    They are commonly used for tasks that involve checking for membership, removing duplicates, and performing set operations such as union, intersection, and difference.
    set elements cant be of mutable types, which means
        you can have a set of integers, set of strings, set of floats
        but you cannnot have a set of lists, set of sets
        as lists and sets are mutable

    #set of integers
    s1 = {10, 20, 30, 10, 30, 40}
    print(s1, type(s1)) # {40, 10, 20, 30} <class 'set'>

    #set of strings
    s2 = {"abc", "kxs", "fewf", "abc"}
    print(s2, type(s2)) # {'fewf', 'abc', 'kxs'} <class 'set'>

    #set of lists
    s3 = {[10, 20, 30], [30, 40]} # TypeError: unhashable type, cannot be used in a set
    print(s3, type(s3))

    c1 = "reactjs"
    c2 = "mongodb"
    c3 = "nodejs"
    c4 = "blockchain"

    s1 = (c1,c2)
    s2 = (c3,c4)
    s3 = (c1,c3)
    s4 = (c2,c4)
    s5 = (c1,c2)
    s6 = (c3,c4)

    courses = {s1, s2, s3, s4, s5, s6}
    print(courses) # {('mongodb', 'blockchain'), ('reactjs', 'nodejs'), ('nodejs', 'blockchain'), ('reactjs', 'mongodb')}
    print(len(courses)) # 4 
    
set.add()
    
    s1 = {10, 20, 30}
    s1.add(40)
    s1.add(10)
    s1.add(50)
    print(s1) # {40, 10, 50, 20, 30}

    s1 = set()
    s2 = {}
    print(type(s1)) # <class 'set'> 
    print(type(s2) )# <class 'dict'>
    
    n = int(input("Enter number of straight lines: "))
    set_of_start_points = set()
    set_of_end_points = set()
    for i in range(n):
        start_point = tuple(map(int, input().split()))
        end_point = tuple(map(int, input().split()))
        set_of_start_points.add(start_point)
        set_of_end_points.add(end_point)

    print(set_of_start_points,len(set_of_start_points))
    print(set_of_end_points,len(set_of_end_points))

set() function:
    set() coneverts other iterables into a set
    string list, range(), tuple can be converted into a set

    c = ["C", "C++", "Java", "Python", "Java", "C++"]
    s = set(c)
    print(s) # {'C', 'C++', 'Java', 'Python'}
    
    #converting a string into a set
    x = "aabbccaabbccdd"
    s = set(x)
    print(s) # {'d', 'a', 'c', 'b'}
    
set.remove()
    used to remove an element from set
    element based removal
    if the element is not present in the set, an error will be raised

    s = {10, 20, 30}
    s.remove(20)
    print(s) # {10, 30}
    s.remove(100)
    print(s) # KeyError: 100
    
set.discard()
    used to remove an element from set only if exits
    if the element is not present in the set, no error will be raised
    
    s = {10, 20, 30, 100}
    s.discard(100)
    print(s) # {10, 20, 30}, 100 is removed as it exits in the set
    s.discard(1000)
    print(s) # {10, 20, 30} 1000 is not present in the set, so no error is raised
    
    # Finding out whether a string is a Pangram or not using sets
        pangram is a string that contains all the letters of the alphabet atleast once
    
        import string
        print(string.ascii_lowercase) # 'abcdefghijklmnopqrstuvwxyz'
    
        str = input().lower()
        x = set(str)
        x.discard(" ")
        if len(x) == 26:
            print("Pangram")
        else:
            print("Not Pangram")
    
    
    # union() ---> Set A + Set B
    # intersection() ---> Set A * Set B, commom elements in both sets
    # difference(A, B) ---> Set A - Set B, elements in Set A but not in Set B
    # difference(B, A) ---> Set B - Set A, elements in Set B but not in Set A
    # symmetric_difference() ---> Set A ^ Set B, elements in Set A or Set B but not both
                           ---> union of A Diff B and B diff A
    
    s1 = {10, 20, 30}
    s2 = {30, 40, 50}
    print(s1.union(s2)) # {10, 20, 30, 40, 50}
    print(s1.intersection(s2)) # {30}
    print(s1.difference(s2)) # {10, 20}
    print(s2.difference(s1)) # {40, 50}
    print(s1.symmetric_difference(s2)) # {10, 20, 40, 50}

    s1 = {10, 20, 30}
    s2 = {30, 40, 50}
    s1.intersection(s2) # Birth a new set
    s1.intersection_update(s2) # Update the set 1 with the intersection of set 1 and set 2
"""

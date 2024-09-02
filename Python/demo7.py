"""
Dictionaries:
    used to store data in key-value pair forms
    keys can be of immutable types only
    Do not allow duplicate values
    Using key we can access values
    Key value pair must be written in the following form
        key-value
        e.g {"J.K Rowling" : "Harry Potter", "Abdul Kalam" : "Wings on fire" }
        Above is an example of a string : string dictionary
        e.g {"a" : 1, "b" : 2, "c" : 3}
        Above is an example for string : int dictionary

Different ways to create a dictionary in python:

    Creating a dictionary on own:
        # string : int mapping
        d = {"sachin" : 100, "kohli" : 80, "ponting" : 78}
        print(d) 
        print(type(d))
        #accesing values
        print(d["sachin"]) #gives the value associated with sachin
        print(d["kohli"])
    
    Constructing from an empty dictionary:
        d = {} # empty dictionary
        d["sachin"] = 100 # inserts a new key-value pair "sachin" : 100
        d["kohli"] = 80
        d["kohli"] = 110 # does not have duplicate strings, rather updates the existing key to new value
        print(d) # {'sachin': 100, 'kohli': 190}
        
        no_of_pairs = int(input("Enter number of pairs: "))
        d = {}
        for i in range(no_of_pairs):
            key = input("Enter a batsman name: ")
            value = int(input("Enter number of centuries score: "))
            d[key] = value
        print(d)
        
    Constructing a dictionary from existing data:
        batsmen = ["sachin", "kohli", "ponting"]
        centuries = [100, 80, 50]
        d = {}
        for i in range(len(batsmen)): # index based
            d[batsmen[i]] = centuries[i]
        print(d)
        
    Using dict() function to create dictionaries:
        dict() is the built-in function to create dictionary
        dict() expects to iterate of iterables where inner iterable are of length 2
        
        data = [["sachin", 100], ["kohli", 80], ["ponting", 50]]
        d = dict(data)
        print(d) # {'sachin': 100, 'kohli': 80, 'ponting': 50}

        data1 = ['a1', 'b2', 'c3']
        d1 = dict(data1)
        print(d1) # {'a': '1', 'b': '2', 'c': '3'}
        
    Comprehension on a dictionary:
        batsmen = ["sachin", "kohli", "ponting"]
        centuries = [100, 80, 50]
        d = {batsmen[i]:centuries[i] for i in range(len(batsmen))}
        print(d)
        
        import string
        l = list(string.ascii_letters)
        d ={l[i]:i+1 for i in range(26)}
        print(d)

        d1 = {chr(96+i): i for i in range(1, 27)}
        print(d1) 
        
    zip()
        zip() is used to generate N length tuples, where ith element of each tuple comes from ith iterable
        lst = [10, 20, 30, 40, 50]
        string  = 'abc'
        z = zip(lst, string)
        print(z) #izp object, <zip object at 0x7f19f6aa3880>
        print(list(z)) # [(10, 'a'), (20, 'b'), (30, 'c')]

        z1 = zip([1, 2, 3, 4, 5], "money heist", range(10, 100, 10))
        print(list(z1)) # [(1, 'm', 10), (2, 'o', 20), (3, 'n', 30), (4, 'e', 40), (5, 'y', 50)]
        
        d = dict(zip(lst, string)) 
        print(d) # {10: 'a', 20: 'b', 30: 'c'}
        
dict.keys(), dict.values() and dict.items() in dictionary:
    d = {"sachin":100, "kohli":80, "ponting":50}
    print(len(d)) # 3, number of pairs
    for i in d: # running a loop on keys
        print(i, d[i])
        
    print(d.keys()) # list of keys
    print(d.values()) # lsit of values
    print(d.items()) # list of items
        
Special looping Technique:
    students = [["23MH1A05H9", "XYZ", 17], ["23MH1A05E8", "PQR", 19], ["23MH1A05J3", "ABC", 21]]
    for roll, name, age in students: #provided that length of inner iteraables is same
        print(roll, name, age)

    names = ["berlin", "rio", "tokyo", "palermo"]
    marks = [[68, 49, 86, 39, 71], [58, 58, 33, 38, 90], [25, 77, 32, 96, 39], [42, 65, 30, 51, 92]]
    d =  dict(zip(names, marks))
    d1, d2, d3, d4 = {}, {}, {}, {}
    for k, v in d.items():
        d1[k] = max(v)
        d2[k] = min(v)
        d3[k] = sum(v)
        d4[k] = [max(v), min(v), sum(v)]
    print(d1, d2, d3, d4, sep = '\n')
    
Maintaining frequency of iterable using dictionaries:
    s = "aaaabbcdcdca"
    d = {}
    for i in s:
        if i in d:
        d[i] +=1
        else:
            d[i] = 1
    print(d) 
            
""" 
s = "aaaabbcdcdca"
d = {}
for i in s:
    if i in d:
       d[i] +=1
    else:
        d[i] = 1
print(d) 
        

    
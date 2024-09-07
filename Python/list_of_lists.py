"""
list() function
    used to convert other iterables into a list

    string = "hello world"
    list_of_chars = list(string)
    print(list_of_chars) # ['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']

    list_of_even = list(range(2, 21, 2))
    print(list_of_even) # [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

    l = list()
    print(l) # []

List of lists

    #                  0   1   2     0   1   2     0   1   2
    list_of_lists = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
    #                       0           1           2

    print(list_of_lists[0][0]) # 10
    print(list_of_lists[1][1]) # 50
    print(list_of_lists[2][2]) # 90

    Standard way of giving a matrix input:
        r, c = map(int, input().split())
        matrix = []
        for i in range(r):
            row = list(map(int, input().split()))
            matrix.append(row)
        print(matrix)

    r, c = map(int, input().split())
    matrix = [list(map(int, input().split())) for i in range(r)]
    print(matrix)

    value based looping:
        matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
        for each_row in matrix:
            for each_value in each_row:
                print(each_value, end = " ");
            print()
        print()

        for each_row in matrix:
            print("sum = ", sum(each_row), "\tmax = ", max(each_row), "\tmin = ", min(each_row))

    index based looping:
        r = c = 3
        matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
        for i in range(r):
            for j in range(c):
                print(matrix[i][j], end = " ");
            print()

        x = [[10, 20, 30], [40, 50, 60, 70], [80, 90]]
        for i in range(len(x)):
            for j in range(len(x[i])):
                print(x[i][j], end = " ")
            print()

Comprehensions of 2-D Lists:
    marks = [[16, 19, 41, 32, 91],[45, 94, 42, 36, 11],[67, 81, 36, 42, 1],[9, 7, 17, 41, 47],[91, 94, 32, 16, 11]]

    # create a new list called stats
    # [[16, 91, 199], [11, 94, 228], [1, 81, 227], [7, 47, 121], [11, 91, 244]]

    stat = []
    for i in marks:
        stat.append([min(i), max(i), sum(i)])
    print(stat)

    stats = [[min(marks[i]), max(marks[i]), sum(marks[i])] for i in range(len(marks))]
    print(stats)

    ###
    import random
    marks = [[(random.randint(1, 100)) for i in range(5)] for j in range(5)]
    print(marks)


"""
import random
m, n  = random.randint(1, 10), random.randint(1, 10)
mat = [[random.randint(10, 20) for i in range(n)] for j in range(m)]
print(m, n)
for i in range(m):
    print(mat[i])

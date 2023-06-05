def mul(a, b):
    len_column_a = len(a[0])
    len_row_b = len(b)
    if len_column_a == len_row_b:
        row = len(a)
        column = len(b[0])
        c = init(row, column)
        for i in range(row):
            for j in range(column):
                for k in range(len_column_a):
                    c[i][j] += a[i][k]*b[k][j]
    else:
        c = -1
    return c

def mul_(a, b):
    len_column_a = len(a[0])
    len_row_b = len(b)
    if len_column_a == len_row_b:
        row = len(a)
        column = len(b[0])
        c = init(row, column)


def init(row, column):
    c = [[0 for i in range(column)] for j in range(row)]
    return c

def init_2(row, column):
    pass

def trans(a):
    row = len(a)
    column = len(a[0])
    c = init(column, row)
    for i in range(row):
        for j in range(column):
            c[j][i] = a[i][j]
    return c

def det(a):
    row = len(a)
    column = len(a[0])
    if row == column:
        n = row
        if n == 2:
            return a[0][0]*a[1][1] - a[1][0]*a[0][1]
        else:
            res = 0
            for i in range(n):
                res += a[0][i]*det(minor(a, 0, i))*(-1)**i
            return res

def minor(a, i, j):
    row = len(a)
    column = len(a[0])
    if row == column:
        n = row
        c = init(n-1, n-1)
        for ii in range(n-1):
            for jj in range(n-1):
                if ii < i and jj < j:
                    c[ii][jj] = a[ii][jj]
                if ii < i and jj >= j:
                    c[ii][jj] = a[ii][jj+1]
                if ii >= i and jj < j:
                    c[ii][jj] = a[ii+1][jj]
                if ii >= i and jj >= j:
                    c[ii][jj] = a[ii+1][jj+1]
    else:
        c = -1
    return c

def al_dop(a, i , j):
    return (-1)**(i+j)*det(minor(a, i, j))

def adj(a):
    row = len(a)
    column = len(a[0])
    if row == column:
        n = row
        c = init(n, n)
        for i in range(n):
            for j in range(n):
                c[i][j] = al_dop(a, i, j)
        c = trans(c)
        return c

def inverse(a):
    row = len(a)
    column = len(a[0])
    if row == column:
        n = row
        c = init(n, n)
        dett = det(a)
        c = adj(a)
        c = mult_number(c, 1/dett)
        return c

def mult_number(a, number):
    for i in range(len(a)):
        for j in range(len(a[0])):
            a[i][j] = a[i][j]*number
    return a






a = [[1, 2], [3, 4]]
b = [[5, 6], [7, 8]]

a = [[1, 2, 3], [4, 5, 6], [7, 8, 10]]
b = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# a = [[1, 2, 3], 
#      [4, 5, 6]]
# b = [[10, 11], 
#      [15, 16], 
#      [1, 1]]
# c = mul(a, b)
# print(a)
# a = trans(a)
print(a)
#c = minor(a, 1, 1)
#print(c)
c = inverse(a)
print(c)

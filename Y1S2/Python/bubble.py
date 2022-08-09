# O(n^2) runtime
def bubble(alist):
    sorted = False
    while not sorted:
        sorted = True
        for i in range(len(alist) - 1):
            if alist[i] > alist[i + 1]:
                alist[i], alist[i + 1] = alist[i + 1], alist[i]
                sorted = False

    return alist


print(bubble([15, 4, 3, 2, 5, 7, 8, 6, 2, 1]))

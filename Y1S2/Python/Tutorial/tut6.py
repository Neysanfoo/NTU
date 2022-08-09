def reverser(a_str):
    if len(a_str) == 1:
        return a_str
    else:
        new_str = reverser(a_str[1:]) + a_str[0]
        return new_str


def reverseAndRepeat(a_str, num):
    if len(a_str) == 1:
        return a_str * num
    else:
        new_str = reverseAndRepeat(a_str[1:], num) + a_str[0] * num
        return new_str


def reverseAndOppositeCase(a_str):
    if len(a_str) == 1:
        return a_str.swapcase()
    else:
        new_str = reverseAndOppositeCase(a_str[1:]) + a_str[0].swapcase()
        return new_str


def symmetricStirng(a_str):
    return a_str + reverser(a_str)


print(symmetricStirng("ABCDefg"))

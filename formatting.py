first_name = "Neysan"
last_name = "Foo"

# sentence = "My name is {} {}".format(first_name,last_name)

# sentence = f'My name is {first_name} {last_name}'
# print(sentence)


# for n in range(1,11):
#     sentence = f'The values is {n:02}'
#     print(sentence)

# for n in range(1000,1010):
#     sentence = f'The value is {n:,}'
#     print(sentence)

# from math import pi
# sentence = f'Pi is equal to {pi:.3f}'
# print(sentence)

from datetime import datetime

birthday = datetime(2000,5,5)

sentence = f'Neysan has a birthday on {birthday:%B %d, %Y}'
print(sentence)
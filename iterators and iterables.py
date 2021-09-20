# How can we tell is something is iterable?
# If something is iterable, it must have the method __iter__()
# An iterator is object with a state that remembers where it is during iteration.
# An iterator contains the __next__() method

# nums = [2,4,6]
# print(dir(nums)) # Contains __iter__(), but does not contain __next__()

# i_nums = iter(nums)
# print(i_nums)
# print(dir(i_nums)) # Contains __next__()
# print(next(i_nums)) 
# print(next(i_nums)) 
# print(next(i_nums)) 


#------------------------------------------------------------------------#

# Underneath the hood of a for loop
# while True:
#     try:
#         item = next(i_nums)
#         print(item)
#     except StopIteration:
#         break

#------------------------------------------------------------------------#

# Creating a class that is iterable
# We will design it to be like the built in range function
# class MyRange:

#     def __init__(self, start, end):
#         self.value = start
#         self.end = end
    
#     def __iter__(self):
#         return self

#     def __next__(self):
#         if self.value >= self.end:
#             raise StopIteration
#         current = self.value
#         self.value += 1
#         return current

# nums = MyRange(0,10)
# print(nums)
# for num in nums:
#     print(num)

#------------------------------------------------------------------------#

# Generators have a yield statement instead of a return statement
# The difference is that while a return statement terminates 
# a function entirely, yield statement pauses the function saving 
# all its states and later continues from there on successive calls.
# We will write a generator function that does the same thing as our range class

# def my_range(start, end):
#     current = start
#     while current < end:
#         yield current
#         current += 1

# nums = my_range(1,10)
# print([num for num in nums])

#------------------------------------------------------------------------#
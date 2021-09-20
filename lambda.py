# Lambda expression = Anonymous function
# lambda x1,x2,x3... : (return) 


# Write a function to compute 3x+1

# def f(x):
# 	return 3*x + 1
# print(f(2))

# g = lambda x: 3*x+1
# print(g(2))

# Combine first name and last name into a single "Full Name"

# full_name = lambda fn, ln: fn.strip().title() + " " + ln.strip().title()
# my_name = full_name("   Neysan   ", "Foo")
# print(my_name)

# Sort authors by last name
# scifi_authors = ["Isaac Asimov", "Ray Bradbury", "Robert Heinlein",
#  "Arthur C. Clarke", "Frank Herbert", "Orson Scott Card", "Douglas Adams"
#  "H. G. Wells", "Leigh Brackett"]
# scifi_authors.sort(key=lambda name: name.split()[-1].lower())
# print(scifi_authors)


# Write a function that makes functions
# def build_quadratic_function(a,b,c):
# 	"""Returns the function f(x) = ax^2 + bx + c"""
# 	return lambda x: a*x**2 + b*x + c
# f = build_quadratic_function(2,3,-5)
# print(f(4))

# g = build_quadratic_function(1,3,2)(2)
# print(g)
grades = {
    ('FS1', 1) : 45,
    ('FS1', 2) : 75,
    ('FS1', 3) : 25,
    ('FS1', 4) : 65,

    ('FS2', 1) : 75,
    ('FS2', 2) : 40,
    ('FS2', 3) : 70,
    ('FS2', 4) : 80 
}

def inputRecord(dataBase, group, id, score): # To make a new entry to dataBase
	if 1<=id<=40 and 0<=score<=100:
		dataBase[(group,id)] = score
	return dataBase	
#print(inputRecord(grades, "FS3", 2, 50))

	
def query(dataBase, group, id): # Returns the grade of a student
	return dataBase[(group,id)]

#print(query(grades,"FS1",2))

def listGrades(dataBase, group): #List the grades of all the students in a group
	return ([dataBase[key] for key in dataBase if key[0]==group])

#print(listGrades(grades,"FS2"))

def maxGrade(dataBase, group):
    return max(listGrades(dataBase,group))

#print(maxGrade(grades,"FS2"))



print("""Welcome to the grading system! Please enter your options: 
1: input record 
2: query a student
3: list grades in a group
4: get max in a group
5: list all group names
6: exit""")

while True:

    option = int(input("option: "))

    if option == 1:
        groupChoice = input("Please input the group name: ")
        idChoice = int(input("Please input the student id: "))
        scoreChoice = int(input("Please input the score: "))
        inputRecord(grades, groupChoice, idChoice, scoreChoice)
        print("({}, {}) has been entered into the databse.".format(groupChoice, str(idChoice)))

    if option == 2:
        groupChoice = input("Please input the group name: ")
        idChoice = int(input("Please input the student id: "))
        print(query(grades, groupChoice, idChoice))

    if option == 3:
        groupChoice = input("Please input the group name: ")
        print(listGrades(grades, groupChoice))

    if option == 4:
        groupChoice = input("Please input the group name: ")
        print(maxGrade(grades, groupChoice))

    if option == 5:
        print(list(set([key[0] for key in grades]))[::-1])

    if option == 6:
        break

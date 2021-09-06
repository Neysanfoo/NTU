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

print(listGrades(grades,"FS2"))

def maxGrade(dataBase, group):
    return max(listGrades(dataBase,group))


print(maxGrade(grades,"FS2"))
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

def inputRecord(dataBase, group, id, score):
	if 1<=id<=40 and 0<=score<=100:
		dataBase[(group,id)] = score
	return dataBase	
print(inputRecord(grades, "FS3", 2, 50))
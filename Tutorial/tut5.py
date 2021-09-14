#Implment Bulls and Cows https://en.wikipedia.org/wiki/Bulls_and_Cows
from random import randint

def random_tuple():
    digits = [0,1,2,3,4,5,6,7,8,9]
    target = digits.pop(randint(0,9)), digits.pop(randint(0,8)),digits.pop(randint(0,7)),digits.pop(randint(0,6))
    target_int = "".join(map(str,target))
    return target

def noRepeat(int):
    if len(str(int)) == len(set(str(int))):
        return True
    else:
        return False


target = random_tuple()

attempts = 0


while True:
    attempts += 1
    bulls = 0
    cows = 0
    guess = input("Please input 4 digits: ")
    if len(guess) != 4:
        print("Enter 4 digit number only. Try again.")
        attempts -= 1
        continue
    elif noRepeat(int(guess)) == False:
        print("Number should not have repeated digits. Try again.")
        attempts -= 1
        continue
    for i in range(4):
        if int(guess[i])==target[i]:
            bulls += 1
        elif int(guess[i]) in target:
            cows += 1
    print(f"{bulls} A (Bulls) {cows} B (Cows)")
    if bulls == 4:
        print("You Win!")
        print(f"Attempts: {attempts}")
        break

# Discussion 1: To play the 1A2B game, what are the steps (procedures) needed? 
# What is the flow of them? Come up with your design (algorithm)
# by pseudocode/flowchart first.

# Pseudocode:
# Initialize target to 4 different random integers

# Initiallize attempts to zero

# While True:
#     Add 1 to attempts
#     Initiallize bulls counter to zero
#     Initiallize cows counter to zero
#     Prompt user for 4 digit input

#     for i in 0 to 3:
#         if user input is equal to targer at index i:
#             Add one to bulls counter
#         else if user input at index i is in the target:
#             Add one to cows counter 
    
#     Print "{bulls} A (Bulls) {cows} B (Cows)"

#     if bulls is equal to 4:
#         Print "You Win!!"
#         Print attempts
#         break out of While loop


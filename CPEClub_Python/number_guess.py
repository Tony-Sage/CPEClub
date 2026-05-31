import random

num = random.randint(1, 10)

tries = 0
allowedTries = 5
guessed = False

while tries < allowedTries:
    try:
        guess = int(input("I have a number between 1 and 10 in mind. \nGuess the number? "))
        print()
        tries += 1
        triesLeft = allowedTries - tries
        
        if guess < num:
            print("Nah. The number is bigger than that")
        elif guess > num:
            print("Nah. The number is less than that")
        else:
            print("Bingo! You guessed right!\n")
            guessed = True
            break     
        print(f"You have {triesLeft} tries remaining\n")
        
    except ValueError:
        print("Invalid input! Please enter a number between 1 and 10.\n")
        continue

if guessed == True:
    print(f"Congrats! You guessed it in {tries} tries.")
else:
    print("Sorry :( \nNo more tries left.")
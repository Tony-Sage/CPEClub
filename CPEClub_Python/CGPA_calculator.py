totalCreditUnits = 0
totalQualityUnits = 0
record = []

# function to match grade to points
def calculateGradePoint(grade):
    match grade:
        case "A":
            return 5
        case "B":
            return 4
        case "C":
            return 3
        case "D":
            return 2
        case "E":
            return 1
        case "F":
            return 0
        case _:
            return False

def updateRecord(course, creditLoad, grade):
    record.append({"course": course, "creditLoad": creditLoad, "grade": grade})
    

#heading
print("== CGPA Calculator == \n")

#input validation for number of courses
while True:
    try:
        number = int(input("How many courses did you offer this semester? "))
        break
    except ValueError:
        print("Please input a valid number. Letters and symbols are not accepted")

# collecting results
for i in range(number):
    
    data = input(f"\nEnter the course code, credit load and achieved grade for course number {i + 1} separated by a single space each: ").split()
    
    course = data[0]
    
    #input validation for credit load
    while True:
        try:
            creditLoad = int(data[1])
            break
        except ValueError:
            input("The credit load must be a number. Enter a valid number: ")
        
    grade = data[2]
    totalCreditUnits += creditLoad
    gradePoint = calculateGradePoint(data[2])
    
    # input validation for grade
    if gradePoint != False:
        totalQualityUnits += creditLoad * gradePoint
        updateRecord(course, creditLoad, grade)
    else:
        while gradePoint == False:
            print("\nInvalid grade! Grade must be between A and F")
            gradePoint = calculateGradePoint(input("Enter a valid grade: "))
            totalQualityUnits += creditLoad * gradePoint
            updateRecord(course, creditLoad, grade)
        
# calculating CGPA
CGPA = totalQualityUnits / totalCreditUnits

# displaying result
print("\n=== YOUR RESULT ===")
for i in range(number):
    print(f"Course: {record[i]['course']}, Credit Load: {record[i]['creditLoad']}, Grade: {record[i]['grade']}")

print(f"\nYour CGPA is {CGPA: .2f}")

#saving to file
choice = input("Do you want to save result to file? Enter y for yes or n for no: ")

while True:
    if choice == "y":
        with open("CGPA.txt", "w") as file:
            file.write("=== YOUR RESULT ===\n")
            for i in range(number):
                file.write(f"Course: {record[i]['course']}, Credit Load: {record[i]['creditLoad']}, Grade: {record[i]['grade']}")
            file.write(f"\nYour CGPA is {CGPA: .2f}")
            break
    else:
        print("Enter only y or n please!")
print("== CGPA Calculator == \n")

number = int(input("How many courses did you offer this semester? "))

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

totalCreditUnits = 0
totalQualityUnits = 0

for i in range(number):
    
    data = input(f"\nEnter the credit load and achieved grade for course number {i + 1} separated by a single space each: ").split()
    
    totalCreditUnits += int(data[0])
    gradePoint = calculateGradePoint(data[1])
    
    if gradePoint != False:
        totalQualityUnits += int(data[0]) * gradePoint
    else:
        while gradePoint == False:
            print("\nInvalid grade! Grade must be between A and F")
            gradePoint = calculateGradePoint(input("Enter a valid grade: "))
        

CGPA = totalQualityUnits / totalCreditUnits   
print(f"Your CGPA is {CGPA: .2f}")
def calculate_gpa(grades, credit_hours):
    total_quality_points = 0
    total_credit_hours = 0

    for grade, credit_hour in zip(grades, credit_hours):
        if grade == "A":
            quality_points = 4.0
        elif grade == "A-":
            quality_points = 3.7
        elif grade == "B+":
            quality_points = 3.3
        elif grade == "B":
            quality_points = 3.0
        elif grade == "B-":
            quality_points = 2.7
        elif grade == "C+":
            quality_points = 2.3
        elif grade == "C":
            quality_points = 2.0
        elif grade == "C-":
            quality_points = 1.7
        elif grade == "D+":
            quality_points = 1.3
        elif grade == "D":
            quality_points = 1.0
        else:
            quality_points = 0.0

        total_quality_points += quality_points * credit_hour
        total_credit_hours += credit_hour

    if total_credit_hours == 0:
        return 0.0
    else:
        gpa = total_quality_points / total_credit_hours
        return gpa

# Input grades and credit hours for each course
grades = ["A", "B", "A-", "C+"]
credit_hours = [3, 4, 3, 2]

# Calculate GPA
gpa = calculate_gpa(grades, credit_hours)

print(f"Your GPA is: {gpa:.2f}")

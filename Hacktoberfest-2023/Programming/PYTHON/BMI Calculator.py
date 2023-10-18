def get_height_cm():
    unit = int(input("Height in 1. inches, 2. feet and inches, or 3. centimeters? Choose and type 1, 2, or 3 -> "))
    
    if unit == 1:
        return float(input("Enter your height in inches: ")) * 2.54
    elif unit == 2:
        height_ft_inches = input("Enter in this format: 5'4 or foot'inches -> ")
        feet, inches = map(int, height_ft_inches.split("'"))
        return feet * 30.48 + inches * 2.54
    elif unit == 3:
        return float(input("Enter your height in centimeters: "))
    else:
        return None

def get_weight_kg():
    unit = int(input("Weight in 1. kg or 2. pounds? Choose and type 1 or 2 -> "))
    weight = float(input("Enter your weight: "))
    
    if unit == 2:
        return weight * 0.453592
    else:
        return weight

def calculate_bmi(height_cm, weight_kg):
    height_m = height_cm / 100
    return weight_kg / (height_m * height_m)

def get_bmi_category(bmi):
    bmi_categories = {
        (0, 16): "You are severely underweight",
        (16, 17): "You are moderately underweight",
        (17, 18.5): "You are mildly underweight",
        (18.5, 25): "You are healthy",
        (25, 30): "You are overweight",
        (30, 35): "You belong to obesity class I",
        (35, 40): "You belong to obesity class II",
        (40, float('inf')): "You belong to obesity class III"
    }
    
    for (min_value, max_value), category in bmi_categories.items():
        if min_value <= bmi < max_value:
            return category
    
    return "Enter valid details"

def main():
    height_cm = get_height_cm()
    weight_kg = get_weight_kg()
    
    if height_cm is not None and weight_kg is not None:
        bmi = calculate_bmi(height_cm, weight_kg)
        print(f"Your Body Mass Index is: {bmi:.2f}")
        bmi_category = get_bmi_category(bmi)
        print(bmi_category)

if __name__ == "__main__":
    main()

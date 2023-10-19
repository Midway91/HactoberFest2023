# Objectives

# Create a class (Blueprint)
# create an instance (Object)
# class vs instance
# instance attributes: defined in __init(self)__
# class attribute
# class attribute and instance attribute


# Lists
# position, name, age, level, salary
se1 = ['Software Engineer', "Chirag", 22, "Junior", 10000]
se2 = ["Software Engineer", "Rahul", 27, "Senior", 50000]


# Class
class SoftwareEngineer:

    # class attributes
    alias = "Keyboard Magician"

    def __init__(self, position,  name, age, level, salary):
        # instance attributes
        self.position = position
        self.name = name
        self.age = age
        self.level = level
        self.salary = salary


# Instance of class SoftwareEngineer
ob_se1 = SoftwareEngineer("Software Engineer", "Chirag Verma", 22, "Junior", 10000)
print(ob_se1.name, ob_se1.age)
print(SoftwareEngineer.alias)
print(ob_se1.alias)
# print(SoftwareEngineer.position)
# This above one won't work because position is an instance attribute ans it can be handled only by instance

print("\n")

ob_se2 = SoftwareEngineer("Software Engineer", "Rahul Verma", 27, "Senior", 50000)
print(ob_se2.name, ob_se2.age)
print(ob_se2.alias)
print(SoftwareEngineer.alias)




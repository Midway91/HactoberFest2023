# Objectives
# instance methods(self)
# our methods can take arguments and they return values
# special "dunder" methods i.e __func__
# @staticmethod

# Lists
# position, name, age, level, salary
se1 = ['Software Engineer', "Chirag", 22, "Junior", 10000]
se2 = ["Software Engineer", "Rahul", 27, "Senior", 50000]
de1 = ["Designer", "Amit"]


def code(se):
    print(f'{se[1]} is writing code...')


# code(se2)
# print()
# code(de1)

# Through this we get the output for the designer also which is not okay so we bound the function to a specific class.


# Class
class SoftwareEngineer:

    # class attributes
    alias = "Keyboard Magician"

    # special function
    def __init__(self, position,  name, age, level, salary):
        # instance attributes
        self.position = position
        self.name = name
        self.age = age
        self.level = level
        self.salary = salary

    # instance method
    def code(self):
        print(f'{self.name} is writing code...')

    def code_in_language(self, language):
        print(f'{self.name} writing code in {language}...')

    # def information(self):
    #     print(f'Name = {self.name}, Age = {self.age}, Level = {self.level}')

    # dunder method
    def __str__(self):
        information = f'Name = {self.name}, Age = {self.age}, Level = {self.level}'
        return information

    def __eq__(self, other):  # At default __eq__ function compare the memory address
        return self.name == other.name and self.age == other.age

    @staticmethod  # Through this decorator we can use this function with class objects.
    def entry_salary(age):
        if age < 25:
            return 5000
        if age < 30:
            return 7000
        return 10000


ob_se1 = SoftwareEngineer('Software Engineer', "Chirag", 22, "Junior", 10000)
ob_se2 = SoftwareEngineer("Software Engineer", "Rahul Verma", 27, "Senior", 50000)
ob_se3 = SoftwareEngineer("Software Engineer", "Rahul Verma", 27, "Senior", 50000)

print()
ob_se1.code()
ob_se2.code()
print()
ob_se1.code_in_language("Python")
print(ob_se1)
ob_se2.code_in_language("C++")
print(ob_se2)

print()

print(ob_se2 == ob_se3)

print(ob_se1.entry_salary(25))
print(SoftwareEngineer.entry_salary(21))

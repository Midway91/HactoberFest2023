
# Objectives

# Inheritance: ChildClass(BaseClass)
# inherits, extends and override
# super().__init__()
# Polymorphism

class Employee:

    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def work(self):
        print(f'{self.name} is working...')


class SoftwareEngineer(Employee):  # we inherit Employee class here

    def __init__(self, name, age, salary, level):  # we override __init__(self) function here
        super().__init__(name, age, salary)
        self.level = level

    def work(self):  # we override work(self) function here
        print(f'{self.name} is coding...')

    def debug(self):  # we extend the functionality of Employee class here in SoftwareEngineer class
        print(f'{self.name} is debugging...')


class Designer(Employee):  # we inherit Employee class here

    def work(self):  # we override work(self) function here
        print(f'{self.name} is designing...')

    def draw(self):  # we extend the functionality of Employee class here in Designer class
        print(f'{self.name} is drawing...')


se = SoftwareEngineer('Chirag', 22, 100000, 'Junior')
print(se.name, se.age)
se.work()
se.debug()

d = Designer('Rahul', 27, 100000)
print(d.name, d.age)
d.work()
d.draw()


# Polymorphism
employees = [SoftwareEngineer('Chirag', 22, 100000, 'Junior'),
             SoftwareEngineer('Mukul', 22, 100000, 'Junior'),
             Designer('Jagmohan', 27, 100000)]


# As we call work function multiple times but they give perform different for coding and designing
def motivate_employees(employees):
    for employee in employees:
        employee.work()


motivate_employees(employees)
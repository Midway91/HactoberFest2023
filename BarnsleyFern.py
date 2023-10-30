import turtle
import random

# Set up the Turtle screen
screen = turtle.Screen()
screen.bgcolor("black")
screen.title("Barnsley Fern")

# Create a Turtle object
fern = turtle.Turtle()
fern.shape("circle")
fern.speed(0)
fern.color("green")
fern.penup()
fern.goto(0, -200)
fern.pendown()

# Define the transformation functions
def transform1(x, y):
    x1 = 0
    y1 = 0.16 * y
    return x1, y1

def transform2(x, y):
    x2 = 0.85 * x + 0.04 * y
    y2 = -0.04 * x + 0.85 * y + 1.6
    return x2, y2

def transform3(x, y):
    x3 = 0.2 * x - 0.26 * y
    y3 = 0.23 * x + 0.22 * y + 1.6
    return x3, y3

def transform4(x, y):
    x4 = -0.15 * x + 0.28 * y
    y4 = 0.26 * x + 0.24 * y + 0.44
    return x4, y4

# List of transformation functions and their probabilities
transforms = [transform1, transform2, transform3, transform4]
probabilities = [0.01, 0.85, 0.07, 0.07]

# Number of iterations
num_iterations = 50000

# Generate the Barnsley Fern
for _ in range(num_iterations):
    x, y = random.uniform(-3, 3), random.uniform(0, 10)
    r = random.random()
    for i in range(len(transforms)):
        if r < sum(probabilities[:i + 1]):
            x, y = transforms[i](x, y)
            break
    fern.penup()
    fern.goto(x * 50, y * 50)
    fern.pendown()
    fern.dot(1)

# Close the window on click
screen.exitonclick()

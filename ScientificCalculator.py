# Importing the library
from future.moves import tkinter
import math


# To provide functionalities
def click(val):
    e = entry.get()  # getting the value
    ans = " "

    try:
        # To clear the last inserted text
        if val == "C":
            e = e[0:len(e) - 1]  # deleting the last entered value
            entry.delete(0, "end")
            entry.insert(0, e)
            return

        # To delete everything
        elif val == "CE":
            entry.delete(0, "end")

        # Square root
        elif val == "√":
            ans = math.sqrt(eval(e))

        # pi value
        elif val == "π":
            ans = math.pi

        # cos value
        elif val == "cosθ":
            ans = math.cos(math.radians(eval(e)))

        # sin value
        elif val == "sinθ":
            ans = math.sin(math.radians(eval(e)))

        # tan Value
        elif val == "tanθ":
            ans = math.tan(math.radians(eval(e)))

        # 2π value
        elif val == "2π":
            ans = 2 * math.pi

        # cosh value
        elif val == "cosh":
            ans = math.cosh(eval(e))

        # sinh value
        elif val == "sinh":
            ans = math.sinh(eval(e))

        # tanh value
        elif val == "tanh":
            ans = math.tanh(eval(e))

        # cube root value
        elif val == chr(8731):
            ans = eval(e) ** (1 / 3)

        # x to the power y
        elif val == "x\u02b8":
            entry.insert("end", "**")
            return

        # cube value
        elif val == "x\u00B3":
            ans = eval(e) ** 3

        # square value
        elif val == "x\u00B2":
            ans = eval(e) ** 2

        # ln value
        elif val == "ln":
            ans = math.log2(eval(e))

        # deg value
        elif val == "deg":
            ans = math.degrees(eval(e))

        # radian value
        elif val == "rad":
            ans = math.radians(eval(e))

        # e value
        elif val == "e":
            ans = math.e

        # log10 value
        elif val == "log10":
            ans = math.log10(eval(e))

        # factorial value
        elif val == "x!":
            ans = math.factorial(eval(e))

        # division operator
        elif val == chr(247):
            entry.insert("end", "/")
            return

        elif val == "=":
            ans = eval(e)

        else:
            entry.insert("end", val)
            return

        entry.delete(0, "end")
        entry.insert(0, ans)

    except SyntaxError:
        pass


# Created the object
root = tkinter.Tk()

# Setting the title and geometry
root.title("Scientific Calculator")
root.geometry("680x486+100+100")

# Setting the background color
root.config(bg="black")


# Entry field
entry = tkinter.Entry(root, font=("arial", 20, "bold"), bg="black", fg="white", bd=10, width=30)
entry.grid(row=0, column=0, columnspan=8)

# buttons list
button_list = ["C", "CE", "√", "+", "π", "cosθ", "tanθ", "sinθ", "1", "2", "3", "-", "2π", "cosh", "tanh", "sinh",
               "4", "5", "6", "*", chr(8731), "x\u02b8", "x\u00B3", "x\u00B2", "7", "8", "9", chr(247), "ln", "deg",
               "rad", "e", "0", ".", "%", "=", "log10", "(", ")", "x!"]
r = 1
c = 0
# Loop to get the buttons on window
for i in button_list:
    # Buttons
    button = tkinter.Button(root, width=5, height=2, bd=2, text=i, bg="black", fg="white",
                            font=("arial", 18, "bold"), command=lambda button=i: click(button))
    button.grid(row=r, column=c, pady=1)
    c += 1
    if c > 7:
        r += 1
        c = 0

# Makes window on loop
root.mainloop()

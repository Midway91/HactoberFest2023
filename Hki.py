import tkinter as tk

root = tk.Tk()

root.geometry("500x500")
root.resizable(False, False)
root.title("Aki was here!")
root.configure(bg="black")

greetings = tk.Label(root, text="Greetings, Hacktoberfest!",
                     font=('Courier New', 18), bg="green")
greetings.place(x=70, y=175)

message = tk.Label(root, text="This is Jake, a developer from Manila, Philippines.\nThis is my first ever commit to a public repository!",
                   font=('Courier New', 10), fg='green')
message.place(x=35, y=215)

htbf = tk.Label(root, text="#Hacktoberfest 2023", font=(
    'Courier New', 13), bg='black', fg='green')
htbf.place(x=145, y=260)

root.mainloop()
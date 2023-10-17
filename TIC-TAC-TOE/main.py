import dis
from tkinter import *
from tkinter import messagebox
import ctypes, os 
ctypes.windll.shcore.SetProcessDpiAwareness(True)

root = Tk()
root.title("Tic Tac Toe")
# root.geometry('800x800+400+50')
root['bg'] = "#f0f0f0"
root.iconbitmap(r'./ico/icon.ico')
# 
# Game Variables 
clicked = True # X -> True | O -> False
count = 1
winner = False

def disable_all_buttons():
    b1.configure(state=DISABLED)
    b2.configure(state=DISABLED)
    b3.configure(state=DISABLED)
    b4.configure(state=DISABLED)
    b5.configure(state=DISABLED)
    b6.configure(state=DISABLED)
    b7.configure(state=DISABLED)
    b8.configure(state=DISABLED)
    b9.configure(state=DISABLED)
    messagebox.showinfo("Congratulations. . . !!", "You have won the game. . . !!")

def check_if_someone_won():
    global winner
    global clicked
    global count
    # NOTE: Check for 'X'
    # Check horizontally
    if b1['text'] == "X" and b2['text'] == "X" and b3['text'] == "X":
        b1.configure(bg="red")
        b2.configure(bg="red")
        b3.configure(bg="red")
        winner = True
        disable_all_buttons()

    elif b4['text'] == "X" and b5['text'] == "X" and b6['text'] == "X":
        b4.configure(bg="red")
        b5.configure(bg="red")
        b6.configure(bg="red")
        winner = True
        disable_all_buttons()

    elif b7['text'] == "X" and b8['text'] == "X" and b9['text'] == "X":
        b7.configure(bg="red")
        b8.configure(bg="red")
        b9.configure(bg="red")
        winner = True
        disable_all_buttons()

    # Check vertically
    elif b1['text'] == "X" and b4['text'] == "X" and b7['text'] == "X":
        b1.configure(bg="red")
        b4.configure(bg="red")
        b7.configure(bg="red")
        winner = True
        disable_all_buttons()

    elif b2['text'] == "X" and b5['text'] == "X" and b8['text'] == "X":
        b2.configure(bg="red")
        b5.configure(bg="red")
        b8.configure(bg="red")
        winner = True
        disable_all_buttons()

    elif b3['text'] == "X" and b6['text'] == "X" and b9['text'] == "X":
        b3.configure(bg="red")
        b6.configure(bg="red")
        b9.configure(bg="red")
        winner = True
        disable_all_buttons()

    # Check diagonally
    elif b1['text'] == "X" and b5['text'] == "X" and b9['text'] == "X":
        b1.configure(bg="red")
        b5.configure(bg="red")
        b9.configure(bg="red")
        winner = True
        disable_all_buttons()

    elif b3['text'] == "X" and b5['text'] == "X" and b7['text'] == "X":
        b3.configure(bg="red")
        b5.configure(bg="red")
        b7.configure(bg="red")
        winner = True
        disable_all_buttons()

    # NOTE: Check for 'O'
    # Check horizontally
    if b1['text'] == "O" and b2['text'] == "O" and b3['text'] == "O":
        b1.configure(bg="blue")
        b2.configure(bg="blue")
        b3.configure(bg="blue")
        winner = True
        disable_all_buttons()

    elif b4['text'] == "O" and b5['text'] == "O" and b6['text'] == "O":
        b4.configure(bg="blue")
        b5.configure(bg="blue")
        b6.configure(bg="blue")
        winner = True
        disable_all_buttons()

    elif b7['text'] == "O" and b8['text'] == "O" and b9['text'] == "O":
        b7.configure(bg="blue")
        b8.configure(bg="blue")
        b9.configure(bg="blue")
        winner = True
        disable_all_buttons()

    # Check vertically
    elif b1['text'] == "O" and b4['text'] == "O" and b7['text'] == "O":
        b1.configure(bg="blue")
        b4.configure(bg="blue")
        b7.configure(bg="blue")
        winner = True
        disable_all_buttons()

    elif b2['text'] == "O" and b5['text'] == "O" and b8['text'] == "O":
        b2.configure(bg="blue")
        b5.configure(bg="blue")
        b8.configure(bg="blue")
        winner = True
        disable_all_buttons()

    elif b3['text'] == "O" and b6['text'] == "O" and b9['text'] == "O":
        b3.configure(bg="blue")
        b6.configure(bg="blue")
        b9.configure(bg="blue")
        winner = True
        disable_all_buttons()

    # Check diagonally
    elif b1['text'] == "O" and b5['text'] == "O" and b9['text'] == "O":
        b1.configure(bg="blue")
        b5.configure(bg="blue")
        b9.configure(bg="blue")
        winner = True
        disable_all_buttons()

    elif b3['text'] == "O" and b5['text'] == "O" and b7['text'] == "O":
        b3.configure(bg="blue")
        b5.configure(bg="blue")
        b7.configure(bg="blue")
        winner = True
        disable_all_buttons()

    # print(count, winner)
    # Check if tie
    if count == 9 and winner == False:
        messagebox.showinfo("Tic Tac Toe", "Game Draw")
        b1.configure(state=DISABLED, bg="silver")
        b2.configure(state=DISABLED, bg="silver")
        b3.configure(state=DISABLED, bg="silver")
        b4.configure(state=DISABLED, bg="silver")
        b5.configure(state=DISABLED, bg="silver")
        b6.configure(state=DISABLED, bg="silver")
        b7.configure(state=DISABLED, bg="silver")
        b8.configure(state=DISABLED, bg="silver")
        b9.configure(state=DISABLED, bg="silver")

def b_click(b):
    global clicked, count

    # for 'X'
    if b['text'] == " " and clicked == True:
        b['text'] = "X"
        clicked = False
        count += 1
        check_if_someone_won()

    # for 'O'
    elif b['text'] == " " and clicked == False:
        b['text'] = "O"
        clicked = True
        count += 1
        check_if_someone_won()

    else:
        messagebox.showerror("Hey", "It's already selected")

def reset():
    global b1, b2, b3, b4, b5, b6, b7, b8, b9
    global clicked, count
    clicked = True
    count = 0
    
    b1 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b1))
    b2 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b2))
    b3 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b3))
    b4 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b4))
    b5 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b5))
    b6 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b6))
    b7 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b7))
    b8 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b8))
    b9 = Button(root, text=" ", height=3, width=6, font="Helvetica 20", bg="SystemButtonFace", padx=6, command=lambda: b_click(b9))

    # Create Tic Tac Toe Button's
    b1.grid(row=0, column=0, padx=2, pady=2)
    b2.grid(row=0, column=1, padx=2, pady=2)
    b3.grid(row=0, column=2, padx=2, pady=2)

    b4.grid(row=1, column=0, padx=2, pady=2)
    b5.grid(row=1, column=1, padx=2, pady=2)
    b6.grid(row=1, column=2, padx=2, pady=2)

    b7.grid(row=2, column=0, padx=2, pady=2)
    b8.grid(row=2, column=1, padx=2, pady=2)
    b9.grid(row=2, column=2, padx=2, pady=2)

main_menu = Menu(root)
root.configure(menu=main_menu)

# Options menu
option_menu = Menu(main_menu, tearoff=0)

main_menu.add_cascade(label="Options", menu=option_menu)
option_menu.add_command(label="Reset Game", command=reset)
option_menu.add_command(label="Close", command=root.quit)

reset()
root.mainloop()

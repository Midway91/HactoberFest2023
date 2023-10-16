from tkinter import *
from random import choice
from random import shuffle
import ctypes
ctypes.windll.shcore.SetProcessDpiAwareness(True)

root = Tk()
root.title("Word Jumble Game")
root.geometry('900x480+400+50')
# root.iconbitmap('./ico/icon.ico')

# States of IN
states = [
    "Andhra Pradesh", "Arunachal Pradesh", "Assam", "Bihar", 
    "Chhattisgarh", "Goa", "Gujarat", "Haryana", "Himachal Pradesh", 
    "Jammu and Kashmir", "Jharkhand", "Karnataka", "Kerala", "Madhya Pradesh", 
    "Maharashtra", "Manipur", "Meghalaya", "Mizoram", "Nagaland", "Odisha",
    "Punjab", "Rajasthan", "Sikkim", "Tamil Nadu", "Telangana", 
    "Tripura", "Uttar Pradesh", "Uttarakhand", "West Bengal", 
    "Andaman and Nicobar Islands", "Chandigarh", "Dadra and Nagar Haveli", 
    "Daman and Diu", "Lakshadweep",  "Puducherry"]

# Shiffle word real logic
def shuffle_word_game():
    global shuffled_word
    global word
    global hint_counter
    hint_counter = 0

    # Clear entry box
    entry_word.delete(0, END)
    # Clear answer_lbl
    answer_lbl['text'] = ''
    # Clear the status_bar text
    status_bar_lbl['text'] = 'Status bar'
    # Clear hint Label
    hint_lbl['text'] = ''

    # NOTE: Pick random state from list
    word = choice(states)
    word = word.lower()
    shuffle_lbl['text'] = word

    # NOTE: Break the word and shuffle it
    break_apart_word = list(word)
    shuffle(break_apart_word)

    # print(word)
    # Turn the break_apart_word list, into shuffled_word
    shuffled_word = ''
    for letter in break_apart_word:
        shuffled_word += letter
    
    shuffle_lbl['text'] = shuffled_word

# Answer function
def answer():
    if entry_word.get() != '':
        if word == entry_word.get():
            answer_lbl['text'] = "Correct !!"
            status_bar_lbl['text'] = "Congratulations! You have won."
        else:
            answer_lbl['text'] = "Incorrect !!"
            status_bar_lbl['text'] = "Better luck next time..."
    else:
        pass
    
# Status Bar
def status_bar():
    global status_bar_lbl
    status_frame = Frame(root)
    status_bar_lbl = Label(status_frame, text="Status Bar ", anchor='e', fg='white', bg='#484943')
    status_bar_lbl.pack(anchor='e', fill=X)
    status_frame.pack(side='bottom', fill=X)

status_bar()

# NOTE: Hint counter
hint_counter = 0

# Create Hint function
def hint(count):
    global hint_counter
    # print(hint_counter)
    word_length = len(word)
    # print(word)
    if hint_counter < word_length:
        hint_lbl['text'] = hint_lbl['text'] + word[count]
        hint_counter += 1


# Shuffle_Label effect
def on_enter(e):
    shuffle_lbl['bg'] = "#e5f9fb"
    shuffle_lbl['fg'] = "black"
    shuffle_lbl['highlightbackground'] = "#0076d7"
    shuffle_lbl['highlightthickness'] = 1

def on_leave(e):
    shuffle_lbl['bg'] = "#fff"
    shuffle_lbl['fg'] = "#000"
    shuffle_lbl['highlightbackground'] = "red"
    shuffle_lbl['highlightthickness'] = 1

# Answer_label Effect
def on_enter_ans_lbl(e):
    answer_lbl['bg'] = "#e5f9fb"
    answer_lbl['fg'] = "black"
    answer_lbl['highlightbackground'] = "#0076d7"
    answer_lbl['highlightthickness'] = 1

def on_leave_ans_lbl(e):
    answer_lbl['bg'] = "#fff"
    answer_lbl['fg'] = "#000"
    answer_lbl['highlightbackground'] = "red"
    answer_lbl['highlightthickness'] = 1

# Answer_label Effect
def on_enter_hint_lbl(e):
    hint_lbl['bg'] = "#e5f9fb"
    hint_lbl['fg'] = "black"
    hint_lbl['highlightbackground'] = "#0076d7"
    hint_lbl['highlightthickness'] = 1

def on_leave_hint_lbl(e):
    hint_lbl['bg'] = "#fff"
    hint_lbl['fg'] = "#000"
    hint_lbl['highlightbackground'] = "red"
    hint_lbl['highlightthickness'] = 1

# Pick Another word button
def btn_on_enter1(e):
    btn['bg'] = "#e5f9fb"
    btn['fg'] = "black"
    btn['highlightbackground'] = "#0076d7"
    btn['activebackground'] = "#c5f9fb"
    btn['highlightthickness'] = 5

def btn_on_leave1(e):
    btn['bg'] = "#fff"
    btn['fg'] = "#000"
    btn['highlightbackground'] = "#FFF"
    btn['highlightthickness'] = 1

# Answer Button
def btn_on_enter2(e):
    answer_btn['bg'] = "#e5f9fb"
    answer_btn['fg'] = "black"
    answer_btn['highlightbackground'] = "#0076d7"
    answer_btn['activebackground'] = "#c5f9fb"
    answer_btn['highlightthickness'] = 5

def btn_on_leave2(e):
    answer_btn['bg'] = "#fff"
    answer_btn['fg'] = "#000"
    answer_btn['highlightbackground'] = "#FFF"
    answer_btn['highlightthickness'] = 1

def btn_on_enter3(e):
    hint_btn['bg'] = "#e5f9fb"
    hint_btn['fg'] = "black"
    hint_btn['highlightbackground'] = "#0076d7"
    hint_btn['activebackground'] = "#c5f9fb"
    hint_btn['highlightthickness'] = 5
    
def btn_on_leave3(e):
    hint_btn['bg'] = "#fff"
    hint_btn['fg'] = "#000"
    hint_btn['highlightbackground'] = "#FFF"
    hint_btn['highlightthickness'] = 1
    

shuffle_lbl = Label(root, text="", fg='black', font=("Helvetica", 40), bg='#fff', bd=0, relief='solid', padx=10, pady=10, activebackground='#3E4149', activeforeground='white')
shuffle_lbl.bind("<Enter>", on_enter)
shuffle_lbl.bind("<Leave>", on_leave)
shuffle_lbl.pack(padx=10, pady=10)

btn_frame = Frame(root)

entry_word = Entry(root, font=("Helvetica", 30), width=21, highlightcolor='red')
entry_word.pack(pady=10, padx=10)

btn = Button(btn_frame, text="Pick Another word", command=shuffle_word_game, padx=10, relief="ridge", bd=1, cursor="hand2", font=("Helvetica", 20))
btn.bind("<Enter>", func=btn_on_enter1)
btn.bind("<Leave>", func=btn_on_leave1)
btn.grid(row=0, column=0, padx=10, pady=10)

answer_btn = Button(btn_frame, text="Answer", command=answer, padx=10, relief="ridge", bd=1, cursor="hand2", font=("Helvetica", 20))
answer_btn.bind("<Enter>", func=btn_on_enter2)
answer_btn.bind("<Leave>", func=btn_on_leave2)
answer_btn.grid(row=0, column=1, padx=10, pady=10)

hint_btn = Button(btn_frame, text="Hint", command=lambda: hint(hint_counter), padx=10, relief="ridge", bd=1, cursor="hand2", font=("Helvetica", 20))
hint_btn.bind("<Enter>", func=btn_on_enter3)
hint_btn.bind("<Leave>", func=btn_on_leave3)
hint_btn.grid(row=0, column=2, padx=10, pady=10)

hint_lbl = Label(btn_frame, text="", font=("Helvetica", 30))
hint_lbl.bind("<Enter>", on_enter_hint_lbl)
hint_lbl.bind("<Leave>", on_leave_hint_lbl)
hint_lbl.grid(row=2, column=0, columnspan=3)

btn_frame.pack()

answer_lbl = Label(root, text="", fg='black', font=("Helvetica", 40), bg='#fff', bd=0, relief='solid', padx=10, pady=10, activebackground='#3E4149', activeforeground='white')
answer_lbl.bind("<Enter>", on_enter_ans_lbl)
answer_lbl.bind("<Leave>", on_leave_ans_lbl)
answer_lbl.pack(padx=10, pady=10)

root.resizable(False, False)
shuffle_word_game()
root.mainloop()

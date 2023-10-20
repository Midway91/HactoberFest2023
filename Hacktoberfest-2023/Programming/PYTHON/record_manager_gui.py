import tkinter as tk
from tkinter import *
import os

def main_acc():
    global main_screen
    main_screen = Tk()
    main_screen.geometry("300x260")
    main_screen.title("Main")
    Label(text="Login or Register", bg="#b1abf1", fg="white",
          width="300", height="2", font=("Calibri", 13)).pack(padx=20, 
pady=23 )
    Button(text="LOGIN", height="2", width="15", 
fg="#c0ecc0",command=login).pack(padx=1, pady=20)
    Button(text="REGISTER", height="2", width="15",fg="#D8BFD8", 
command=register).pack(padx=1, pady=5)
    main_screen.mainloop()

def register():
    global register_screen
    register_screen = Toplevel(main_screen)
    register_screen.title("Register")
    register_screen.geometry("320x350")

    global username
    global password
    global username_entry
    global password_entry
    username = StringVar()
    password = StringVar()

    Label(register_screen, text="Enter Details Below to Login!",bg="#D8BFD8", fg="black",
          width="300", height="2",font=("Calibri", 13)).pack(padx=20, 
pady=23 )
    Label(register_screen, text="").pack()

    unLabel = Label(register_screen, text="Username",fg="black", 
bg="#D8BFD8")
    unLabel.pack(pady=5)

    unEntry = Entry(register_screen, textvariable=username)
    unEntry.pack()

    passLabel = Label(register_screen, text="Password",fg="black" , 
bg="#D8BFD8")
    passLabel.pack(pady=5)

    passEntry = Entry(register_screen,textvariable=password, show='*')
    passEntry.pack()

    Label(register_screen, text="").pack()
    Button(register_screen, text="Register", width=10, height=1, 
fg="black", command=register_user).pack()

def login():
    global login_screen
    login_screen = Toplevel(main_screen)
    login_screen.title("Login")
    login_screen.geometry("320x350")
    Label(login_screen,text="Enter Details Below to Login!",bg="#c0ecc0", 
fg="black",
          width="300", height="2",font=("Calibri", 13)).pack(padx=20, 
pady=23 )
    Label(login_screen, text="").pack()

    global username_verify
    global password_verify

    username_verify = StringVar()
    password_verify = StringVar()

    global username_login_entry
    global password_login_entry

    Label(login_screen, text="Username",fg="black", bg="#c0ecc0").pack()
    username_login_entry = Entry(login_screen, 
textvariable=username_verify)
    username_login_entry.pack(pady=5)

    Label(login_screen, text="").pack()
    Label(login_screen, text="Password",fg="black", 
bg="#c0ecc0").pack(pady=5)

    password_login_entry = Entry(login_screen, 
textvariable=password_verify, show='*').pack()

    Label(login_screen, text="").pack()
    Button(login_screen, text="Login",width=10,fg="black" ,height=1, 
command=login_verify).pack()

def register_user():
    username_info = username.get()
    password_info = password.get()

    file = open(username_info, "w")
    file.write(username_info + "\n")
    file.write(password_info)
    file.close()

    username_entry.delete(0, END)
    password_entry.delete(0, END)

    Label(register_screen, text="Registration Success", fg="green", 
font=("calibri", 11)).pack()

def login_verify():
    username1 = username_verify.get()
    password1 = password_verify.get()
    username_login_entry.delete(0, END)
    password_login_entry.delete(0, END)

    list_of_files = os.listdir()
    if username1 in list_of_files:
        file1 = open(username1, "a")
        verify = file1.read().splitlines()
        if password1 in verify:
            login_sucess()
        else:
            password_not_recognised()
    else:
        user_not_found()

def login_sucess():
    global login_success_screen
    login_success_screen = Toplevel(login_screen)
    login_success_screen.title("Success")
    login_success_screen.geometry("150x100")
    Label(login_success_screen, text="Login Success").pack()
    Button(login_success_screen, text="OK", 
command=delete_login_success).pack()

def password_not_recognised():
    global password_not_recog_screen
    password_not_recog_screen = Toplevel(login_screen)
    password_not_recog_screen.title("ERROR")
    password_not_recog_screen.geometry("150x100")
    Label(password_not_recog_screen, text="Invalid Password").pack()
    Button(password_not_recog_screen, text="OK", 
command=delete_password_not_recognised).pack()

def user_not_found():
    global user_not_found_screen
    user_not_found_screen = Toplevel(login_screen)
    user_not_found_screen.title("ERROR")
    user_not_found_screen.geometry("150x100")
    Label(user_not_found_screen,fg="red", text="User Not Found!").pack(pady=20)
    Button(user_not_found_screen, text="OK", 
command=delete_user_not_found_screen).pack()

def delete_login_success():
    login_success_screen.destroy()

def delete_password_not_recognised():
    password_not_recog_screen.destroy()

def delete_user_not_found_screen():
    user_not_found_screen.destroy()

main_acc()






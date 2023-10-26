import tkinter as tk

def click_button(value):
    current = str(entry.get())
    entry.delete(0, tk.END)
    entry.insert(0, current + value)

def clear_entry():
    entry.delete(0, tk.END)

def clear_all():
    entry.delete(0, tk.END)

def calculate():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(0, str(result))
    except Exception as e:
        entry.delete(0, tk.END)
        entry.insert(0, "Error")

root = tk.Tk()
root.title("Calculator")

entry = tk.Entry(root, width=16, font=('Arial', 20), justify='right')
entry.grid(row=0, column=0, columnspan=4)

buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', '.', '+'
]

row_val = 1
col_val = 0
for button in buttons:
    tk.Button(root, text=button, padx=20, pady=20, font=('Arial', 20),
              command=lambda button=button: click_button(button)).grid(row=row_val, column=col_val)
    col_val += 1
    if col_val > 3:
        col_val = 0
        row_val += 1

tk.Button(root, text='AC', padx=20, pady=20, font=('Arial', 20), command=clear_all).grid(row=5, column=0)
tk.Button(root, text='C', padx=20, pady=20, font=('Arial', 20), command=clear_entry).grid(row=5, column=1)
tk.Button(root, text='=', padx=20, pady=20, font=('Arial', 20), command=calculate).grid(row=5, column=2, columnspan=2)

root.mainloop()

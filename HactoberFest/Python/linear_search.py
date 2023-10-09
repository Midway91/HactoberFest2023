values = [2, 23, 34, 39, 43, 58, 67, 73, 88]
to_check_value = 58
checked_value = False
for x in range(len(values)):
    if values[x] == to_check_value:
        checked_value = True
        print("Value found in the list at index ", x)
        break
if checked_value == False:
    print("Value not found in the list.")

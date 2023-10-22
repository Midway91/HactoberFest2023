with open("input.txt", "r") as infile:
    with open("output.txt", "w") as outfile:
        data = infile.read()
        outfile.write(data)

print("File copied successfully.")

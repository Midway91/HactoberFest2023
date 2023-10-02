import os
import re

def rename_files(directory):
    for filename in os.listdir(directory):
        if filename.endswith(".ttf"):
            base, extension = os.path.splitext(filename)
            base = re.sub(r"(?!^)(?<!_)([A-Z])", r"_\1", base)
            base = base.replace("-", "_")
            base = base.lower()
            base = base.replace("__", '_')
            new_filename = f"{base}{extension}"
            os.rename(os.path.join(directory, filename), os.path.join(directory, new_filename))


directory = input("Enter the directory path: ")
rename_files(directory)

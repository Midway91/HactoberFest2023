#!/usr/bin/env python
import shutil

source = "/path/to/source"
destination = "/path/to/backup"

shutil.copytree(source, destination)
print(f"Backup of {source} created at {destination}")

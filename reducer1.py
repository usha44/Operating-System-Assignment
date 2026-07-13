#!/usr/bin/env python3
import sys

current_word = None
files = set()

for line in sys.stdin:
    word, file = line.strip().split("\t")

    if current_word == word:
        files.add(file)
    else:
        if current_word:
            print(f"{current_word}\t{','.join(files)}")
        current_word = word
        files = {file}

if current_word:
    print(f"{current_word}\t{','.join(files)}")


#!/usr/bin/env python3
import sys
import os

filename = os.getenv('map_input_file', 'unknown')

for line in sys.stdin:
    words = line.strip().split()
    for word in words:
        print(f"{word}\t{filename}")


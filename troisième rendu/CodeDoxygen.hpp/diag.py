#!/bin/python3

from hpp2plantuml import CreatePlantUMLFile
from os import chdir, listdir, system
from sys import argv

if len(argv) != 3:
    print("usage: python3 diag.py <in dir> <out file>")
    exit()

chdir(argv[1])
hpps = [f for f in listdir() if f.endswith("hpp")]
CreatePlantUMLFile(hpps, argv[2])
system(f"plantuml {argv[2]}")
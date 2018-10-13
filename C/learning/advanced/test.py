# test.py
import os
os.system("gcc xor-encryption.c -o xor-encryption")
os.system("./xor-encryption testfile.txt testfile-enx MYKey")
os.system("./xor-encryption testfile-enx-rev testfile-enx-rev MYKey")
os.system("cat testfile-enx-rev")
os.system("cat flag")

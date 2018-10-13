import random

def check_key(key):
    sum = 0
    for c in key:
        sum += ord(c)
    return sum

key = ""

while True:
    key += random.choice("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-_")
    s = check_key(key)
    if s == 728:
        print "FOUND KEY: " + key + "\n"
    if s > 918:
        key = ""

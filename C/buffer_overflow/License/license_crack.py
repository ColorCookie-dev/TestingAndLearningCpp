import random

def check_key(key):
    sum = 0
    for c in key:
        sum += ord(c)
    return sum

# This tries to create new keys and tries to check them with check_key
# ====================================================================
# This chooses a random character and concatenates it to the key variable
# if the key does not match when checked and if it doesn't match the it concatenates
# if the if the key gets very long then it resets
# ====================================================================
key = ""
while True:
    key += random.choice("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-_")
    s = check_key(key)
    if s == 728:
        print "FOUND KEY: " + key + "\n"
    if s > 918:
        key = ""

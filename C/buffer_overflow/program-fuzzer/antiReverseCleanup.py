import os

print "This file cleans up the files made by antiReverse.py, only works on linux."
print "[+] Cleaning up!"
os.system("rm real_gdb real_r2 fuzz_gdb fuzz_r2 real_output fuzzed_output")

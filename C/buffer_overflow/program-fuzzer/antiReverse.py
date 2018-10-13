import random
import os
import sys

def flipbyte(in_byte):
    i = random.randint(0, len(in_byte))
    c = chr(random.randint(0, 0xFF))
    return in_byte[:i] + c + in_byte[i+1:]

def alter(filename):
    with open(filename, "rb") as f, open(filename+"_fuzzed", "wb") as nf:
        nf.write(flipbyte(f.read()))
        f.close(); nf.close()
    os.system("chmod +x "+filename+"_fuzzed")

def compare(fn1, fn2):
    with open(fn1, "rb") as f1, open(fn2, "rb") as f2:
        val = f1.read()==f2.read()
        f1.close(); f2.close()
        return val

def checkOutput(filename, sarg):
    os.system("./"+filename+" "+sarg+" > real_output")
    os.system("./"+filename+"_fuzzed "+sarg+" > fuzzed_output")
    return compare("real_output", "fuzzed_output")

def check_gdb(filename):
    os.system("echo disas main | gdb "+filename+" > real_gdb")
    os.system("echo disas main | gdb "+filename+"_fuzzed > fuzz_gdb")
    return compare("real_gdb", "fuzz_gdb")

def check_radare(filename):
    os.system('echo "aaa\ns sym.main\npdf\n" | r2 '+filename+" > real_r2")
    os.system('echo "aaa\ns sym.main\npdf\n" | r2 '+filename+"_fuzzed > fuzz_r2")
    return compare("real_r2", "fuzz_r2")

def checkUsage():
    if len(sys.argv) == 2 or len(sys.argv) == 3:
        return 0
    else:
        print "\nUsage: python ./antiReverse.py <filename to be fuzzed> [arguments to the program]\n"
        print "This script only runs on linux and relys on gdb and radare2, so make sure those are installed."
        print "This tool is a fuzzer this makes the program undebuggable by gdb and radare2 and maybe some other debugging tool"
        print "This tool takes a file and some any one character to some other character and checks if the program"
        print "still works and if the debuggers are able to read the file, if no then it shows the file up."
        print "Important note: if the scripts shows that it found a perfect file then press ^C to inturrupt"
        print "do not press enter. first check if the program has succeeded or not!\n"
        sys.exit(1)

def main():
    checkUsage()
    filename = sys.argv[1]
    if len(sys.argv) == 3:
        arg = sys.argv[2]
    else:
        arg = ""

    while True:
        alter(filename)
        if checkOutput(filename, arg) and not check_radare(filename) and not check_gdb(filename):
            os.system("cat fuzz_gdb")
            os.system("cat fuzz_r2")
            print "\n[+] FOUND PERFECT FUZZED FILE"
            raw_input()

if __name__ == "__main__":
    main()

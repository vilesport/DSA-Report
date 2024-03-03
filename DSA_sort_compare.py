from pwn import *
import numpy as np
import datetime

Sort_Type = ["quick", "heap", "merge", "cpp"]
os.system('python3 ./Compile.py')
os.system('rm ./result.out')
ans = open("./result.out", "w")
for i in range(0, 4):
    ans.write(Sort_Type[i] + "sort:\n")
    for j in range(10):
        with process(["./C_sort/" + Sort_Type[i], "./Testcase/input" + str(j + 1) + ".inp"]) as test:
            ans.write(test.recvuntil(b'|').decode()[:-1] + "ms\n")

ans.write("numpysort:\n")
for j in range(10):
    with process(["python3", "./Python_sort/numpysort.py",  "./Testcase/input" + str(j + 1) + ".inp"]) as test:
        ans.write(test.recvuntil(b'|').decode()[:-1] + "ms\n")
ans.close()
os.system('cat ./result.out')
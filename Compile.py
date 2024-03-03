import os

sort_type = ["heap", "merge", "quick", "cpp"]
for i in range(4):
    os.system('g++ -o ./C_sort/' + sort_type[i] +' ./Sort_source/' + sort_type[i] + 'sort.cpp')
os.system('cp ./Sort_source/numpysort.py ./Python_sort/')
os.system('g++ -o ./Test_gen ./Test_genarate.cpp')
for i in range(10):
    os.system("./Test_gen " + str(i + 1))
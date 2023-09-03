#!/bin/bash

#test cases
arr=(10 20 50 100 200 500 1000)
# compile gen if not exist
if [ ! -f "./generate_map" ]; then
    echo "compiling map generator"
    g++ -o generate_map generate_map.cpp
fi
# compile program if not exist
if [ ! -f "./src/dijkstras" ]; then
    echo "compiling test progam"
    make clean && make
fi
# if the test files don't exist, gen them
if [ ! -e "./file_1.txt" ]; then
    for i in {1..7}
    do
        echo "Generating file with ${arr[$((i-1))]} as the dimension"
        ./generate_map ${arr[$((i-1))]} > file_$i.txt
    done
fi

# create MD table
printf '|   N     |    Elapsed Time    |  Memory Usage  |\n'
printf '|---------|--------------------|----------------|\n'
# for the test cases we have, get the time elapsed, mem used, and put them in MD table
for i in {1..7}
do  
    #valgrind --leak-check=full src/dijkstras < file_$i.txt > log.txt 2>&1
    #mem=`cat log.txt | grep 'bytes allocated' | cut -d ' ' -f 11`
    start=`date +%s.%N`
    src/dijkstras < file_$i.txt > /dev/null &
    pid=$!
    mem=`pmap -x $pid | grep 'total kB' | awk '{ print $3 }'`
    wait $pid
    end=`date +%s.%N`
    runtime=$(echo "$end - $start" | bc -l)
    printf '| %-7s | %-18s | %-14s |\n' "${arr[$((i-1))]}" "$runtime" "$((mem*1024))"
done 
# remove logfile from valgrind
#rm log.txt

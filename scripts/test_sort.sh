#!/bin/bash
g++ -O3 -o gen gen.cpp
make_files=true
myArray=("STL" "QSORT" "MERGE" "QUICK")
if [ -e "/home/ckornega/cs302/proj2/file_1.txt" ] 
then
    make_files=false
else 
    for i in {1..7}
    do 
        nums=$((10**i))
        echo "Generating $nums numbers..."
        ./gen $nums file_$i.txt
    done
fi

printf '|   Mode     |    Size    |  Elapsed Time  |\n'
printf '|------------|------------|----------------|\n'
for i in {1..4}
do 
    mode=${myArray[$((i-1))]}
    for j in {1..7}
    do
    size=$((10**j))
    start=`date +%s.%N`
    ./volsort -m $mode -n < file_$j.txt > /dev/null
    end=`date +%s.%N`
    runtime=$(echo "$end - $start" | bc -l)
    printf '| %-10s | %-10s | %-14f |\n' "$mode" "$size" "$runtime"
    done
done 
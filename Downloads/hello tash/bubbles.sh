#!/bin/bash
echo "no of elements"
read n
echo "enter nos "
for (( i = 0; i < $n; i++ ))
do
read nos[$i]
done
echo "nos are "
for (( i = 0; i < $n; i++ ))
do
echo ${nos[$i]}
done
for (( i = 0; i < $n; i++ ))
do
for (( j = $i; j < $n; j++ ))
do
if [ ${nos[$i]} -gt ${nos[$j]} ];
then
t=${nos[$i]}
nos[$i]=${nos[$j]}
nos[$j]=$t;
fi
done
done
echo "sorted : "
for (( i = 0; i < $n; i++ ))
do
echo ${nos[$i]}
done

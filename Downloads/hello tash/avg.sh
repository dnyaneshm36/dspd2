#!/bin/bash
n=5
sum=0
prod=1
echo "enter nos "
for (( i = 0; i < $n; i++ ))
do
read nos[$i]
done
for (( i = 0; i < $n; i++ ))
do
prod=$(( $prod * ${nos[i]} ))
sum=$(( $sum + ${nos[i]} ))
done
echo "sum = $sum"
echo "product = $prod"
avg=$(( $sum / 5 ))
echo "avg = $avg"


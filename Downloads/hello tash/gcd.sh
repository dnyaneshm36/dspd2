#!/bin/bash
echo "num1"
read a
echo "num2"
read b
m=$a
if [ $b -lt $m ]
then
m=$b
fi
while [ $m -ne 0 ]
do
x=$(( $a % $m ))
y=$(( $b % $m ))
if [ $x -eq 0 -a $y -eq 0 ]
then
echo $m
break
fi
m=$(( $m - 1 ))
done

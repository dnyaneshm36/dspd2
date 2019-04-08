#!/bin/bash
read n
i=2
sum=0
while [ $i -le $n ]
do
	sum=$(( $sum + $i ))
	i=$(( $i + 2 ))
done
echo "$sum"

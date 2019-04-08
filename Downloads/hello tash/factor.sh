#!/bin/bash
read num
i=1
while [ $i -le $num ]
do
	rem=$(( $num % $i ))
	if [ $rem -eq 0 ]
	then
		echo "$i "
	fi
	i=$(( $i + 1 ))
done

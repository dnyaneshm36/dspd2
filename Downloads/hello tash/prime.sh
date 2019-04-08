#!/bin/bash
read num
i=2
flag=0
while [ $i -lt $num ]
do
	rem=$(( $num % $i ))
	if [ $rem -eq 0 ]
	then
		flag=1
	fi
		i=$(( $i + 1 ))

done
if [ $flag -eq 1 ]
then
	echo "NO"
else
	echo "YES"
fi	

		

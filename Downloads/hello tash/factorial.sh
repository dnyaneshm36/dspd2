#!/bin/bash
read no
fact=1
while [ $no -ge 1 ]
do 
	fact=$(( $fact * $no )) 
	no=$(( $no - 1 ))
done
echo $fact	

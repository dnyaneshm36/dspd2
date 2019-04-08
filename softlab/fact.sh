#!/bin/bash
fact=1
echo -e "enter a number"
read n
if [ $n -le 0 ] ; then
echo "invalid number"
exit
fi
#factorial logic
if [ $n -gt 0 ] ; then
for((i=$n;i>=1;i--))
do
fact=$((fact* i))
done
fi
echo "The factorial of $n is $fact"


a[0]=12
a[1]=2
a[2]=4
a[4]=3
a[3]=

for((i=0;i<=4;i++))
do
	for((j=0;j<=4;j++))
	do 
	   if[];then
	   temp=${a[$j]}
	   a[$j]=$a[(j+1)$]
	   a[]=$temp
	   fi
	done
done

	for((j=0;j<=4;j++))
	do
	 echo $a[i] 
	done

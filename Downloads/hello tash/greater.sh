#!/bin/bash
echo "num1"
read first
echo "num2"
read sec
echo "num3"
read third
if [ $first -gt $sec ] ; then
if [ $first -gt $third ] ; then
echo -e " $first is greatest " 
else
echo -e " $third is greatest "
fi
else
if [ $sec -gt $third ] ; then
echo -e " $sec is greatest "
else
echo -e " $third is greatest number "
fi
fi


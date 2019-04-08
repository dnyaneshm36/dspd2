#!/bin/bash
echo "length of square "
read l
per=$(( 4 * $l ))
area=$(( $l * $l ))
echo " area = $area perimeter = $per "
echo "length of rectangle "
read lt
echo "breadth of reactangle"
read br
peri=$(( 2 * $lt + 2 * $br ))
arear=$(( $lt * $br ))
echo " area = $arear perimeter = $peri "

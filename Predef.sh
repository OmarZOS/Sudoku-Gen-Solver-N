#!/bin/bash

echo "Please insert the length of the little square of your grid"

read size

echo "Now insert your matrix filename"

read file

echo $size > tmp $file

g++ Predefine.cpp -o pred



(  ./pred < tmp  ) > dimac.cnf

rm pred

cat dimac.cnf | grep 'n: ' > tmp2

sed -i "/n: /d" dimac.cnf

sed -e "s/n://g" -i tmp2

sed -e "s/hil/$(cat tmp2)/g" -i dimac.cnf

rm tmp2

cadical dimac.cnf > solution

cat solution | grep 'v '> soly

sed -e "s/v //g" -i soly

sed -e "s/ 0//g" -i soly

g++ converter.cpp -o hey

sed -i "/v /d" solution

cat solution 

(./hey < tmp )

rm soly

rm hey

rm tmp

rm solution










#!/bin/bash


echo "Enter your N and press [ENTER] : (Keep in mind that your grid will be \n(NxN)x(NxN) )" 

read size

echo $size > tmp

g++ Globe.cpp -o test

(./test < tmp )  > dimac.cnf

rm test

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

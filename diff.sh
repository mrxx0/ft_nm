#!/bin/zsh

./ft_nm $1 > ft_nm.txt
nm -p $1 > nm.txt


DIFF=$(diff -uN ft_nm.txt nm.txt)

if [ "$DIFF" != "" ]
then
	echo $1
	echo "Diff START"
	echo $DIFF
	echo "Diff END"
	echo -e "\n"
fi
rm -r ft_nm.txt nm.txt


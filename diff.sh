#!/bin/zsh

./ft_nm $1 > ft_nm.txt
nm $1 > nm.txt


DIFF=$(diff -ya --suppress-common-lines ft_nm.txt nm.txt)

if [ "$DIFF" != "" ]
then
echo -e "\e[31mFailed on $1\e[0m"
	# echo "Failed on $1 :"
	echo $DIFF
else
	echo -e "\e[32mOK on $1\e[0m"
fi
echo ""
rm -r ft_nm.txt nm.txt


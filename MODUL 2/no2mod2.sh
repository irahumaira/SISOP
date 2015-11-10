#!/bin/bash

read n
for i in `seq 1 $n`;
do
count=0
	for j in `seq 1 $n`;
	do
		if [ $(( i%j )) -eq 0 ];
		then 
			let "count=$count+1"
		fi
	done
if [ $count -eq 2 ];
then echo "$i "
fi
done

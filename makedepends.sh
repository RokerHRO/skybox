#!/bin/sh

rm .depends

for F in $@ ; do
	INC=`echo $F | sed 's/\([a-z0-9]*\)_.*/\1/g'`
	echo $F : ${INC}.inc >> .depends
	echo >> .depends
done

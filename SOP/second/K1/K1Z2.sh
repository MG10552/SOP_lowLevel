#!/bin/bash

find $1 -type f -printf "%U %p\\n" | while read zm1 zm2
do
path=‘dirname $zm2‘
if [ $zm1 -eq "find $path -maxdepth 0 -printf '%U'" ]; then
echo "$zm2 należy do uzytkownika %U"
fi
done

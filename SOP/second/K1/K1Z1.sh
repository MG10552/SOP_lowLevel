#!/bin/bash

for szukajdowoduosobistego in $( | grep -E '^[upper]([a-z])*[0-9]+$')
do
echo "Tak, $szukajdowoduosobistego jest identyfikatorem dowodu osobistego"
done

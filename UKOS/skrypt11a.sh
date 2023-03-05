#! /bin/bash

ZM=x
echo "Wartość zmiennej ZM przed funkcją: $ZM"
echo "Wartość zmiennej ZM1 przed funkcją: $ZM1"
function fun ()
{
 # local ZM
 echo "Wartość zmiennej ZM w funkcji: $ZM"
 ZM=xx
 echo "Wartość zmiennej ZM w funkcji po zmianie: $ZM"
 # local ZM_A
 ZM1=xxx
 echo "Wartość zmiennej ZM1 w funkcji: $ZM1"
}
fun
echo "Wartość zmiennej ZM po funkcji: $ZM"
echo "Wartość zmiennej ZM1 po funkcji: $ZM1"




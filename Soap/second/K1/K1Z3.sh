#!/bin/bash

for plik in $(~/opt/bin)
do
	case $plik in
		*.10552 ) ./ $plik /tmp ;;
		* ) echo "Rozszerzenie jest inne od wymaganego, $plik zostanie pominięty.\n" ;;
	esac
done



#! /bin/bash
apt-get update
apt-get install dialog
dialog --title "Komunikat" --infobox \
"\n  Polecenie dialog \n  zainstalowano \n  poprawnie!" 10 25
read X








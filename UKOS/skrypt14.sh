#! /bin/bash
dialog --title "Okno yesno" --yesno "Ladne to okno?" 10 20
echo $? >yesno

dialog --title "2 Okno yesno" --yesno "Ladne to okno?" 25 10
echo $? >>yesno





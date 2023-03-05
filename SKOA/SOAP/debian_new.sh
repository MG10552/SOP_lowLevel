#!/bin/bash
clear
echo Pakowywanie pliku DEBIAN_NEW.vhd do DEBIAN_NEW.tar.gz
tar -czvf ~aadolph/Publiczny/SOP2014/DEBIAN_LAB.tar.gz /work/DEBIAN_NEW
ls -l ~aadolph/Publiczny/SOP2014/DEBIAN_LAB.tar.gz
tar -tzvf ~aadolph/Publiczny/SOP2014/DEBIAN_LAB.tar.gz
echo Rozpakowywanie pliku DEBIAN_NEW.vhd do /work
tar -zxvf ~aadolph/Publiczny/SOP2014/DEBIAN_LAB.tar.gz -C /work DEBIAN_NEW.vhd
ls -l /work/DEBIAN_NEW.vhd
echo Prosze nacisnąc eneter
read y 


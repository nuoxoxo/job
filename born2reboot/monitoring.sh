#!/bin/bash

wall  "#Architecture: $(uname -a)
#CPU physical : $(lscpu | awk 'NR==5 {print $2}')
#vCPU : $(lscpu | awk 'NR==9 {print $2}')
#Memory Usage: $(free --mega | awk 'NR==2 {printf "%s/%sMB (%.2f%%)\n", $3, $2, $3 * 100 / $2}')
#Disk Usage: $(df --human | awk 'NR==4 {printf "%.0f/%.1fGB (%s)\n", $3 * 1024, $2, $5}')
#CPU Load: $(top -bn1 | awk 'NR==3 {printf "%.1f%%\n", $4 + $2}')
#Last boot: $(who -b | awk ' {print $3, $4}')
#LVM use: $(/usr/sbin/lvm pvdisplay | grep Allocatable | awk '{print $2}')
#Connexions TCP : $(netstat | grep tcp | wc -l) ESTABLISHED
#User log: $(users | wc -w)
#Network: IP $(hostname -I | awk '{print $1}')($(ip a | grep ether | awk '{print $2}'))
#Sudo : $(grep COMMAND /var/log/sudo/sudo.log | wc -l | awk '{printf "%d cmd\n", $0}')
"

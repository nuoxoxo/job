#!/bin/bash

wall  "
      #Architecture: $(uname -a)


      #CPU physical : $(lscpu | awk ' NR==5 {print $2}')
      #CPU physical : $(grep "physical id" /proc/cpuinfo | uniq | wc -l)


      #vCPU : $(lscpu | awk ' NR==9 {print $2}')
      #vCPU : $(grep "processor" /proc/cpuinfo | uniq | wc -l )


      #Memory Usage: $(free --mega | awk 'NR==2 {printf "%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }')
      #Memort Usage: \
      $(free -m | grep "Mem:" | awk '{print $3}')/$(free -m | grep "Mem:" | awk '{print $2}')Mb \
      ($(free -m | grep "Mem:" | awk '{printf("%.2f"), $3/$2*100}'))


      #Disk Usage: $(df -h | awk 'NR==4 {printf "%.1f/%.1fGB (%s)\n", $3 / 1024,$2,$5}')
      #Disk Usage: \
      $(df -m --total | grep "total" | awk '{print $3}')/$(df -h --total | grep "total" | awk '{printf ("%.0f"), $2}')Gb \
      ($(df -h --total | grep "total" | awk '{print $5}'))


      #CPU Load: $(top -bn 1 | awk 'NR==3 {printf "%.2f%%\n", $4 + $2}')
      #CPU Load: $(mpstat | grep "all" | awk '{print 100-$13}')


      #Last boot: $(who -b | awk ' {print $3,$4}')


      #LVM use: $(/usr/sbin/lvm pvdisplay | grep Allocatable | awk '{print $2}')
      #LVM use: $(if [ $(lsblk | grep -c "lvm") -eq 0 ]; then echo "no"; else echo "yes"; fi)


      #Connections TCP : $(ss -s | grep TCP | awk 'NR==2 {printf "%d ESTABLISHED\n", $3}')
      #Connections TCP : $(netstat | grep "tcp" | wc -l) ESTABLISHED


      #User log: $(who | wc -l)
      #User log: $(users | wc -w)


      #Network: IP $(hostname -I)$(ip a | grep link/ether | awk '{printf "(%s)\n", $2}')
      #Network: IP $(hostname -I | awk '{print $1}') ($(ip a | grep ether | awk '{print $2}'))


      #Sudo : $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l | awk '{printf "%d cmd\n", $0}')
      #Sudo : $(grep "COMMAND" /var/log/sudo/sudo.log | wc -l)
      "

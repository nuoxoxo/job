# Rules
* Getting started
* Signature
* LVM
* SU
* vim . man
* Sudo
* Sudo group
* AppArmor
* SSH
* UFW
* Connect SSH server
* Pwquality
* Create new groups
* Banner
* Wall
* work to be done before cron
* Cron

―


* Getting started
  * Download the `debian-11.2.0-amd64-netinst.iso` 
    * small core set of text-mode programs (known as "standard" in Debian)
  * Memory size: 1024
  * Create a virtual hard disk
  * VDI 
    * vid = virtualbox disk image
    * vhd = virtual hard disk
    * vmdk = virtual machine disk
  * Dynamically allocated
  * 12.00 GB
  * Settings - Storage
  * IDE - Choose debian image
  * Start
  * Hostname: LOGIN42
  * Domain name: (default)
  * Root pw: 123
  * New user: nxu
  * pw: 123
  * Partition method
    * Guided - entire disk - set up encrypted LVM
  * Partition disks
    * separate /home:/var:/tmp partitions
  * Encryption passph: 123
  * GRUB boot loader: 
    * Yes
  * Device for boot loader installation:
    * /dev/sda (the long one)

* Signature
```sh
$ ~/VirtualBox VMs/
$ sha1sum ___whatever___$(serv).vdi

. . .
6e657c4619944be17df3c31faa030c25e43e40af
. . .
```

# LVM - create 2 encrypted partitions w. lvm

![](https://i.imgur.com/YXgYRf6.png)

By default

# su

Login as root

```
$ su -
Password:

```

# vim & man
```sh
$ apt-get update -y
$ apt-get upgrade -y
```
> `-y` / `--yes` / `--assume-yes` means assume yes to prompts automatic
```sh
$ apt-get install vim
$ sudo apt-get install man-db
```

# sudo
Install *sudo*
```
$ apt install sudo

And aggressively do
$ apt install sudo vim ufw tree curl wget git man-db openssh-server libpam-pwquality sysvbanner banner 
# # Unable to locate banner
```
verify
```
$ man sudo

$ dpkg -l | grep sudo
>> (sudo) apt list --installed | grep sudo
```
add (your) usr to *sudo* group
```
$ usermod -aG sudo <usr>

or

$ adduser <usr> sudo
```
verify
```
$ getent group sudo

or

$ groups <usr>
$ groups root
$ groups test

or

$ id <usr>
$ id root
$ id test
```
grant su privilege
```
$ sudo visudo

or

$ vi /etc/sudoers

or

$ sudo vi /etc/sudoers.d/rules

>> (the sys will parse automatically any file under sudoers.d dir that 
(1) not ended with `~` and (2) not containing a `.`)

. . .
<usr> ALL=(ALL) ALL
. . .
```
```sh
# 1st ALL: this rule applies to all hosts
# 2nd ALL: as a <usr>, i can run commands as all users
# 3rd ALL: in case of `...=(...:ALL) ...`, as a <usr> i run cmds like all groups
# last ALL: these rules apply to all cmds
```

`-v` . `--validate` - authenticate / update usr's cached credentials
```scala
$ reboot


. . .
Debian GNU/Linux 10 <hostname> tty1

<host> login: <usr>
Password: <pwd>
. . . 

$ sudo -v

[sudo] password for <usr>: <pwd>

$ sudo apt update 

// From here on, run root-privileged cmds w. sudo
```

_ps._ in case log path not present
```
$ sudo mkdir /var/log/sudo
```

# sudo group - *this time we set extended rules*

Config *sudo* - edit _config_ file
- edit `/etc/sudoers.d/__file__`
```sh
$ sudo visudo

or

$ sudo vi /etc/sudoers.d/_file_
$ sudo vi /etc/sudoers.d/rules
```

- pwd
```sh
Defaults	passwd_tries=3
Defaults	badpass_message="Invalid credentials. Please try again."
```

- log
```sh
Defaults	iolog_dir="/var/log/sudo"
Defaults	logfile="/var/log/sudo/<____file____>"
Defaults	log_input,log_output
```

- tty - teletypewriter
```sh
Defaults	requiretty
```

- set *sudo* paths
```sh
Defaults	secure_path=\
"/usr/local/sbin:\
/usr/local/bin:\
/usr/sbin:\
/usr/bin:\
/sbin:\
/bin:\
/snap/bin"
```

- _(condensed)_
```scala
$ sudo vi /etc/sudoers.d/_file_

or

$ sudo vi /etc/sudoers.d/rules # naming --> rules


. . .
Defaults	passwd_tries=3
Defaults	badpass_message="<____errormsg____>"
Defaults	iolog_dir="/var/log/sudo"
Defaults	logfile="/var/log/sudo/<____file____>" # naming --> logfiles
Defaults	log_input,log_output
Defaults	requiretty
Defaults	secure_path=\
"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
. . .
```


# apparmor

list current status of apparmor
```
$ sudo aa-status

>> module is loaded
```


inspect current state
```
$ cat /sys/module/apparmor/parameters/enabled

>> Y
```

list available profiles
```
$ ls /usr/share/apparmor/extra-profiles/

>> (??) no such file or dir
```

# secure shell protocol

Install _open ssh server_
```cobol
$ sudo apt install openssh-server

$ dpkg -l | grep ssh
$ sudo systemctl status ssh

$ man ssh
$ man openssh-server (?? doesn't work)
```

Edit `/etc/ssh/shd_config`
```
$ sudo vi /etc/ssh/shd_config
```

Check status
```scala
Either
$ sudo service ssh status

or

$ systemctl status ssh
On Mac
$ sudo systemsetup -getremotelogin


$ service ssh restart
$ 

```
Keep only one port 
- replace `Port` 22 w. 4242 
Make _SSH_ only available on port 4242 
- replace `#PermitRootLogin prohibit-password` w. `PermitRootLogin no`


verify
```
$ sudo grep Port /etc/ssh/sshd_config
$ sudo service ssh restart
$ sudo grep Port /etc/ssh/sshd_config
```
# uncomplicated firewall

Install _uncomplicated firewall_
```
$ sudo apt install ufw
$ dpkg -l | grep ufw
```

Allow incoming conns via port 4242 
```
$ sudo ufw enable
$ sudo ufw status
$ sudo ufw status verbose


$ sudo ufw allow ssh
$ sudo ufw allow 4242


$ sudo ufw status
$ sudo ufw status verbose
```

( list all rules . delete rule . reset )
```scala
$ sudo ufw status numbered
$ sudo ufw delete <number>
$ sudo ufw reset
```

# connect SSH server

_ssh_ into the VM via 4242
```
$ ssh <usr>@<vmip> -p 4242
$ (do things)
$ logout OR exit
```

or in gui 
```
Settings . Network . Adapter 1 . 
Attached to: check NAT . Advanced: heck Cable conn . Port Forwarding
```
back to Network
```
Network . Rule 1 row . Protocol: TCP . Host Port: 4242 . Guest Port 4242
```

```
$ sudo systemctl restart ssh

$ sudo service sshd status 
>> (see ip at line "listening on _._._._ port 2121")

$ ssh usr@_._._._ -p 2121

$ exit
```

# network 
* edit `/etc/network/interfaces`
```sh
iface enp0s3 inet dhcp
iface enp0s3 inet static
```
* edit `/etc/network/interfaces.d/__file__`
```sh
iface enp0s3 inet static
address <vm-ip>
netmask <vm-netmask>
gateway <vm-gateway>
```

# password quality

Age __ edit `/etc/login.defs`
```scala
$ sudo vi /etc/login.defs


. . .
PASS_MAX_DAY    30  # pw expires every 30 days 
PASS_MIN_DAYS   2   # min days to mod again: 2
PASS_WARN_AGE   7   # warning msg 7 days before pwd expires
. . .
```

( Alternative approach to change Age )
```scala
$ chage -M 30 <usr>
$ chage -m 2  <usr>
$ chage -W 7  <usr>
```

Strength __ edit `/etc/pam.d/common-password`

- from _libpam_ import _pwquality_ 
```
$ sudo apt-get install libpam-pwquality
$ dpkg -l | grep pwquality
$ man pwquality.conf 
```
> ^ pluggable authentication module

- edit `/etc/pam.d/common-password`
```scala
$ sudo vi /etc/pam.d/common-password
or
$ sudo nano /etc/pam.d/common-password


. . .
password   requisite     pam_pwquality.so retry=3
. . .

. . . (minlen=10 can be added here:)
password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10 
. . .
```

append to `retry`:
```scala
minlen=10
ucredit=-1      # uppercase . minus means At Least
dcredit=-1      # digit
maxrepeat=3     # consecutive identical chars < 4
difok=7         # dif ok . must have at least 7 chars diff from prev pw (exc. for root)
                # ?? subject dictates that this rule should not apply to root ??
reject_username
enfore_for_root
```

verify
```scala
$ sudo chage -l <usrname>
```
> `chage` change_age . changes the num of days btw pw mods and the date of the last change
> `chage` is restricted to the root; `-l` may be used by an unprivileged usr  

# Create a new group (UFT)

addgroup . adduser|usermod
```r
$ sudo addgroup UFT


$ sudo adduser <usr> UFT
or
$ sudo usermod -aG UFT <usr>


# check all local usrs
$ cut -d: -f1 /etc/passwd
$ groups
$ chage -l <usr>


$ getent group
$ getent group UFT
$ 
```

# banner

```j
$ sudo apt install sysvbanner
or
$ sudo apt install banner # Unable to locate banner
```

# wall

optional dependencies `net-tools` & `sysstat`
```sh
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


#Connetions TCP : $(ss -s | grep TCP | awk 'NR==2 {printf "%d ESTABLISHED\n", $3}')
#Connetions TCP : $(netstat | grep "tcp" | wc -l) ESTABLISHED


#User log: $(who | wc -l)
#User log: $(users | wc -w)


#Network: IP $(hostname -I)$(ip a | grep link/ether | awk '{printf "(%s)\n", $2}')
#Network: IP $(hostname -I | awk '{print $1}') ($(ip a | grep "ether" | awk '{print $2}'))


#Sudo : $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l | awk '{printf "%d cmd\n", $0}')
#Sudo : $(grep "COMMAND" /var/log/sudo/__LOG__ | wc -l)
"
```


# work to be done before cron

```
$ sudo visudo


. . .
<usr> ALL=(ALL) NOPASSWD:
/root/monitoring.sh
. . .
```


# cron

config (-e) cron table (-u root)
```scala
$ sudo crontab -u root -e
(or just crontab -e)

. . .
*/10 * * * * sh /root/monitoring.sh

or

*/10 * * * * /bin/sleep $(last --time-format iso reboot | head -1 | awk -F ":" '{printf ("\%d", $2\%10*60+$3)}') && (sh) /root/monitoring.sh
. . .

$ sudo reboot
$ 
```

[cf. pihole on ink](https://github.com/nuoxoxo/pihole-on-ink) \
[crontab parameter](https://bencane.com/2012/09/03/cheat-sheet-crontab-by-example/)


> in case of cronjob error \
> `drm:vmw_host_log *ERROR* Failed to send host log message.` \
> [fix](https://unix.stackexchange.com/questions/502540/why-does-drmvmw-host-log-vmwgfx-error-failed-to-send-host-log-message-sh)


# defend

check curr host
```
$ hostnamectl
```
change hstname
```
$ hostnamectl set-hostname <_new_hstname_>
```
edit `/etc/hosts`
```
$ 127.0.0.1 localhost
^^^
$ 127.0.0.1 <_new_hstname_>
$ sudo reboot
```

# debian _vs_ centos

&nbsp; | Debian | CentOS
-|-|-
GUI | complicated | usr-friendly apps and GUI
Maintenance | by individual usrs | by Red Hat community
Package manager | apt-get | YUM as rpm
Package base | vast | limited
Release | 2-year cycle, easy to fix bugs | long interval, thus stable
Update | install new | easy updating from prev ver.
Market | less market bc limited end usage | large market bc user-friendly
Architecture | rich arch. support | less arch. support

# apt _vs_ aptitude

&nbsp; | apt | aptitude
-|-|-
first glance | (like c) | (like c++)
main difference | low-lv pm thus used by other hi-lv pms | hi-lv pm
functionality | low-lv func. | more diverse
functionality_ | system upgrade, purge package, resolve dependencies | integrates `apt-get` `apt-mark` `apt-cache`

# selinux _vs_ apparmor

both are securtity systems, both isolate attackers \
from the rest of system when an app is compromised

&nbsp; | SELinux | APPArmor
-|-|-
rule complexity | complex | straight forward
&nbsp; | labels all files & processes | pathname-based system need no labeling
&nbsp; | as profiles++ current profiles mod to split channels | even on extensive amount all profiles refer to pathnames
&nbsp; | not all apps preserve labels | pathnames are easy to comprehend & audit
&nbsp; | incremental policy development is difficult | &nbsp;
writing rules | policies generation can be automated | can be handwritten 
&nbsp; | &nbsp; | auto-gen using `aa-logprof`
hence | more ctrl on isolating processes | path based control, transparency++
identify attacks | hard to verify independently | easy to verify independently
mainenance | hard to maintain | use automated tools
ease of use | complex policy language | auditable policies
&nbsp; | hard to manage rules, lack of integrated tools | GUI and console toolset
&nbsp; | learning curve++ | training takes 2 days max
&nbsp; | low adoption rate | easy integration with novell platforms

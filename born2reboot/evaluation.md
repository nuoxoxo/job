### General

###### check signature.txt - diff the 2 signatures

```fortran
$ shasum borntoberoot.vdi > signature.txt
$ shasum borntoberoot.vdi > eval.txt
$ diff *.txt 
$ cat *.txt
```

### Question time

```fortran
$ HOW a vm works ??
  an image file that works like an actual computer with a diff OS and environment

$ CHOICE of the os ??
  debian - simpler and more distro-ish

$ CentOS vs. debian

  - GUI     - centos has a user-friendly interface
            - debian looks complicated
  - Mainte. - debian is maintained by individuals
            - centos by Red Hat community
  - Packag. - debian uses apt, hence `apt-get`
            - centos uses Redhat Package Manager (.rpm)
  - Soft    - debian has a vast selection
            - centos software choices are limited
  - Archit. - debian = rich architecture support
            - centos has LESS support
  - stab    - debian has a 2-year release cycle, bug fixed frequently
            - centos is more stable due to long release cycle
  - Market  - debian has SMALLER market
            - people love centos because of its GUI 

$ WHY use VM

  - the question if Physical M. vs. Virtual M.
  - VMs are easy to manage and maintain
  - we can run mult. operating system env. on a single physical machine
  - saving physical space, time and management costs

$ aptitude vs. apt

  comp - apt is like C, aptitude C++
  rel. - aptd is created for Debian is front-end for apt 
  apt  - low level, so that higher level PMs can use apt
  aptd - high level, aptd has a user-interface, allowing package search
  cmd - apt   - /apt-get/ to install, upgrade, purge and resolve dependencies
        aptd  - /apt-cache/ and /apt-mark/ to handle more complex tuff
  
$ apparmor ??

  what - a Linux kernel security module
  goal - goal is to bound programs to limited resources
          ie. isolate programs from each other
  how  - controls access based on the paths of program files
  feat - more transparent due to path-based control
  advn -  1. EASY to verify a specific attack
          2. straight forward, easier for administration
```

### (side quest) - cronjob
```
$ sudo crontab -l

syntax:
* * *   * * 
m h dom m dow
```

### (side quest) - unable to resolve host

```sh
$ cat /etc/hosts
$ vi /etc/hosts
  ---> add: 127.0.0.1 fink512
```

### simple setup

```sh
  Be sure that no graphical env. is present
$ ls /usr/bin/*sessions ----------(n/a)
$ ls /usr/share/xsessions --------(n/a)
$ ls /usr/share/wayland-sessions -(n/a)
$ ls /usr/share/


$ sudo servise ssh status
$ sudo ufw status
$ sudo ufw deny 4242
$ sudo ufw allow 4242
$ ssh mother@0.0.0.0 -p 4242         <- connect from host (physical)
$ sudo service ssh restart            <- reset
(or) $ sudo systemctl restart ssh          <- reset 
```

### user

```fortran
$ id -u /fink/
$ id -u test
$ sudo adduser funk
$ getent group sudo
$ getent group fink21
$ sudo adduser funk fink21
```

- [x] user with login as name inside `sudo` and `user42`
- [x] pw set up policy : $ vi /etc/pam.d/common-password 
- [x] pw expiry policy : $ vi /etc/login.defs  

### Hostname & partitions

```fortran
  check and mod. hostname
$ sudo hostnamectl
$ sudo hostnamectl set-hostname _fink
$ sudo systemctl reboot
(change it back again.)

  view partitions
$ sudo  fdisk -l
$       lsblk
```

- what is LVM ?? 

LVM stands for Logical Volume Management \
It is a system of managing logical volumes, or filesystems, more advanced and flexible than the traditional method of partitioning a disk into one or more segments and formatting that partition with a filesystem.

- why not resize and move partitions ?? 

GParted you can expand and shrink partitions, but only if they are not in use \
LVM can expand a partition while it is mounted

- how LVM works 

lvm works by chunking the physical volumes (PVs) into physical extents (PEs) \
PEs are mapped onto logical extents (LEs) which are then pooled into volume groups (VGs) \
These groups are linked together into logical volumes (LVs) that act as virtual disk partitions and that can be managed as such by using LVM.



### SUDO

```fortran
  check if sudo is installed
$ sudo
(or) $ sudo -l
(or) $ dpkg -l | grep sudo

  check sudo command logs
$ sudo ls /path/
$ sudo tree
$ sudo cat /path/sudo.log
```


### UFW

```fortran
  check if UFW is installed
$ dpkg -l | grep ufw
$ sudo ufw status
$ sudo ufw allow 8080
$ sudo ufw status numbered
$ sudo ufw delete 2
$ sudo ufw delete 3
```


### SSH

###### check if only port 2121 in use
```fortran
$ cat /etc/ssh/sshd_config | grep -i port
```
```fortran
$ sudo systemctl restart sshd
$ ssh-keygen

$ ssh-copy-id -p 2121 fink@_._._._
```
```fortran
$ ifconfig getifaddr en0
```


### script + cronjob

```fortran
$ * * * * *           /monitor.sh
$ * * * * * sleep 30; /monitor.sh
```


----

### Q & A

```fortran
debian vs. centos

- (read the following like fiction)
- GUI     - centos has a user-friendly interface, debian looks complicated
- Mainte. - debian is maintained by individuals, centos by Red Hat community
- Packag. - debian uses `apt-get`, centos uses Redhat Package Manager (.rpm)
- Soft    - debian has a vast selection, for centos software choices are limited
- Archit. - rich architecture support, centos has LESS support
- Release - debian has a 2-year release cycle, bug fixed frequently
- Stable  - centos is more stable due to long release cycle
- Market  - debian has SMALLER market, on the other hand people love centos GUI 
```
```fortran
APT

short for "Advanced Packaging Tool"
initially designed for the Debian .deb packages
a free and open source software that handles software
it has been made compatible with RPM Package Manager.
```
```fortran
Aptitude 

initially created for Debain
front-end to APT 
it added a user interface, allowing users to interactively search package. 
it has been made compatible with RPM based distributions as well.
```
```fortran
APT vs. Aptitude

APT is like C
Aptitude, C++

apt is low level, so it can be used by high level pms
aptitude is a high level pm, functionality more diverse

apt uses /apt-get/ to install/upgrade/purge/resolve dependencies etc.
aptitude added /apt-cache/ /apt-mark/ to handle more stuff

```
```cobol
SELinux AppArmor are both are security systems
they isolate applications from each other
thus isolate an attacker from the rest of the syst when one app is compromised.
```
```sh
# SELinux
controls access based on the labels of the files and processes

rule sets are often complex 
complexity leads to more control over how processes are isolated
generating these policies can be automated 
HARD to independently verify attacks

SELinux system is more secure
```
```sh
# AppArmor
controls access based on the paths of the program files

profiles can be handwritten by humans or generated
path-based control leads to more transparence
EASY to independently verify attacks

apparmor is very straight forward, easier in administration
```

<!---

### Tasks

- at least 2 encrypted partitions ... lsblk
- create new account, ssh into it using port 4242
- check if 4242 is the active port
- check if root is unavailable via ssh
- check if UFW firewall is activated
- check hostname (format: /login/42)
- modify hostname, modify it again to /login/42
- check password policy
  - expiry in _ days : 30
  - min days to wait for mod: 2
  - msg _ days before expire: 7
  - pw must be >=10 chars
  - pw must contain an Upper and a Num
  - pw must not have >3 consecutive identical chars
  - pw must not have username in it
  - pw policy applies to root except the one below
  - * pw must be >=7 chars different than prev pw
- check sudo config, check if sudo uses strict rules
  - limit of 3 incorrect pw attempts
  - custom msg appears if sudo pw fails
  - archival of all sudo in/output
  - archive of sudo is set to /var/log/sudo/
  - check if TTY is enabled
  - sudo path restricted to:
    - / usr / local / sbin:
    - / usr / local / bin:
    - / usr / sbin:
    - / usr / bin:
    - / sbin:
    - / bin:
    - / snap / bin
- check all users (must have user with name /login/)
- user /login/ belongs to 2 groups: user42, sudo
- create new account, assign it to a group(s)
- check script
  - look once more at all cmds used in `monitoring.sh`
  - check if you know how to use `crontab`
- extra
  - head -n 2 /etc/os-release
  - (sudo) aa-status
  - ss -tunlp
  - (sudo) ufw status

--->

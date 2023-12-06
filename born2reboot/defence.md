[cheesesheet](../born_to_reboot/cheesesheet.md)

&nbsp;

###### To begin

```fortran
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\
| Create a new user :                   |
|                                       |
| $ sudo adduser username               | <- creating new user
| $ sudo chage -l username              | <- Verify password info for new user
| $ sudo adduser username testing       |
| $ sudo adduser username g1            | <- assign new user to various groups
| $ (sudo) usermod -aG g1 userlol       | <- alternatively
| $ getent group sudo                   |
| $ sudo:x:21:test,fink42,kimgord0n     |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//

```

###### Things to check

```fortran
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\
| $ lsblk                               | <- Check partitions
| $ sudo aa-status                      | <- Check AppArmor status
| $ getent group sudo                   | <- Check sudo group users
    $ getent group testing
    $ getent group g1    
| $ sudo service ssh status             | <- ssh
    $ ssh mothership@0.0.0.0 -p 4242         <- connect from host (physical)
    $ sudo service ssh restart            <- reset ssh
    $ sudo systemctl restart ssh          <---┛
| $ sudo ufw status                     | <- ufw (allow, deny, status)
    $ sudo ufw deny 4242
    $ sudo ufw status
    $ sudo ufw allow 8080
    $ sudo ufw allow 4242
    $ sudo ufw deny 8080
| $ sudo visudo
    $ ls /etc/sudoers.d/
    $ vi /etc/sudoers.d/rule
| $ vi /etc/login.defs                  | <- password expire policy
| $ vi /etc/pam.d/common-password       | <- password policy
| $ sudo crontab -l                     | <- cron schedule (remember to `sudo`)
    $ sudo crontab -e
| $ sudo ls /var/log/sudo/
    $ sudo cat /var/log/sudo/ _ / _ / _ /log    | <- browse log folders
| $ sudo hostnamectl set-hostname <new name>    | <- change host name
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

```

###### -

###### Q&A

```fortran
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\

- * Difference between aptitude & apt

- create at least 2 encrypted partitions

| $ lsblk


- * what is SELinus
- * what is AppArmor

- create new account & add to group
- a user with your login as username has to be present
- user has to belong to the user21 and sudo groups

| $ sudo adduser fink
| $ sudo groupadd user21

| $ sudo adduser fink sudo 
| $ getent group sudo

| $ sudo adduser fink user21 
| $ getent group user21


- it must not be possible to connect using SSH as root for security reasons

| $ grep -i permit /etc/ssh/sshd_config


- a SSH service will be running on port 4242 only

| $ grep -i port /etc/ssh/sshd_config


- check the UFW

| $ sudo ufw status
| $ sudo ufw allow 4242
| $ sudo ufw deny 22/tcp


- connect local to fink via ssh

| $local: ssh fink@0.0.0.0 -p 4242


- use "/login/42" as the hostname of the vm

| $ sudo hostnamectl set-hostname fink42
| $ hostnamectl


- pw (1) - "login.defs"

| $ grep -i pass /etc/login.defs
| $ 
| $ sudo chage -l fink

  - expire in _ days: 30
  - at least _ days before modification: 2
  - warning message _ days before exp.: 7


- pw (2) - "pam.d/common-password"

| $ vi /etc/pam.d/common-password

  - at least 10 chars long 

    minlen=10

  - must contain an Up letter and a number

    ucredit=-1

  - must not contain >3 consecutive identical chars

    maxrepeat=3

  - must not include the name of the user 

    usercheck=1

  - must have <7 chars that are part of former pw (not for root) 

    enforce_for_root (by default won t check the above rule)

  - root pw has to comply with the policy 

    change root pw immediately


- config sudo group (1) - many small things

| $ grep -i default / etc/sudoers.d/rules
  or
| $ sudo visudo

  - auth using sudo limited to 3 attempts in the event of an incorrect pw

    Defaults     passwd_tries=3

  - custom message due to wrong pw

    Defaults     badpass_message="..."

  - archive each action using sudo, incl. inputs/outputs, log file saved in /var/log/sudo/

    Defaults     iolog_dir="..."
    Defaults     logfile="..."
    Defaults     log_input,logoutput

  - tty mode enabled for security reasons

    Defaults     requiretty


- config sudo group (2) - restrict paths used by sudo

(dont use grep)

| $ cat /etc/sudoers.d/rules
  or
| $ sudo visudo

\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
```

tips from subjects

```fortran
$ sudo
$ head -n 2 /etc/os-release
$ aa-status
$ ss -tunlp
$ ufw status
```
```

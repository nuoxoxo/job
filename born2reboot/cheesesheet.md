[defence](../born_to_reboot/defence.md)

&nbsp;

## Format : task - command - what it means

- ###### disk: 123QWEasd . vm: test . 123QWERTYasd . root: 123
- Login as root - `su -` - switch user
- List partitioning - `lsblk` - list block devices
- User and group
  - Add user to group - two ways: 
    - `adduser <u> <g>`
    - `(sudo) usermod -aG <g> <u>` - append group
  - `sudo groupadd <g>`
  - `getent <g>`
  - Check all local users - `cut -d':' -f1 /etc/passwd` - view field 1 cut out by `:`
  - Check what _ belongs to - `$ groups`
  - List users of a group - `getent group _ ` - get entries
  - Show user and group names - `id -ng <u>` - show name not number, show group thereof
- Let user have sudo previlege
  - Edit the *sudoers* file - `sudo visudo`
    - `test ALL=(ALL) ALL` - Hosts=(Users:Groups) Commands 
  - Edit *rules* to same effect - `vi /etc/sudoers.d/rules`
    - `test ALL=(ALL) ALL`
    - include path - `@includedir /etc/sudoers.d/rules`
- Hostname
  - Check host(name) - `$ hostnamectl`
  - Change hostname - 3 steps:
    - `sudo hostnamectl set-hostname nuoxoxo` - set new name
    - `127.0.0.1       localhost` <--- (no change)
    - `127.0.1.1       nuoxoxo` < ---- modify this line
    - reboot and check - `hostnamectl`
- Install all u need 
  - `apt install \`
    - sudo vim
    - curl wget
    - ufw tree git man-db
    - openssh-server
    - libpam-pwquality
    - sysvbanner
    - banner
- Up everything 
  - `apt-get update -y` - y means assume yes
  - `apt-get upgrade -y`
- Verify a certain app: 
  - use *grep* - `dpkg -l | grep <app>`
  - or *apt list* - `apt list --installed | grep <app>`
- **Sudoers** configurations
```sh
Defaults	passwd_tries=3
Defaults	badpass_message="Invalid credentials. Please try again."
```
```sh
Defaults	iolog_dir="/var/log/sudo"
Defaults	logfile="/var/log/sudo/"
Defaults	log_input,log_output

# set up logfiles to detect break-in attempts
```
```sh
Defaults	requiretty

# requiretty prevents password leaking
# in cleartext, when sudo requires password via ssh.

# once set, sudo must be run from a logged-in 
# terminal session (a tty), which prevents use of sudo from daemons 
# or processes like cronjobs or web plugins. 
```
```sh
Defaults	secure_path=\
"/usr/local/sbin:\
/usr/local/bin:\
/usr/sbin:\
/usr/bin:\
/sbin:\
/bin:\
/snap/bin"

# secure path replaces the PATH environment 
# variable with a value specified in the sudoers file
```
- **APPARMOR**
  - Apparmor status - `sudo aa-status`
  - Check if enabled - `cat /sys/module/apparmor/parameters/enabled` - will get a Y
- **SSH - Server setup**
  - means *Secure shell protocol*
  - SSH status - `sudo systemctl status ssh`
  - change port - `sudo vi /etc/ssh/sshd_config`
    - `Port 4242`
    - reboot - `sudo service ssh restart`
    - check - `grep Port /ect/ssh/sshd_config`
- **UFW**
  - mean *Uncomplicated firewall*
  - UFW status - `sudo ufw status numbered`
  - if disabled - `sudo ufw enable`
  - **Useful for defence**
    - `sudo ufw status numbered`
    - `sudo ufw delete 2`
    - `sudo ufw delete 4`
    - `sudo ufw status numbered` - two rules (4242) deleted
    - `sudo ufw allow 4242` - re-added
    - `sudo ufw status numbered` - check again they are there
- **SSH - Connect**
  - Navigate:
    - VirtualBox . Setting . Network . Adapter 1 . Advanced . Port Forwarding
  - Setup up port: 
    - Name: Rule 1 
    - Protocol: TCP 
    - Host port: 2121
    - Guest port: 2121
  - Connect
    - Restart - `sudo systemctl restart ssh`
    - Status - `sudo service sshd status` - see "Server listening on \_.\_.\_.\_ port __"
    - On hostside - `ssh <u>@<ip> -p 2121`
    - `exit`
- **Pwquality**
  - libpam means *Pluggable Authentication Module library*
  - edit age of password - two ways:
    - edit *login.defs* in /etc/
      - `vi /etc/login.defs`
      - `PASS_MAX_DAYS    30`  # expires every 30 days 
      - `PASS_MIN_DAYS   2`   # 2 days to wait before re-mod
      - `PASS_WARN_AGE   7`   # warning appears 7 days before expiry date
    - use *chage*
      - `chage -M 30 <u>`
      - `chage -m 2 <u>`
      - `chage -W 7 <u>`
  - edit password strength:
    - edit *common-password* in etc/pam.d 
      - `vi /etc/pam.d/common-password` and reboot
```erlang
password  [success=2 default=ignore] \
pam_unix.so obscure sha512 minlen=10
```
```erlang
password  requisite \
pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1 \
maxrepeat=3 usercheck=0 difok=7 enforce_for_root
```



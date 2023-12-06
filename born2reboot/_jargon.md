
- AppArmor
  - is a linux kernal security module
  - to enhance usr/grp permission
  - confine programs to a limited set of resources
- "du -sh"
  - `du` - disk usage
  - `-s` - summary
  - `-h` - human-readable format
  - also `-a` - all (files & dirs)
- apt-get / aptitude don't work outside linux
  - mac os is built on BSD (Berkeley Software Distribution)
- aptitude 
  - introduced 2014
  - gained pop over apt-get in 2016 (ubuntu 16.04)
  - cleaner commands
  - `$ aptitude` into interface whereas no interface on apt-get 
- apt-get is verbose
```j
$ apt-cache search _app_
$ apt-cache show _app_
$ apt-get install _app_
-
$ aptitude search _app_
$ aptitude show _app_
$ aptitude install _app_
```
- `getent`
  - get entries
- SELinux
  - security-enhanced linux
  - devd by NSA
  - to have more power over who can access the syst
- SSH
  - secure shell protocol
- TTY
  - teletypewriter
  - is a Unix command to print the filename of the terminal connected to standard input
```j
$ tty
/dev/ttys000
```
- UTM
  - universal turing machine

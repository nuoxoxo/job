# "You can't trust code that you did not totally create yourself." - Ken Thompson

Setup

```sh
curl -fL https://github.com/coursier/launchers/raw/master/cs-x86_64-apple-darwin.gz | gzip -d > cs && chmod +x cs && (xattr -d com.apple.quarantine cs || true) && ./cs setup
```

```j
$ scalac helloworld.scala
...
$ $ scala helloworld
```

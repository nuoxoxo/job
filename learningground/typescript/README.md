# "I report to God. You report to me." - Terry Davis




Setup

```j
$ npm install typescript --save-dev
$ npm install tsc
$ npm i -D @types/node
$ vi tsconfig.json
```

```j
$ vi ~/.vimrc

+.  set regexpengine=0
```

Basic json

```j


{
	"compilerOptions":
	{
		"types": [
			"node"
		],
		"target": "es5",
		"module": "commonjs",
		"noImplicitAny": true,
		"removeComments": true,
		"preserveConstEnums": true,
		"sourceMap": true
	},

	"files": 
	[
		"core.ts",
		"sys.ts",
		"types.ts",
		"scanner.ts",
		"parser.ts",
		"utilities.ts",
		"binder.ts",
		"checker.ts",
		"emitter.ts",
		"program.ts",
		"commandLineParser.ts",
		"tsc.ts",
		"diagnosticInformationMap.generated.ts"
	]
}
```

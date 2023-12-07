
#src	:=	helloworld.ts
src	:=	adding.ts

name	:=	$(src:.ts=)
js	:=	$(src:.ts=.js)

all	:	$(name)

$(name)	:
	tsc $(src) && node ./$(js) 21 21
	@#tsc $(src) && node ./$(js)

f	:	fclean

fclean	:
	rm -rf *.js

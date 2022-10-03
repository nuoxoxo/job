#cc	:=	clang++ -std=c++11		#osx
#cc	:=	c++ -std=c++11 -lpthread -lm	#ubu
cc	:=	c++ -std=c++11

exe	:=	atomic

all	:	$(exe)

%.o	:	%.cpp
		$(cc) -c $< -o $@

$(exe)	:	atomic.o
		$(cc) atomic.o -o atomic
		@printf " \n\t run: \n\t for i in {1..10}; do ./atomic; done \n"
		@printf " \n\t to fix it, replace long long with atomic<long, long> \n\n"

f	:	fclean
re	:	fclean all

clean	:
		rm -f *.o

fclean	:	clean
		rm -f atomic a.out

.PHONY	:	fclean clean all re f

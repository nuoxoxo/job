comp		:=	c++ -std=c++11 -Wall -Werror -Wextra
name		:=	out
rmv		:=	rm -f
src		:=	aoc1501.cc
src		:=	aoc1601.cc
src		:=	aoc1701.cc
src		:=	aoc1801.cc
src		:=	aoc1901.cc
src		:=	aoc2001.cc
src		:=	aoc2101.cc
src		:=	aoc1502.cc
src		:=	aoc1602.cc
src		:=	aoc1702.cc
src		:=	aoc1802.cc
src		:=	aoc2002.cc
src		:=	aoc2102.cc

all		:	$(name)

$(name)		:	$(src)
			@ $(comp) $^ -o $@ 

			@ echo "data " && ./$(name) < 2102.0
			@ echo ""
			@ echo "test " && ./$(name) < test		

			@#@ echo "data " && ./$(name) < 2002.0
			@#@ echo ""
			@#@ echo "test " && ./$(name) < test

			@#@ echo "data " && ./$(name) < 1802.0
			@#@ echo ""
			@#@ echo "test " && ./$(name) < test

			@#@ echo "data " && ./$(name) < 1702.0
			@#@ echo ""
			@#@ echo "test " && ./$(name) < test

			@#@ echo "test " && ./$(name) < test
			@#@ ./$(name) < 1602.0
			@#@ echo "test " && ./$(name) < test
			@#@ ./$(name) < 1502.0

			@#@ ./$(name) < 2101.0
			@#@ ./$(name) < 2001.0
			@#@ time ./$(name) < 1801.0
			@#@ ./$(name) < 1701.0
			@#@ ./$(name) < 1601.1
			@#@ ./$(name) < 1601.0
			@#@ ./$(name) < 1501.0
			@ make f

clean		:
			@ $(rmv) $(name)

fclean		:	clean
			@ $(rmv) out *.out

f		:	fclean
re		:	f all
.PHONY		:	fclean clean all re f

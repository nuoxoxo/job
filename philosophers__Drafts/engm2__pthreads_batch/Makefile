exe	:= main main2 demo test pthread *.out
all
clean	:
	/bin/rm -rf *.o __sandbox_*/*.o

fclean	:
	/bin/rm -rf *.o __sandbox_*/*.o $(exe) $(addprefix __sandbox_*/, $(exe))

f	:	fclean

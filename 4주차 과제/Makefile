cc = g++
target = 4weekHW
objects = main.o

$(target): $(objects)
	$(cc) -o $(target) $(objects)

$(objects): GrowableArray.h Array.h

.PHONY : clean
clean :
	rm $(target) $(objects)

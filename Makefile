#
# Makefile for OSX
#

program_name=fire
sources= \
	main.cpp
objects=$(sources:.cpp=.o)

link_flags=-stdlib=libc++
compile_flags=-std=c++11 -stdlib=libc++

all: $(program_name)

$(program_name): $(objects)
	clang++ -o $@ $(objects) $(link_flags)

%.o: %.cpp
	clang++ -o $@ -c $< $(compile_flags)

clean:
	rm -f $(objects) $(program_name)


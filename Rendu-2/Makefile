TARGET = main rigth_triangle square parallelogram shape menu board interface 

##########################################################"

CFLAGS = -g -O2 -Wall -Weffc++ -Werror
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`
TARGET_OBJECT = $(addprefix bin/, $(addsuffix .o, $(TARGET)))

vpath %.cpp src/
vpath %.hpp include/

Tangram: $(TARGET_OBJECT)
	g++ $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@ 

bin/shape.o: shape.cpp shape.hpp 
	g++ $(CFLAGS) -c $< -o $@

bin/rigth_triangle.o: rigth_triangle.cpp rigth_triangle.hpp shape.hpp
	g++ $(CFLAGS) -c $< -o $@

bin/square.o: square.cpp square.hpp shape.hpp
	g++ $(CFLAGS) -c $< -o $@

bin/parallelogram.o: parallelogram.cpp parallelogram.hpp shape.hpp 
	g++ $(CFLAGS) -c $< -o $@

bin/board.o: board.cpp board.hpp
	g++ $(CFLAGS) -c $< -o $@

bin/menu.o: menu.cpp menu.hpp
	g++ $(CFLAGS) -c $< -o $@

bin/interface.o: interface.cpp interface.hpp menu.hpp board.hpp shape.hpp rigth_triangle.hpp parallelogram.hpp square.hpp button.hpp
	g++ $(CFLAGS) -c $< -o $@

bin/main.o: main.cpp interface.hpp menu.hpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	-rm bin/*.o
	-rm Tangram

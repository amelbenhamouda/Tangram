TARGET = test rigth_triangle square parallelogram shape

##########################################################"

CFLAGS = -g -O2 -Wall -Weffc++ -Werror
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`
TARGET_OBJECT = $(addprefix bin/, $(addsuffix .o, $(TARGET)))


vpath %.cpp src/
vpath %.hpp include/

#CFLAGS = -g -O2 -Wall `pkg-config --cflags MLV`
#DFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
#LDLIBS = `pkg-config --libs-only-l MLV`
all: test

test: $(TARGET_OBJECT)
	g++ $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@ 

bin/shape.o: shape.cpp shape.hpp 
	g++ $(CFLAGS) -c $< -o $@
bin/rigth_triangle.o: rigth_triangle.cpp rigth_triangle.hpp shape.hpp
	g++ $(CFLAGS) -c $< -o $@
bin/square.o: square.cpp square.hpp shape.hpp
	g++ $(CFLAGS) -c $< -o $@
bin/parallelogram.o: parallelogram.cpp parallelogram.hpp shape.hpp 
	g++ $(CFLAGS) -c $< -o $@
bin/test.o: test.cpp rigth_triangle.hpp parallelogram.hpp square.hpp shape.hpp
	g++ $(CFLAGS) -c $< -o $@


clean:
	-rm -rf $(TARGET_OBJECT) test

#   This file is part of the MLV Library.
#
#   Copyright (C) 2010,2011,2012,2013 Adrien Boussicault, Marc Zipstein
#
#
#    This Library is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This Library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this Library.  If not, see <http://www.gnu.org/licenses/>.

LIB= Drawer.o TopoParser.o  GraphPrinter.o Peer.o PeerList.o  Printer.o GroupList.o Group.o Grouper.o GroupPrinter.o

CPPFLAGS += -g

all: topo

topo: ${LIB} main.cpp
	g++ -o  $@ $^ ${CPPFLAGS} 

clean:
	rm -f *.o topo core *.jpeg

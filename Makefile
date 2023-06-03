SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -g -std=c++17 $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

all: main00 main01 main02 main03 main04 main05 main06 main07 main08 main09 main10

main00:	widget.o main00.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main01:	widget.o main01.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main02:	widget.o main02.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main03:	widget.o main03.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main04:	widget.o main04.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main05:	widget.o main05.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main06:	widget.o main06.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main07:	widget.o main07.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main08:	widget.o main08.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main09:	widget.o main09.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main10:	widget.o main10.o
	$(CXX) -o $@ $^ $(LDFLAGS)

.phony:	clean
clean:
	$(RM) all *.o main00 main01 main02 main03 main04 main05 main06 main07 main08 main09 main10
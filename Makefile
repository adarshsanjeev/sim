TARGET=sim
OBJECT=main.o class.o alu.o

$(TARGET): $(OBJECT)
	clang++ -o $(TARGET) $(OBJECT)
$(OBJECT): %.o: %.cpp
	clang++ -c $<

class.o: class.h
main.o: class.h
alu.o: class.h

.PHONY: clean

clean:
	rm -rf *.o sim a.out

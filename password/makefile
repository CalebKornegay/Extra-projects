.PHONY: clean test all
all: clean
	@javac -d class src/*.java

clean:	
	@rm -rf class/	
	@mkdir class
	@touch class/.keep

test: clean all
	@cd class && java main && cd ..
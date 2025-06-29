CC= g++
PROGNAME= tobase
PROD_FLAGS= -O2 -DNDEBUG
DEBUG_FLAGS= -ggdb
COMPILER_FLAGS= -std=c++17
CLASSNAMES= main
run_args= 1200

# directories and co
BIN= bin
BASH_FILE= ~/.bash_config
EXPORT_DIR= ~/data/etc/binaries

.PHONY: dev prod run make_bin clean run to_prod to_dev deb_flgs export export_bash

#-----------------------------MAIN---------------------------->

dev: to_dev $(CLASSNAMES)
	$(CC) $(BUILD_FLAGS) -o bin/$(PROGNAME) bin/*.o

export: prod
	cp ./$(BIN)/$(PROGNAME) $(EXPORT_DIR)
	echo "alias $(PROGNAME)=\"$(EXPORT_DIR)/$(PROGNAME)\" " >> $(BASH_FILE)

prod: to_prod $(CLASSNAMES)
	$(CC) $(PROD_FLAGS) -o bin/$(PROGNAME) bin/*.o

run: dev
	./$(BIN)/$(PROGNAME) $(run_args)

run_prod: prod
	./$(BIN)/$(PROGNAME)

#-----------------------------CLASSES---------------------------->

main : make_bin src/main.cpp
	$(CC) $(COMPILER_FLAGS) $(BUILD_FLAGS) -c src/main.cpp -o bin/main.o

#-----------------------------ARBITRARY---------------------------->

make_bin:
	mkdir -p bin

to_prod:
	$(eval BUILD_FLAGS= $(PROD_FLAGS))

to_dev:
	$(eval BUILD_FLAGS= $(DEBUG_FLAGS))

clean:
	rm -rf bin/
	echo 'cleaned'


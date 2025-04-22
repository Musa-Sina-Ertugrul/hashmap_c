CFLAGS := -g -Wall -Wextra -fPIC
CC := gcc
SRC_DIR := src
OBJ_DIR := build/lib
H_DIR := include
SRCS := $(wildcard $(SRC_DIR)/*.c)
TEST_DIR := tests
files := hashmap
test_files := test_hash test_init_node test_init_map test_put test_get \
			test_destroy test_del


all: build_dirs $(files)

build_dirs:
	mkdir -p $(OBJ_DIR)

$(files):
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$@.c -I$(H_DIR) -o $(OBJ_DIR)/$@.o
	$(CC) $(CFLAGS) -shared -o $(OBJ_DIR)/lib$@.so $(OBJ_DIR)/$@.o


test: $(test_files) run_test

$(test_files): 
	$(CC) $(CFLAGS) $(TEST_DIR)/$@.c -o build/$@ -I$(H_DIR) -L$(OBJ_DIR) $(foreach word ,$(files),-l$(word)) -Wl,-rpath,'$(OBJ_DIR)'
	chmod +x build/$@

run_test: $(foreach word ,$(wildcard build/test_*), $(word)_run)
	@echo "------ Finished Tests ------"

$(foreach word ,$(wildcard build/test_*), $(word)_run):
	@echo "------ Running $(patsubst %_run,%,$@) test ------"
	@./$(patsubst %_run,%,$@)
	@echo "------ Test $(patsubst %_run,%,$@) passed ------"

clean:
	rm -rf build

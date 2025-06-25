build_directory_name:=build
build_directory:=./$(build_directory_name)
Cache_txt:=$(build_directory)/CMakeCache.txt
Final:=$(build_directory)/app/main
Final_copy:=main.exe
PREDEFINED_GENERATOR:=-G "Unix Makefiles" 
image_out:=$(wildcard *.ppm)

ifeq ($(OS),Windows_NT)
	Final_file=$(Final).exe
else
	Final_file=$(Final)
endif




$(Cache_txt):$(build_directory)
	cmake -B build $(PREDEFINED_GENERATOR)

$(Final_file):$(Cache_txt)
	cmake --build build

target:$(Final_file)

copy:$(Final_file)
	cp $(Final_file) ./

$(Final_copy):$(Final)
	make copy

run:$(Final_file)
	@echo "Your OS is $(OS)"
	$(Final)

run_copy:$(Final_copy)
	./main

clean:$(build_directory) 
	rm -rf $(build_directory)

build:$(build_directory)		

$(build_directory):
	@echo "Folder $(build_directory) does not exist"
	mkdir -p $(build_directory)
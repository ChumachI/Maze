## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
##                   COLOR THEME                   ##
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
DEFAULT=\033[0m 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
WHITE_FG=\033[37m 
RED_FG=\033[31m 
GREEN_FG=\033[32m 
YELLOW_FG=\033[33m 
BLUE_FG=\033[34m 
PURPLE_FG=\033[35m 
CYAN_FG=\033[36m 
BLACK_FG=\033[30m 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
WHITE_BG=\033[47m 
RED_BG=\033[41m 
GREEN_BG=\033[42m
YELLOW_BG=\033[43m  
BLUE_BG=\033[44m 
PURPLE_BG=\033[45m
CYAN_BG=\033[46m 
BLACK_BG=\033[40m 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 
##                   VARIABLES                     ## 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 

PACKAGE = Maze
CC=g++
OS=$(shell uname)
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
LGTEST_FLAGS = -lgtest -lgtest_main -pthread
GCOV_FLAGS=-coverage
ifeq ($(OS), Linux)
  OPEN=xdg-open
  START = ./build/View
else
  OPEN=open
  START = $(OPEN) build/View.app/
endif

all: install

install: uninstall clean
	@mkdir build
	@cd build/ && qmake ../view/View/View.pro && make
	$(START)

uninstall:
	rm -rf build

clean:
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                   CLEANING                     $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 
	@rm -f test
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f *info
	@rm -rf report
	@rm -f *.o
	@rm -rf build
	@rm -rf docs
	@rm -rf *.gz
	@rm -rf build
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                 CLEANING DONE                  $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

.PHONY: dvi
dvi: clean
	@mkdir -p docs
	@doxygen Doxyfile
	@mv html latex docs
	@open docs/html/index.html
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)               DOCUMENTATION READY              $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

.PHONY: dist
dist:
	@mkdir $(PACKAGE)
	@cp -r ./model $(PACKAGE)
	@cp -r ./controller $(PACKAGE)
	@cp -r ./view $(PACKAGE)
	@cp -r ./files $(PACKAGE)
	@cp Makefile $(PACKAGE)
	@tar -czf $(PACKAGE).tar.gz $(PACKAGE)
	@rm -rf $(PACKAGE)
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                ARCHIVE IS READY                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

.PHONY: tests
tests: clean
	@echo "$(BLACK_FG)$(GREEN_BG)                                                 $(DEFAULT)"
	@echo "$(BLACK_FG)$(GREEN_BG)                  CREATING TEST                  $(DEFAULT)"
	@echo "$(BLACK_FG)$(GREEN_BG)                                                 $(DEFAULT)\n"
	@$(CC) ./model/*/*.cc -o test $(WILD) $(CC_FLAGS) $(LGTEST_FLAGS) -g
	@./test

.PHONY: gcov_report
gcov_report:
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                CREATE REPORT                   $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 
	@$(CC) $(CC_FLAGS) model/*/*.cc $(LGTEST_FLAGS) $(GCOV_FLAGS) -o info
	@./info
	@lcov -t "info" -o gcovreport.info -c -d .
	@lcov --remove gcovreport.info '/usr/*' '*test*' --output-file gcovreport.info
	@genhtml -o report gcovreport.info
	@$(OPEN) report/index.html
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                   COMPLETE                     $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n"

style_fix:
	@cp ../materials/linters/.clang-format .
	@clang-format -i */*.cc
	@clang-format -i */*.h
	@clang-format -i */*/*.cc
	@clang-format -i */*/*.h
	@rm -f .clang-format
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                  STYLE FIXED                   $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

check_style:
	@cp ../materials/linters/.clang-format .
	@clang-format -n */*.cc
	@clang-format -n */*.h
	@clang-format -n */*/*.cc
	@clang-format -n */*/*.h
	@rm -f .clang-format
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)             STYLE CHECK FINISHED               $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 
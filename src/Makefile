# Определение операционной системы, имена программ и параметров
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11 #-pedantic

# SANITIZE = -fsanitize=undefined -fsanitize=address
GCOVFLAGS = -ftest-coverage

# MacOS
ifeq ($(shell uname -s),Darwin) 
OPEN_CMD = open
OFLAGS = -lcheck -lm -lpthread -fprofile-arcs
MEMORY_TEST = leaks
# Ubuntu
else ifneq (,$(wildcard /etc/lsb-release))
OPEN_CMD = xdg-open
OFLAGS = -lcheck -lm -lpthread -fprofile-arcs -lgcov -lrt -lsubunit
CFLAGS = -Wall -Wextra -Werror -g -std=c11 -DUBUNTU
MEMORY_TEST = valgrind
# Other Linux
else ifeq ($(shell uname -s),Linux)
OPEN_CMD = xdg-open
OFLAGS =  -lcheck -lm -lpthread -fprofile-arcs -lgcov -lrt
MEMORY_TEST = valgrind
endif

# Пути до используемых папок
OBJ_DIR = obj
TEST_DIR = tests
REPORT_DIR = report
# Списки различных файлов
SOURCES:= s21_*.c
TESTS:= $(TEST_DIR)/*.c
LIB = s21_string.a
# Указываем список каталогов, в которых make выполняет поиск
vpath %.c $(SOURCES) : $(TESTS)
vpath %.o $(OBJ_DIR)

# ЦЕЛИ СБОРКИ
# Цель по-умолчанию: проверка стилей, запуск тестов, отчет и библиотека
all: style gcov_report $(LIB)

# Создание временной папки для .o-файлов
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(TEST_DIR)

# Создание временной папки для отчетов
$(REPORT_DIR):
	@mkdir -p $(REPORT_DIR)

# Запуск всех проверок
check: style cppcheck $(MEMORY_TEST)

# Сборка приложения для запуска тестов
test: clean $(OBJ_DIR)
	@for f in $(SOURCES); do $(CC) $(CFLAGS) -c --coverage $$f -o $(OBJ_DIR)/$$f.o; done;
	@for f in $(TESTS); do $(CC) $(CFLAGS) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/s21_*.o $(OBJ_DIR)/$(TEST_DIR)/*.o $(OFLAGS)
	./$@

# Сборка библиотеки для вертера без тестов и покрытия кода
s21_string.a: $(OBJ_DIR)
	@for f in $(SOURCES); do $(CC) $(CFLAGS) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	ar rcs $(LIB) $(addprefix $(OBJ_DIR)/, s21_*.o)

# Создание отчета по покрытию тестами
gcov_report: test $(REPORT_DIR)
	./test
	lcov -c -d . -o $(REPORT_DIR)/report.info --no-external
	genhtml $(REPORT_DIR)/report.info --output-directory=$(REPORT_DIR)
	$(OPEN_CMD) $(REPORT_DIR)/src/index.html

# Проверка и автоматическое форматирование по Google-style
style:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h tests/*.c
	clang-format -i *.c *.h tests/*.c
	rm .clang-format

# Подготовка докера для его работы на goinfre
init_docker:
	rm -rf ~/Library/Containers/com.docker.docker
	mkdir -p ~/goinfre/Docker/Data
	ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker

# Запуск мини-вертера (проверка на стили и корректность сборки Makefile)
docker: $(LIB)
	cd ../materials/build && sh run.sh

# Запуск докера с тестами
docker_test: clean
	cd docker && sh run_tests.sh

# Запуск докера с valgrind
docker_leak: clean
	cd docker && sh run_leaks.sh

# Запуск докера с тестами и valgrind
docker_all: clean
	cd docker && sh run_all.sh

# Проверка статическим анализатором кода
cppcheck: 
	cppcheck *.c *.h

# Проверка на утечки памяти для macOS
leaks: clean test
	CK_FORK=no leaks --atExit -- ./test 
	make clean

# Проверка памяти для Linux
valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

# Очистка от временных файлов
clean:
	rm -rf src *.o  *.png 
	rm -rf *.gcno *.gcda *.gch *.info *.html *.a *.css *.o *.dSYM *.log
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -f $(TEST_DIR)/*.o
	rm -f test
	rm -rf usr

# Пересборка проекта (при этом не изменившиеся модули не пересобираются)
rebuild:
	make -B

 # Перечисление целей, которые не являются названиями файлов
.PHONY: all	check test s21_string.a gcov_report style init_docker docker docker_test docker_leak docker_all cppcheck leaks valgrind clean rebuild

CXX_9=g++9.1
CXX=g++
CXXFLAGS= -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS = -lrestbed -lpthread
LINKFLAGS_TEST= -lgtest

SRC_DIR_SERVER = src/server
SRC_DIR= src

TEST_DIR = test

#GMOCK = /usr/src/gmock/gmock-all.cc -lpthread

SRC_INCLUDE = include
TEST_INCLUDE = test
SERVER_INCLUDE = -I include/server
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM_SERVER = trackEx
PROGRAM_TEST = testTrackEx

.PHONY: all
all: $(PROGRAM_SERVER) $(PROGRAM_TEST) memcheck-test coverage docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX_9) $(CXXFLAGS) $(LINKFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) $(PROGRAM_SERVER) $(PROGRAM_TEST) $(COVERAGE_DIR)


$(PROGRAM_SERVER):
	$(CXX_9) $(CXXFLAGS) -o $(PROGRAM_SERVER) -I $(SRC_INCLUDE) $(SERVER_INCLUDE) $(SRC_DIR_SERVER)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)


$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS_TEST)
	$(PROGRAM_TEST)

memcheck-game: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM)


memcheck-test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

.PHONY: coverage
coverage: $(PROGRAM_TEST)
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/Aegir/src/*" -o $(COVERAGE_RESULTS)
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	rm -f *.gc*

.PHONY: static
static: ${SRC_DIR}
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${TEST_DIR} ${INCLUDE} --suppress=missingInclude

.PHONY: style
style: ${TEST_DIR} ${SRC_INCLUDE} ${SRC_DIR_SERVICE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/* ${SRC_DIR_SERVER}/* $(SERVER_INCLUDE)/*


.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen docs/source/doxyfile

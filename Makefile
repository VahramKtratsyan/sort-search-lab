BUILD_DIR := build
INCLUDE_DIR := include
TEST_DIR := test
BENCHMARK_DIR = benchmark
CXX := clang++
CXXFLAGS := -std=c++20 -g -Wunreachable-code -Wunreachable-code-loop-increment \
-Wunreachable-code-return -Wall -Wpedantic -Wextra -Werror
TEST_LIBS := -lgtest -lgtest_main -lpthread
INCLUDES := -I include
INCLUDE_DEPS_COMP_SORT = $(INCLUDE_DIR)/sorting_lib/sorting_algorithms/with_comparison/*.tpp
INCLUDE_DEPS_NON_COMP_SORT = $(INCLUDE_DIR)/sorting_lib/sorting_algorithms/without_comparison/*.tpp
INCLUDE_DEPS_SEARCH = $(INCLUDE_DIR)/searching_lib/searching_algorithms/*.tpp
INCLUDE_DEPS_BENCHMARK = $(INCLUDE_DIR)/benchmark_lib/sorting_benchmark/*.tpp \
$(INCLUDE_DIR)/benchmark_lib/searching_benchmark/*.tpp \
$(INCLUDE_DIR)/benchmark_lib/utilities/*.tpp \
$(INCLUDE_DIR)/sorting_lib/utilities/wrapper/*.hpp $(INCLUDE_DIR)/searching_lib/utilities/wrapper/*.hpp \
$(INCLUDE_DIR)/benchmark_lib/utilities/benchmark_entry/*.tpp


all: $(BUILD_DIR)/exe/test/comp_sort_test $(BUILD_DIR)/exe/test/non_comp_sort_test \
$(BUILD_DIR)/exe/test/search_test $(BUILD_DIR)/exe/benchmark_main

$(BUILD_DIR)/exe/test/comp_sort_test: $(BUILD_DIR)/object/comp_sort_test.o | $(BUILD_DIR)/exe/test
	$(CXX) $< -o $@ $(TEST_LIBS)

$(BUILD_DIR)/object/comp_sort_test.o: $(TEST_DIR)/comp_sort_test.cpp $(INCLUDE_DEPS_COMP_SORT) | $(BUILD_DIR)/object
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


$(BUILD_DIR)/exe/test/non_comp_sort_test: $(BUILD_DIR)/object/non_comp_sort_test.o | $(BUILD_DIR)/exe/test
	$(CXX) $< -o $@ $(TEST_LIBS)
	
$(BUILD_DIR)/object/non_comp_sort_test.o: $(TEST_DIR)/non_comp_sort_test.cpp $(INCLUDE_DEPS_NON_COMP_SORT) | $(BUILD_DIR)/object
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


$(BUILD_DIR)/exe/test/search_test: $(BUILD_DIR)/object/search_test.o | $(BUILD_DIR)/exe/test
	$(CXX) $< -o $@ $(TEST_LIBS)

$(BUILD_DIR)/object/search_test.o: $(TEST_DIR)/search_test.cpp $(INCLUDE_DEPS_SEARCH) | $(BUILD_DIR)/object
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


$(BUILD_DIR)/exe/benchmark_main: $(BUILD_DIR)/object/benchmark_main.o | $(BUILD_DIR)/exe
	$(CXX) $< -o $@

$(BUILD_DIR)/object/benchmark_main.o: $(BENCHMARK_DIR)/benchmark_main.cpp $(INCLUDE_DEPS_BENCHMARK) | $(BUILD_DIR)/object
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/object: | $(BUILD_DIR)
	mkdir -p $@

$(BUILD_DIR)/exe: | $(BUILD_DIR)
	mkdir -p $@

$(BUILD_DIR)/exe/test: | $(BUILD_DIR)/exe
	mkdir -p $@

comp_sort_test:
	./$(BUILD_DIR)/exe/test/comp_sort_test

non_comp_sort_test:
	./$(BUILD_DIR)/exe/test/non_comp_sort_test

search_test:
	./$(BUILD_DIR)/exe/test/search_test

benchmark_main:
	./$(BUILD_DIR)/exe/benchmark_main

clean:
	rm -rf $(BUILD_DIR)

help:
	@echo "Available targets:"
	@echo "  all     - Build and link the test executable (default)"
	@echo "  comp_sort_test    - Run the built comp_sort_test executable"
	@echo "  non_comp_sort_test    - Run the built non_comp_sort_test executable"
	@echo "  search_test    - Run the built search_test executable"
	@echo "  benchmark_main    - Run the built benchmark_main executable"
	@echo "  clean   - Remove build directory"
	@echo  "  help    - Show this help list"

.PHONY: all test clean help
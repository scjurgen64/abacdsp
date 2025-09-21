#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}     Unit Test Coverage Checker${NC}"
echo -e "${BLUE}     (Unified *_test.cpp pattern)${NC}"
echo -e "${BLUE}========================================${NC}"

# Check if src and test directories exist
if [ ! -d "./src" ]; then
    echo -e "${RED}Error: ./src directory not found${NC}"
    exit 1
fi

if [ ! -d "./test" ]; then
    echo -e "${RED}Error: ./test directory not found${NC}"
    exit 1
fi

# Enable debug mode with -d flag
DEBUG=false
if [[ "$1" == "-d" || "$1" == "--debug" ]]; then
    DEBUG=true
    echo -e "${CYAN}DEBUG MODE ENABLED${NC}"
fi

echo -e "${BLUE}Scanning files...${NC}"

missing_count=0
total_count=0
missing_tests=()

# Get all header files
for header in $(find ./src -name "*.h" | sort); do
    class_name=$(basename "$header" .h)
    total_count=$((total_count + 1))

    if [ "$DEBUG" = true ]; then
        echo -e "${CYAN}DEBUG: Processing header '$header' -> class '$class_name'${NC}"
    fi

    # Look for corresponding *_test.cpp file
    test_file_pattern="${class_name}_test.cpp"

    if find ./test -name "$test_file_pattern" | grep -q .; then
        if [ "$DEBUG" = true ]; then
            found_test=$(find ./test -name "$test_file_pattern")
            echo -e "${CYAN}DEBUG: Found test file: $found_test${NC}"
        fi
        echo -e "${GREEN}✓ COVERED:${NC} $class_name"
    else
        echo -e "${RED}✗ MISSING TEST:${NC} $class_name"

        # Extract the directory structure for suggestions
        header_dir=$(dirname "$header" | sed 's|\./src/includes/||' | sed 's|\./src/||')
        echo -e "  ${YELLOW}Expected: ./test/$header_dir/${class_name}_test.cpp${NC}"
        echo

        missing_count=$((missing_count + 1))
        missing_tests+=("$header:$class_name:$header_dir")
    fi
done

# Summary
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}             SUMMARY${NC}"
echo -e "${BLUE}========================================${NC}"

if [ $total_count -gt 0 ]; then
    coverage_percent=$(( (total_count - missing_count) * 100 / total_count ))
else
    coverage_percent=0
fi

echo -e "Total header files: ${BLUE}$total_count${NC}"
echo -e "Files with tests:   ${GREEN}$((total_count - missing_count))${NC}"
echo -e "Missing tests:      ${RED}$missing_count${NC}"
echo -e "Coverage:           ${YELLOW}$coverage_percent%${NC}"

if [ $missing_count -eq 0 ]; then
    echo -e "${GREEN}🎉 Perfect! All header files have corresponding tests!${NC}"
else
    echo
    echo -e "${RED}Missing tests for:${NC}"
    for entry in "${missing_tests[@]}"; do
        IFS=':' read -r header_file class_name header_dir <<< "$entry"
        echo -e "${RED}  • $class_name${NC} ($header_file)"
    done

    echo
    echo -e "${YELLOW}💡 Quick commands to create missing test files:${NC}"
    for entry in "${missing_tests[@]}"; do
        IFS=':' read -r header_file class_name header_dir <<< "$entry"
        test_dir="./test/$header_dir"
        test_file="$test_dir/${class_name}_test.cpp"

        echo -e "${BLUE}mkdir -p $test_dir && touch $test_file${NC}"
    done
fi

# Exit with error code if tests are missing (useful for CI/CD)
if [ $missing_count -gt 0 ]; then
    exit 1
else
    exit 0
fi
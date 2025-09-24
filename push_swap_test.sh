#!/bin/bash
set -e  # Exit on first failure

# Colors for logs
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Array of test inputs
inputs=(
  "3 2 1"
  "5 1 4 2 3"
  "2 1 3 6 5 4"
  "10 9 8 7 6 5 4 3 2 1"
  "1 2 3 4 5 6 7 8 9 10"
)

# Track failures
failures=0

echo "Running push_swap tests..."

for input in "${inputs[@]}"; do
    echo -e "\nTesting input: $input"
    
    # Run push_swap through valgrind
    if ! echo $input | valgrind --leak-check=full --error-exitcode=1 ./push_swap &> valgrind.log; then
        echo -e "${RED}Memory leak or crash detected for input: $input${NC}"
        cat valgrind.log
        failures=$((failures + 1))
        continue
    fi

    echo -e "${GREEN}Test passed for input: $input${NC}"
done

if [ $failures -eq 0 ]; then
    echo -e "\n${GREEN}All tests passed!${NC}"
else
    echo -e "\n${RED}$failures test(s) failed.${NC}"
    exit 1
fi

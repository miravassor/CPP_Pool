#!/bin/bash

# ANSI color codes
GREEN_BOLD="\e[1;32m"
RESET="\e[0m"

# Timeout duration in seconds
TIMEOUT_DURATION=1

for i in {2..1000}; do
    # Generate a shuffled list of numbers from 1 to 100
    numbers=$(shuf -i 1-3000 -n $i)

    # Run the PmergeMe command with a timeout
    if output=$(timeout $TIMEOUT_DURATION ./PmergeMe $numbers); then
        # If the command is successful, print "success" in green and bold
        echo -e "${GREEN_BOLD}success${RESET}"
    else
        # Determine if the command failed due to timeout or another error
        if [ $? -eq 124 ]; then
            echo "ERROR: Command timed out at i=$i"
        else
            echo "ERROR detected at i=$i"
        fi
        echo "Shuffled List: $numbers"
        exit 1
    fi
done




# for i in {2..10000}; do
#     # Generate a shuffled list of numbers from 1 to 100 and store it in a variable
#     numbers=$(shuf -i 1-100 -n $i | tr "\n" " ")

#     # Run the PmergeMe command with the shuffled numbers
#     output=$(./PmergeMe $numbers)

#     # Check if "ERROR" is in the output
#     if echo "$output" | grep -q "ERROR"; then
#         echo "ERROR detected at i=$i"
#         echo "Shuffled List: $numbers"
#         exit 1
#     fi
# done

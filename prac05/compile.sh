# Bash Script

# gcc -o program "$1" -pthread -Wall
gcc -o program "$1" -fopenmp -Wall
# gcc -o program program.c -Wall # -Werror # Show all warnings and treat warnings as errors
# gcc -o program sandbox.c -Wall # -Werror
./program
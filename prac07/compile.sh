# Bash Script

# gcc -o program "$1" -pthread -Wall
gcc -o program "$1"  -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings 


# a16
# gcc R_05_01_1.c  R_05_01_2.c -o program  -Wall

./program
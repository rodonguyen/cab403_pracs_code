# Bash Script

# gcc -o program "$1" -pthread -Wall
gcc -o program "$1"  -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings 

./program
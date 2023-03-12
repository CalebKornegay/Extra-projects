if [ "$1" == "" ] || [ "$2" == "" ]; then
    echo "Try -h for help"
    exit
fi

if [ "$1" == "-h" ]; then
    echo "Usage: ./curl.sh or sh curl.sh [source url] [dest file]"
    exit
fi 

echo "Downloading contents of $1 to the file $2"
curl "$1" -o "$2" 
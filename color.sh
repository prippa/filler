gren=$(printf "[1;32mO\033[0m")
yel=$(printf "[1;34mX\033[0m")

sed "s|O|$gren|g" |
sed "s|X|$yel|g" |
sed "s|fin|player|g"

gren=$(printf "[1;32mO\033[0m")
yel=$(printf "[1;34mX\033[0m")
cls=$(printf "\033[1J\033[;H")
sle=$(sleep 1)

sed "s|O|$gren|g" |
sed "s|X|$yel|g" |
sed "s|Plateau|$cls|g" |
sed "g|Piece|$sle|" |
sed "s|fin|player|g"

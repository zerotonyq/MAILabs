echo "Ready(Y/N)?"
read answer
while [[ "$answer" = "Y" ]];
do
echo "choose floor num"
read floor
echo "choose ceiling num"
read ceiling
random=$(($RANDOM % ceiling + floor))
echo "your random number is $random"
echo "are you ready?(Y/N)"
read answer
done



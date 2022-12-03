temp=‘cat $1‘
lines=$2
arr=()
SAVEIFS=$IFS
IFS=";"
n=0
while read val
do
	echo "$val"
	i=1
	while [[ i -le lines ]]
	do
		arr[$n]=‘echo "$val" | cut --delimiter=";" -f$i‘
		((n++))
		((i++))
	done
done < $1
IFS=$SAVEIFS
echo "${arr[*]}" 
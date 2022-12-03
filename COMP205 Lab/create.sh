rm rand_nums

for i in `seq 1"$1"`
	do
		for j in `seq 1"$2"`
		do
			echo -n $RANDOM >>rand_nums
			echo -n ";" >>rand_nums
		done
	echo \n >>rand_nums
done
for threads in {1..100}
do
	echo "running game on big with $threads threads"
	./GameOfLife big.txt 100 $threads Y N
done

cp ./results.csv ./results_big.csv

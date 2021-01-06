for threads in {1..100}
do
    echo "running game on small with $threads threads"
    ./GameOfLife small.txt 100 $threads Y N
done

cp ./results.csv ./results_small.csv
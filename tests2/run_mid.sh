for threads in {1..100}
do
    echo "running game on mid with $threads threads"
    ./GameOfLife mid.txt 100 $threads Y N
done

cp ./results.csv ./results_mid.csv
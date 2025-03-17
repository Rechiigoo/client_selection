echo "Raffle test in batch: Testing randomizer"
make clean
make raffle

rm -f raffle_batch.txt

echo "Doing all raffles, please wait..." 
for i in $(seq 1 10);
do
    echo "Raffle" $i
    ./raffle raffle.txt >> raffle_batch.txt
    sleep 1
done

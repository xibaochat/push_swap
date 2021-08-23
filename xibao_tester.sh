# Create directory to store tested numbers
mkdir -p args_tests

# Set number of numbers in stack to sort
for i in {2..500}
do
	# Generate random list of $i numbers
	ARG=`NB_TO_GENERATE=$i python random_num_generator.py`

	# Store random list in log file
	echo $ARG > args_tests/test_$i.txt

	# Start test with generated random list as argument
	echo -n "[+] Testing for $i numbers:\t"
	NB_INSTRUCTION=`./push_swap $ARG | wc -l`
	echo -n "$NB_INSTRUCTION\t-->\t"
	./push_swap $ARG | ./checker $ARG
done

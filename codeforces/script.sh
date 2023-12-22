########## WITH DIFF ##########

set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer

########## WITH CHECKER ##########

# set -e
# g++ test.cpp -o code
# g++ gen.cpp -o gen
# g++ brute.cpp -o brute
# g++ checker.cpp -o checker
# for((i = 1; ; ++i)); do
#     ./gen $i > input_file
#     ./code < input_file > myAnswer
#     ./brute < input_file > correctAnswer
#     ./checker > checker_log
#     echo "Passed test: "  $i
# done
# echo "WA on the following test:"
# cat input_file
# echo "Your answer is:"
# cat myAnswer

########## PAUSE PROGRAM ##########

sleep 1h
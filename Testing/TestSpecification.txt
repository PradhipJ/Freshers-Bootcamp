int add(string numbers)

GIVEN
WHEN
THEN

1. Given "" ,then 0 is expected
2. Given "0",then 0 is expected
3. Given "1" (a single valid digit),then "1" (same digit) is expected
4. Given "1, 2" (two valid numbers),then 3 (addition of the two numbers) is expected
5. Given unknown amount of numbers,then addition of the numbers is expected
6. Given "1\n2,3" (new line instead of commas),then 6 (addition of given numbers) is expected
7. Given with different delimiter “//;\n1;2”, addition of numbers is expected with default delimiter ";"
8. Given a negative number,then an expection "negatives not allowed" is expected
9. Given a number bigger than 1000, then that number is ignored
10. Given numbers with delimiters of any length, addition of numbers is expected
11. Given numbers with multiple delimeters, addition of numbers is expected

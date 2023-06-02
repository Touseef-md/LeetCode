EDGE Cases for ATOI function:
1) Leading spaces
2) + sign, error was with + sign index was not incremented and it assumed + to be a digit.
3) Have to consider only numbers starting from the left.
4) Consider the decimal numbers. Forming number from right to left, whenever there occur a decimal make the placeValue =1 and num=0.
5) After + ,- sign if there is anyother symbol other than a digit ans =0.
6) Ignore the leading zeros.
7) If the number is very large.
8) If the placeValue becomes large, before the number becomes large.
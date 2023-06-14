Edge case: I forgot that here the leading zeros are useless but the trailing zeros are considered. ex: 1.1 and 1.10.
<br>
My whole logic is wrong I was comparing the first characters i.e. if the first character is greater then it is greater but here we needed to parse the number instead of character. ex: 1.2 and 1.10. Here my answer was 1 because 2>1 but answer should be -1 because 10 >2.
# Minimum-Spaning-Tree
C++
## Objective

![Screenshot from 2021-12-20 11-30-50](https://user-images.githubusercontent.com/66109376/146707864-33f096c9-a6d2-40d9-9f20-eb9fbd17a9a4.png)

## Input

![Screenshot from 2021-12-20 11-34-28](https://user-images.githubusercontent.com/66109376/146708066-e1609310-cfc6-4b1f-8ede-05dbc50bf691.png)

### Explanation of the Input
* First line represents n(the number of the pins).
* Then, it will give n lines representing the coordinate of each pin.
* Last, it will give the existing routing segments.

## Output

![Screenshot from 2021-12-20 11-38-47](https://user-images.githubusercontent.com/66109376/146708350-9bf164bb-21f1-460a-bfe5-240a3139b491.png)

### Explanation of the Output
* You should output minimal cost
* Then, output m lines which represent the added routing segments.
  * (m: number of added routing segments)
* Pin order is not matter each line such as “1 0” in the second line is OK
* Pin order is not matter between lines neither
  * "3 7", "2 6", "0 1" is OK

## Compile format
```
 g++ -std=c++11 0710747.cpp -o Lab2
```
```
./Lab2 [input] [output]
```
## Check your answer
* First type this
```
chmod 755 verify
```
* Then run the verify
```
./verify [input file] [golden output file] [your output file]
```

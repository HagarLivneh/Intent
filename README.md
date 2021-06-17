# Intent recognition

Case Examples:
- What is the weather like today? => Prints (Intent: Get Weather)
- What is the weather like in Paris today? => Prints (Intent: Get Weather City)
- Tell me an interesting fact. => Prints (Intent: Get Fact)

## Build project with Google tests

$`git clone https://github.com/google/googletest.git -b release-1.10.0`

$`cd googletest && mkdir build && cd build && cmake .. && make`

- Run tests
$`./test/IntentTest`      


## Build Project without Google tests

$`mkdir build && cd build && cmake .. && make`      

- Run executable
$`./execut/IntentReco`      


# Welcome to ft_containers 📦 

## Building instructions for tests
```sh
git submodule update --init --recursive
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all
./tests/ft_containers_tst
```
## Lunch only some tests
```sh
./tests/ft_containers_tst --gtest_filter=Vector*
./tests/ft_containers_tst --gtest_filter=Map*
```

## Author

👨 **Thomas WAGNER**

* Github: [@twagger](https://github.com/twagger/)
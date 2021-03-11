# Hash-TCP-server

## Preset
```python
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install libssl-dev
```

## Tutorial

```python
cd simple-hash-server/lib
git clone https://github.com/google/googletest/
cd ..
mkdir build
cd build
cmake ..
make all
```

## Run server:
In build directory:
```python
cd src
./server_run
```

## Run GTests:
In build directory:
```python
cd tst
./server_tst
```

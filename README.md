# Hash-TCP-server

## Description
Simple TCP hash server  
Default properties:  
local ip: "0.0.0.0"  
port: "8080"  
concurrent connections: "20"  
Use this simple hash-client for testing:  https://github.com/sergeya3ro/simple-test-client

## Preset
```python
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install libssl-dev
```

## Tutorial

```python
chmod +x build_server.sh
./build_server.sh
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

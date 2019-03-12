g++ -c api.cpp
ar cr libapi.a api.o 
g++ -o client client.cpp -L . -l api
./client
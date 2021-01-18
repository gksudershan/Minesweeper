default:
	g++ app.c++ main.c++ `wx-config --cxxflags --libs` -o app 
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
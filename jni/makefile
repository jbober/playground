JAVA_HOME=/etc/alternatives/java_sdk_1.8.0/
HelloJNI.o: HelloJNI.c
	g++ -fpic -c -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux  HelloJNI.c 
libHelloJNI.so: HelloJNI.o
	g++ -shared -o libHelloJNI.so HelloJNI.o
	

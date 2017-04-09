JAVA_HOME=/etc/alternatives/java_sdk_1.8.0/
HelloJNI.o: HelloJNI.c
	gcc -fpic -c -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux  HelloJNI.c 
libHelloJNI.so: HelloJNI.o
	gcc -shared -o libHelloJNI.so HelloJNI.o

HelloJNI.class:	HelloJNI.java
	javac HelloJNI.java
	

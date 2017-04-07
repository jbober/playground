JAVA_HOME=/etc/alternatives/java_sdk_1.8.0/
HelloJNI: HelloJNI.c
	g++ -c -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux -o libhello.so -shared  HelloJNI.c 
